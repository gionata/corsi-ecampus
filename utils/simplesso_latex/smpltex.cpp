#include <iostream>
#include <boost/rational.hpp>

typedef boost::rational<int> number;

using namespace std;

enum con_type {LP_ROW_FREE = 0, LP_ROW_LEQ, LP_ROW_GEQ, LP_ROW_FIXED};
enum aux_type {LP_AUX_SLACK, LP_AUX_SURPL, LP_AUX_ARTIF};
enum pro_dir  {LP_MIN, LP_MAX};
enum row_stat {lp_aux_basic = 0, lp_aux_nbv };
enum row_dual {lp_dlv_fixed = 0, lp_dlv_geq, lp_dlv_leq, lp_dlv_free };

/*! LP row (auxiliary variable) */
class lp_row {
public:
      /*! ordinal number (1 to m) assigned to this row */
      int i;
      /*! row name (1 to 255 chars); NULL means no name is assigned to
         this row */
      char *name;
      con_type constraint_type;
      /*! type of the auxiliary variable */
      aux_type auxiliary_type;
      /*! pointer to the list of constraint coefficients which
         are placed in this row */
      numeric *row_ptr;
      /*! if the auxiliary variable is basic, head[bind] refers to this
         row, otherwise, bind is 0; this attribute is valid only if the
         basis factorization is valid */
};

/*! LP column (structural variable) */
class GLPCOL
{
      /*! ordinal number (1 to n) assigned to this column */
      int j;
      /*! column name (1 to 255 chars); NULL means no name is assigned
         to this column */
      char *name;
      /*! kind of the structural variable:
         GLP_CV - continuous variable
         GLP_IV - integer or binary variable */
      int kind;
      /*! type of the structural variable:
         GLP_FR - free variable
         GLP_LO - variable with lower bound
         GLP_UP - variable with upper bound
         GLP_DB - double-bounded variable
         GLP_FX - fixed variable */
      int type;
      /*! lower bound; if the column has no lower bound, lb is zero */
      double lb; /* non-scaled */
      /*! upper bound; if the column has no upper bound, ub is zero */
      /*! if the column type is GLP_FX, ub is equal to lb */
      double ub; /* non-scaled */
      /*! objective coefficient at the structural variable */
      double coef; /* non-scaled */
      /*! pointer to doubly linked list of constraint coefficients which
         are placed in this column */
      numeric *ptr; /* non-scaled */
      /*! status of the structural variable:
         GLP_BS - basic variable
         GLP_NL - non-basic variable on lower bound
         GLP_NU - non-basic variable on upper bound
         GLP_NF - non-basic free variable
         GLP_NS - non-basic fixed variable */
      int stat;
      /*! if the structural variable is basic, head[bind] refers to
         this column; otherwise, bind is 0; this attribute is valid only
         if the basis factorization is valid */
      int bind;
      /*! primal value of the structural variable in basic solution */
      double prim; /* non-scaled */
      /*! dual value of the structural variable in basic solution */
      double dual; /* non-scaled */
      /*! primal value of the structural variable in interior solution */
      double pval; /* non-scaled */
      /*! dual value of the structural variable in interior solution */
      double dval; /* non-scaled */
};

class lp_prob {
  
public:
  void set_obj_coef(int j, numeric val);
  void set_obj_dir(pro_dir dir);
  void set_obj_name(char *name);
  
  void set_mat_row();
  void set_row_name();
  
private:
      /*! problem name (1 to 255 chars); NULL means no name is assigned
         to the problem */
      char *name;
      /*! objective function name (1 to 255 chars); NULL means no name
         is assigned to the objective function */
      char *obj;
      /*! optimization direction flag (objective "sense"):
         GLP_MIN - minimization
         GLP_MAX - maximization */
      pro_dir dir;
      /*! constant term of the objective function ("shift") */
      numeric c0;
      /*! number of rows, 0 <= m <= m_max */
      int m;
      /*! number of columns, 0 <= n <= n_max */
      int n;

      GLPROW **row; /*! GLPROW *row[1+m_max]; */
      /*! row[i], 1 <= i <= m, is a pointer to i-th row */
      GLPCOL **col; /*! GLPCOL *col[1+n_max]; */
      /*! col[j], 1 <= j <= n, is a pointer to j-th column */
      /*! constraint coefficient a[i,j] */
      numeric **tableau;

      /*--------------------------------------------------------------*/
      /*! basis factorization (LP) */
      /*! the factorization is valid only if this flag is set */
      int valid;
      /*! basis header (valid only if the factorization is valid);
         head[i] = k is the ordinal number of auxiliary (1 <= k <= m)
         or structural (m+1 <= k <= m+n) variable which corresponds to
         i-th basic variable xB[i], 1 <= i <= m */
      int *basis; /*! int head[1+m_max]; */
      /*--------------------------------------------------------------*/
      /*! basic solution (LP) */
      /*! primal basic solution status:
         GLP_UNDEF  - primal solution is undefined
         GLP_FEAS   - primal solution is feasible
         GLP_INFEAS - primal solution is infeasible
         GLP_NOFEAS - no primal feasible solution exists */
      int pbs_stat;
      /*! dual basic solution status:
         GLP_UNDEF  - dual solution is undefined
         GLP_FEAS   - dual solution is feasible
         GLP_INFEAS - dual solution is infeasible
         GLP_NOFEAS - no dual feasible solution exists */
      int dbs_stat;
      /*! objective function value */
      double obj_val;
      /*! simplex method iteration count; increased by one on performing
         one simplex iteration */
      int it_cnt;
};

class tableau {
public:
  tableau(int m, int n);
  
};

int main(int argc, char *argv[])
{
  if (argc < 2) {
    cout << "Errore: <" << argv[0] << "file" << endl;
    return(0);
  }
  
  number a1(1,3), a2(2,3);
  
  cout << a1 << endl;
  cout << a2 << endl;
  cout << a1 + a2 << endl;
  cout << a1 - a2 << endl;
  cout << a1 * a2 << endl;
  cout << a1 - a2 << endl;
  cout << a1.denominator() << endl();
  
  return 0;
}