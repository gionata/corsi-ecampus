#include <iostream>
#include <fstream>

using namespace std;

enum pivot_result {optimal, not_possible};

class tableau {
	int n; // variables
	int m; // constraints
	double **tab;
	int *base;

public:
	tableau(int n, int m);
	tableau(char *file);
	// int set_d(double);
	// int set_c(double *);
	int set_row(int row, double *rr);
	int set_base(int *bb);
	pivot_result pivot(int r, int c);
	void print();
	void simplex();
};

tableau::tableau(int n, int m) {
	this->n = n;
	this->m = m;
	tab = new double *[m + 1];
	for(int i = 0; i < m + 1; i++)
		tab[i] = new double[n + 1];
	base = new int[m];
}

tableau::tableau(char *file) {
	ifstream inf;

	inf.open(file);
	if (inf.fail()) {
		cerr << "unable to open file " << file << "for reading" << endl;
		exit(1);
	}

	inf >> this->m;
	inf >> this->n;
	tab = new double *[m + 1];
	for(int i = 0; i < m + 1; i++)
		tab[i] = new double[n + 1];
	base = new int[m];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			inf >> tab[i][j];
		}
	}
	for (int i = 0; i < m; i++)
		inf >> base[i];
	this->print();
}


int tableau::set_row (int row, double *rr) {
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
}

pivot_result tableau::pivot(int r, int c) {
	int i, j;
	double Arc = tab[r][c];
	for(j = 0; j < n + 1; j++)
		tab[r][j] /= Arc;
	for(i = 0; i < m + 1; i++) {
		if (i == r)
			continue;
		double Aic = tab[i][c];
		for(j = 0; j < n + 1; j++) {
			tab[i][j] -= Aic *tab[r][j];
		}
	}
	base[r - 1] = c;


	return optimal;
}

void tableau::simplex() {
	double c_k, r_h;
	int k, h;

	do {
		k = 0, c_k = 0.0;
		// cerca la colonna k | min c_k, c_k < 0
		for (int jj = 1; jj < n + 1; jj++)
			if (tab[0][jj] < c_k) {
				c_k = tab[0][jj];
				k = jj;
			}

		if (k == 0)
			break; // sol ottima		
		
		// cerca la riga h | min b_h / a_hk, a_hk > 0
		h = 0, r_h = 1e10;
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

	return 0;
}
