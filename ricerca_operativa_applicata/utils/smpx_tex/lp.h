#ifndef LP_H
#define LP_H

enum lp_dir_t
  LP_MIN,
  LP_MAX
};

enum lp_constr_sense_t {
  LP_LEQ,
  LP_GEQ,
  LP_EQ
};

enum lp_aux_t {
  LP_AUX_SLACK,
  LP_AUX_SURPL,
  LP_AUX_ARTIF
};

enum lp_status_t {
  LP_UNDEF,
  LP_PRIMAL_UNFEAS,
  LP_PRIMAL_FEAS,
  LP_PRIMAL_OPT,
  LP_DUAL_UNFEAS,
  LP_DUAL_FEAS,
  LP_DUAL_OPT
};

enum lp_var_sign_t {
  LP_ROW_FREE,
  LP_ROW_LEQ,
  LP_ROW_GEQ,
  LP_ROW_FIXED
};

#endif /* LP_H */