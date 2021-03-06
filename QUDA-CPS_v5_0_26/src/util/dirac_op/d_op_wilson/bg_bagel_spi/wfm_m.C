#include "wfm.h"
#include "wfm_internal.h"

/*--------------------------------------------------------------------------*/
/* wilson_m:                                                                */
/*--------------------------------------------------------------------------*/

void wfm::m(Float *chi, 
	    Float *u, 
	    Float *psi, 
	    Float kappa)
{
/*--------------------------------------------------------------------------*/
/* Initializations                                                          */
/*--------------------------------------------------------------------------*/
  int len         =  vol * ND;
  Float  mkappasq = -kappa*kappa;

/*--------------------------------------------------------------------------*/
/* Dslash_E0                                                                */
/*--------------------------------------------------------------------------*/
  dslash(spinor_tmp, u, psi, 1, 0);

/*--------------------------------------------------------------------------*/
/* Dslash_0E                                                                */
/*--------------------------------------------------------------------------*/
  dslash(chi, u, spinor_tmp, 0, 0);

/*--------------------------------------------------------------------------*/
/* 1_OO - kappa^2 * Dslash_0E * Dslash_E0                                   */
/*--------------------------------------------------------------------------*/
  xaxpy(&mkappasq,chi,psi,len);
}


/*--------------------------------------------------------------------------*/
/* wfm::mdag:                                                             */
/*--------------------------------------------------------------------------*/
void wfm::mdag(Float *chi, 
	       Float *u, 
	       Float *psi, 
	       Float kappa)
{

/*--------------------------------------------------------------------------*/
/* Initializations                                                          */
/*--------------------------------------------------------------------------*/
  int        len = vol * ND;
  Float mkappasq = -kappa*kappa;

/*--------------------------------------------------------------------------*/
/* DslashDag_E0                                                             */
/*--------------------------------------------------------------------------*/
//  dslash(chi, u, psi, 1, 1);
  dslash(spinor_tmp, u, psi, 1, 1);

/*--------------------------------------------------------------------------*/
/* DslashDag_0E                                                             */
/*--------------------------------------------------------------------------*/
  dslash(chi, u, spinor_tmp, 0, 1);

/*--------------------------------------------------------------------------*/
/* [1_OO - kappa * DslashDag_0E * DslashDag_E0] ]                           */
/*--------------------------------------------------------------------------*/
  xaxpy(&mkappasq,chi,psi,len);

}

void wfm::mdagm(Float *chi, 
		Float *u, 
		Float *psi, 
		Float *mp_sq_p,
		Float kappa)
{

/*--------------------------------------------------------------------------*/
/* Initializations                                                          */
/*--------------------------------------------------------------------------*/
  int len =  vol *ND;
  Float *tmp1 = spinor_tmp;
  Float *tmp2 = tmp1 + SPINOR_SIZE * vol ;
  Float sum;
  Float mkappasq = -kappa*kappa;

/*--------------------------------------------------------------------------*/
/* Dslash_E0                                                                */
/*--------------------------------------------------------------------------*/
  dslash(tmp1, u, psi, 1, 0);

/*--------------------------------------------------------------------------*/
/* Dslash_0E                                                                */
/*--------------------------------------------------------------------------*/
  dslash(tmp2, u, tmp1, 0, 0);

/*--------------------------------------------------------------------------*/
/* 1_OO - kappa^2 * Dslash_0E * Dslash_E0                                   */
/*--------------------------------------------------------------------------*/
  if(mp_sq_p != 0)
    xaxpy_norm(&mkappasq,tmp2,psi,len,mp_sq_p);
  else 
    xaxpy(&mkappasq,tmp2,psi,len);

/*--------------------------------------------------------------------------*/
/* DslashDag_E0                                                             */
/*--------------------------------------------------------------------------*/
  dslash(tmp1, u, tmp2, 1, 1);

/*--------------------------------------------------------------------------*/
/* DslashDag_0E                                                             */
/*--------------------------------------------------------------------------*/
  dslash(chi, u, tmp1, 0, 1);

/*--------------------------------------------------------------------------*/
/* [1_OO - kappa * DslashDag_0E * DslashDag_E0] *                           */
/*                                 [1_OO - kappa^2 * Dslash_0E * Dslash_E0] */
/*--------------------------------------------------------------------------*/
  xaxpy(&mkappasq,chi,tmp2,len);

}





