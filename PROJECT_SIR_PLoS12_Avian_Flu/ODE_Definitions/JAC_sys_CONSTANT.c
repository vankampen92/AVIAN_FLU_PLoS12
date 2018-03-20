#include "../Include/MODEL.h"
/* Note: Make sure all the entries in the Jacobian matrix
         have been properly defined
*/
int 
jacobian (double t, const double y[], double *dfdy, double dfdt[],
	  void *params)
{
  int N;
  void setting_Jacobian_Matrix(gsl_matrix *, const double *, double, int, Parameter_Model * );
  Parameter_Model * P;
  gsl_matrix_view dfdy_mat;
  gsl_matrix * m;

  P = (Parameter_Model *)params;

  N = P->MODEL_VARIABLES;

  dfdy_mat = gsl_matrix_view_array(dfdy, N, N);
  m = &dfdy_mat.matrix;

  /* Setting the Jacobian matrix evaluated at (y[0], ..., y[W])        */

  /* Optimally, this Function should be inline... */
  setting_Jacobian_Matrix(m, y, t, N, P);
  /* End of setting the Jacobian matrix evaluated at (y[0], ..., y[W]) */

  return GSL_SUCCESS;
}

void setting_Jacobian_Matrix(gsl_matrix * m,  const double *y, double t, int N, Parameter_Model *P)
{
  int n,p;
  double a_00, a_11, a_01, a_10;

  /* Labels:                         */ 
  n = 0;   /*************************/     /* Resource (Prey)     */
  p = 1;  /*************************/      /* Consumer (Predator) */

  /* Setting the Jacobian matrix evaluated at (y[0], ..., y[W]) */
  /* First, setting entries to zero... */
  gsl_matrix_set_zero(m); 
 
  a_00 = jac_00(P, y); 
  a_01 = jac_01(P, y);
  a_10 = jac_10(P, y);
  a_11 = jac_11(P, y);

  gsl_matrix_set(m, 0,0, a_00);
  
  gsl_matrix_set(m, 0,1, a_01);

  gsl_matrix_set(m, 1,0, a_10);

  gsl_matrix_set(m, 1,1, a_11);

}
