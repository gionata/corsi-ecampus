#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/rational.hpp>

typedef boost::rational<int> number;

using namespace std;

enum pivot_result {optimal, initialized, unbounded, unfeasible};

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

string number2ltx(number n)
{
    string number2ltx;
    stringstream ret;
    if (n.denominator() == 1)
        ret << n.numerator();
    else {
        if (n.numerator() > 0)
            ret << "\\frac {" << n.numerator() << "} {" << n.denominator() << "}";
        else
            ret << "-\\frac {" << -n.numerator() << "} {" << n.denominator() << "}";
    }
    return ret.str();
}

class tableau {
    int n; // variables
    int m; // constraints
    number **tab;
    int *base;
    pivot_result status;
    ofstream ltx;

public:
    tableau(int n, int m);
    tableau(char *file);
    ~tableau();
    // int set_d(double);
    // int set_c(double *);
    int set_row(int row, number *rr);
    int set_base(int *bb);
    pivot_result pivot(int r, int c);
    void print();
    void print_canonical_form();
    void simplex();
};

tableau::tableau(int n, int m) {
    this->n = n;
    this->m = m;
    tab = new number *[m + 1];
    for(int i = 0; i < m + 1; i++)
        tab[i] = new number[n + 1];
    base = new int[m];
}

tableau::tableau(char *file) {
    ifstream inf;
    string ltx_file(string(file)+string(".tex"));
    ltx.open(ltx_file.c_str(), ios::trunc);
    if(ltx.fail()) {
        cerr << "unable to open file " << ltx_file << "for writing" << endl;
        exit(1);
    }

    inf.open(file);
    if (inf.fail()) {
        cerr << "unable to open file " << file << "for reading" << endl;
        exit(1);
    }

    inf >> this->m; //cout << "m <- " << this->m << endl;
    inf >> this->n; //cout << "n <- " << this->n << endl;
    tab = new number *[m + 1];
    for(int i = 0; i < m + 1; i++)
        tab[i] = new number[n + 1];
    base = new int[m];
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            double d;
            //inf >> tab[i][j];  cout << "T[" << i << ", " << j << "] <- " << tab[i][j] << endl;
            inf >> d;  //cout << "T[" << i << ", " << j << "] <- " << d << endl;
            tab[i][j] = d;  //cout << "T[" << i << ", " << j << "] <- " << tab[i][j] << endl;
        }
    }
    for (int i = 0; i < m; i++)
        inf >> base[i];

    this->status = initialized;

    this->print_canonical_form();
    this->print();
}

tableau::~tableau()
{
    ltx.close();
}


int tableau::set_row (int row, number *rr) {
    for (int j = 0; j < n + 1; j++)
        tab[row][j] = rr[j];

    return 0;
}

int tableau::set_base(int *bb) {
    for(int i = 0; i < m; i++)
        base[i] = bb[i];

    return 0;
}

