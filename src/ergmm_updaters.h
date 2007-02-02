#ifndef ERGMM_UPDATERS_H
#define ERGMM_UPDATERS_H 1

#include "ergmm_structs.h"
void ERGMM_MCMC_propose(ERGMM_MCMC_Model *model, ERGMM_MCMC_MCMCState *cur, unsigned int Z, unsigned int RE, unsigned int coef, unsigned int LV, unsigned int REV);
/* The main difference between accepting and rejecting is the direction, so
   they are just macros. (The other main difference is whether lpedge needs
   to be copied.)
 */
#define ERGMM_MCMC_accept(model,cur) ERGMM_MCMC_prop_end(model,cur,cur->prop,cur->state, TRUE)
#define ERGMM_MCMC_reject(model,cur) ERGMM_MCMC_prop_end(model,cur,cur->state,cur->prop, FALSE)
void ERGMM_MCMC_prop_end(ERGMM_MCMC_Model *model, ERGMM_MCMC_MCMCState *cur, ERGMM_MCMC_Par *new, ERGMM_MCMC_Par *old, unsigned int copy_lpedge);
unsigned int ERGMM_MCMC_Z_RE_up(ERGMM_MCMC_Model *model, ERGMM_MCMC_Priors *prior, ERGMM_MCMC_MCMCState *cur,ERGMM_MCMC_MCMCSettings *setting);
unsigned int ERGMM_MCMC_coef_up_scl_tr_Z_shift_RE(ERGMM_MCMC_Model *model,  ERGMM_MCMC_Priors *prior, ERGMM_MCMC_MCMCState *cur,ERGMM_MCMC_MCMCSettings *setting);
void ERGMM_MCMC_CV_up(ERGMM_MCMC_Model *model, ERGMM_MCMC_Priors *prior, ERGMM_MCMC_MCMCState *cur);
void ERGMM_MCMC_LV_up(ERGMM_MCMC_Model *model, ERGMM_MCMC_Priors *prior, ERGMM_MCMC_MCMCState *cur);
void ERGMM_MCMC_REV_up(ERGMM_MCMC_Model *model, ERGMM_MCMC_Priors *prior, ERGMM_MCMC_MCMCState *cur);

/* These are the coefficient matrixes for the correlated update-beta-shift-RE proposal. */
#define ERGMM_MCMC_COEF_RE1_12 (-0.5)
#define ERGMM_MCMC_COEF_RE1_22 (0.8660254037844385)

#define ERGMM_MCMC_COEF_RE2_12 (-0.3333333333333333)
#define ERGMM_MCMC_COEF_RE2_13 (-0.3333333333333333)
#define ERGMM_MCMC_COEF_RE2_22 (0.9428090415820633)
#define ERGMM_MCMC_COEF_RE2_23 (-0.4714045207910316)
#define ERGMM_MCMC_COEF_RE2_33 (0.8164965809277260)

#endif
