
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

USING_NAMESPACE_CPS

void fillCloverAll(Lattice &lat, double *h_quda_clover, 
		   double *h_quda_clover_inv, ChkbType chkb, 
		   CgArg *cg_arg, CnvFrmType cnv_frm, PreserveType prs_f_in, 
		   DiracOpClover dirac);
void quda_clover_interface(double *h_quda_clover,  double *h_cps_clover);
void inversion_clover(Lattice &lat, double *h_quda_clover, 
		      double *h_quda_clover_inv, Vector *f_in, Vector *f_out);

void reorder_gauge(void *h_gauge, double *gauge_reord);
void set_quda_params(CgArg *cg_arg);

#endif