void tableau::print() {
    string beginFrame (
        "\\begin{frame}[fragile]{TITOLO}\n"
        "\\centering\n"
        "\\begin{tikzpicture}\n"
        "{\\tiny\n"
        "\\node[%\n"
        "  align=center,\n"
        "  text width=3.5em,\n"
        "  text height=5ex,\n"
        "  row 1/.style={gray, text height=1em},\n"
        "  row 2/.style={blue!50!gray, text height=1em},\n"
        "  row 3/.style={blue},\n"
        "  column 1/.style={gray,text width=1em},\n"
        "  column 2/.style={red!50!gray,text width=1.5em},\n"
        "  column 3/.style={red},\n"
        "  column RATIO/.style={gray},\n"
        "  row 3 column 1/.style={gray},\n"
        "  row 3 column 2/.style={red!50!gray},\n"
        "  row 3 column 3/.style={red},\n"
        "  matrix of math nodes] (M)\n"
        "{%\n"
        "% Indice delle righe (M-1)\n");

    string endFrame (
        "}\n"
        "\\end{tikzpicture}\n"
        "%sono fragile: lasciami uno spazio vuoto\n"
        "\n"
        "\\end{frame}\n\n");

    static int tableau_id = 0;
    int i, j;
    cout << "Base:";
    for (j = 0; j < m; j++)
        cout << " " << base[j];

    cout << endl << "Tableau " << tableau_id++ << ":" << endl;
    for (i=0; i < m + 1; i++) {
        for (j = 0; j < n; j++) {
            cout.width(9);
            cout << right << tab[i][j] << " ";
        }
        cout.width(9);
        cout << right << tab[i][n] << endl;
    }
    cout << endl;

    // controlla se ottima o illimitata
    bool ottima = false;
    bool illimitata = false;
    number c_k, r_h;
    int k, h;

    do {
        k = 0, c_k = 0;
        // cerca la colonna k | min c_k, c_k < 0
        for (int jj = 1; jj < n + 1; jj++)
            if (tab[0][jj] < c_k) {
                c_k = tab[0][jj];
                k = jj;
            }

        if (k == 0) {
            ottima = true;
            break; // sol ottima
        }

        // cerca la riga h | min b_h / a_hk, a_hk > 0
        h = 0, r_h = 1e6;
        for (int ii = 1; ii < m + 1; ii++)
            if (tab[ii][k] > 0 &&
                    tab[ii][0]/tab[ii][k] < r_h)  {
                r_h = tab[ii][0]/tab[ii][k];
                h = ii;
            }
        if (h == 0) {
            illimitata = true;
            break; // sol illimitata
        }

        break;

    } while(k && h);

    stringstream titolo, ratio;
    titolo << "Iterazione " << tableau_id << ": soluzione " ;
    if (ottima) {
        titolo << "ottima";
    } else if (illimitata) {
        titolo << "illimitata";
    } else {
        titolo << "migliorabile";
    }

    string myBeginFrame(beginFrame);
    replace(myBeginFrame, "TITOLO", titolo.str());
    ratio << this->n+4;
    replace(myBeginFrame, "RATIO", ratio.str());

    ltx << myBeginFrame;
    ltx << "~&~&0";
    for (j = 1; j <= this->n; j++)
        ltx << "&" << j;
    ltx << "\\\\\n";
    ltx << "% Intestazione delle colonne (M-2)\n~ &~&\\mbox {rhs}";
    for (j = 1; j <= this->n; j++)
        ltx << "&x_ {" << j << "}";
    if (h && k)
        ltx << "&Rapp.";
    ltx << "\\\\\n";
    for (i = 0; i <= this-> m; i++) {
        ltx << "% Riga " << i << "\n";
        ltx << i << "&";
        if (i == 0)
            ltx << "z";
        else
            ltx << "x_ {" << base[i-1] << "}";
        for (j = 0; j <= this->n; j++) {
            ltx << "&" << number2ltx(this->tab[i][j]);
        }
        // aggiungi il rapporto
        if (k && h && i > 0) {
	    if (tab[i][k] > 0) {
	      number ratio_b_a = tab[i][0]/tab[i][k];
	      ltx << "&" << number2ltx(ratio_b_a);
	    } else
	      ltx << "&";
        }

        ltx << "\\\\\n";
    }
    ltx << "}; %end of matrix node\n";
// bordi continui
    ltx << "% riquadro\n"
        "\\draw(M-3-3.north west) -- (M-3-" << this->n+3 << ".north east) "
        "-- (M-" << this->m+3 << "-" << this->n+3 << ".south east) "
        "-- (M-" << this->m+3 << "-3.south west) -- cycle;\n";
    ltx << "% separatore orizzontale\n"
        "\\draw[dashed] (M-4-3.north west) -- (M-4-" << this->n+3 << ".north east);\n";
    ltx << "% separatore verticale\n"
        "\\draw[dashed] (M-3-4.north west) -- (M-" << this->m+3 << "-4.south west);\n";

    if (k) {
        ltx<< "% entra x_k\n"
           "\\draw[->,thick,red!50!blue] (M-1-"<< k+3 << ".north) to (M-2-" << k+3 << ".north);\n"
           "% esce x_{s_h}\n"
           "\\draw[->,thick,red!50!blue] (M-2-" << base[h-1] + 3 << ".north) to (M-1-" << base[h-1] + 3 << ".north);\n";
    }

    if (k && h) {
        ltx << "% il pivot\n"
            "\\fill[yellow!50,fill opacity=0.25,thick,draw=blue!60!black] "
            "(M-" << h+3 << "-" << k+3 << ".base) circle (1.5 em);\n";
    }

    ltx << endFrame;
}

void tableau::print_canonical_form() {
    string beginFrame (
        "\\begin{frame}{TITOLO}\n"
        "{\\small\n");

    string endFrame (
        "}\n\n"
        "\\end{frame}\n\n");
    stringstream titolo;
    titolo << "PL in forma canonica";
    string myBeginFrame(beginFrame);
    replace(myBeginFrame, "TITOLO", titolo.str());
    ltx << myBeginFrame;
    ltx << "$$\n\\begin{array}{cc";
    for (int j = 1; j <= n; j++)
        ltx << "cr";
    ltx << "cc}\n";
    for (int i = 0; i <= this->m; i++) {
        // riga i
        switch(i) {
        case 0:
            ltx << "\t\\min z\t&=";
            break;
        case 1:
            ltx << "\t\\mbox{s.t.}\t&";
            break;
        default:
            ltx << "\t&";
        }
        bool first_term_written = false;
        for (int j = 1; j <= this->n; j++) {
            ltx << "\t&";
            if (this->tab[i][j].numerator() != 0) {
                if (first_term_written)
                    if(this->tab[i][j].numerator() > 0)
                        ltx << "+&";
                    else
                        ltx << "-&";
                else {
                    if (this->tab[i][j] < 0)
                        ltx << "-&";
                    else
                        ltx << " &";
                }

                if (this->tab[i][j] != 1)
                    ltx << number2ltx(abs(this->tab[i][j]));
                ltx << " x_{" << j << "}";
                first_term_written = true;
            } else {
                ltx << "\t&";
            }
        }
        if (i == 0) {
            if (this->tab[i][0] != 0)
                if (this->tab[i][0] > 0)
                    ltx << "\t&+\t&";
                else
                    ltx << "\t&+\t&";
            if (this->tab[i][0] != 0)
                ltx << number2ltx(abs(this->tab[i][0]));
        } else
            ltx << "\t&=\t&" << number2ltx(this->tab[i][0]);
	 ltx << "\\\\\n";
    }
    ltx << "\t&\t&\\multicolumn{" << 2*this->n << "}{c}{x_{1} \\geq 0";
    for (int j = 2; j <= this->n; j++)
        ltx << ",\\ x_{" << j << "} \\geq 0";
    ltx << "}\n\\end{array}\n$$\n";
    ltx << endFrame;
}

pivot_result tableau::pivot(int r, int c) {
    int i, j;
    number Arc = tab[r][c];
    for(j = 0; j < n + 1; j++)
        tab[r][j] /= Arc;
    for(i = 0; i < m + 1; i++) {
        if (i == r)
            continue;
        number Aic = tab[i][c];
        for(j = 0; j < n + 1; j++) {
            tab[i][j] -= Aic *tab[r][j];
        }
    }
    base[r - 1] = c;

    status = optimal;
    return optimal;
}

void tableau::simplex() {
    number c_k, r_h;
    int k, h;

    do {
        k = 0, c_k = 0;
// cerca la colonna k | min c_k, c_k < 0
        for (int jj = 1; jj < n + 1; jj++)
            if (tab[0][jj] < c_k) {
                c_k = tab[0][jj];
                k = jj;
            }

        if (k == 0)
            break; // sol ottima

// cerca la riga h | min b_h / a_hk, a_hk > 0
        h = 0, r_h = 1e6;
        for (int ii = 1; ii < m + 1; ii++)
            if (tab[ii][k] > 0 &&
                    tab[ii][0]/tab[ii][k] < r_h)  {
                r_h = tab[ii][0]/tab[ii][k];
                h = ii;
            }
        if (h == 0)
            break; // sol illimitata

//		cout << endl << "Pivot in (" << h << ", " << k << ")";
//		cout << " => x_" << k << " sostituisce x_" << base[h - 1] <<" in B" << endl;
        pivot(h, k);
        print();

    } while(k && h);

}


int main (int argc, char* argv[]) {

    if (argc < 2)
        return 0;

    tableau *t = new tableau(argv[1]);
    t->simplex();
    delete t;

    return 0;
}
