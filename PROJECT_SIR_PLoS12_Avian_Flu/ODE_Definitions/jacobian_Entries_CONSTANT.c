#include "../Include/MODEL.h"

#define BETA_DERIVATIVE_P (Functional_Response_Derivative_Predator(P, y))
#define BETA_DERIVATIVE_N (Functional_Response_Derivative_Prey(P, y))

double jac_00(Parameter_Model *P, const double *y)
{	
  double a;

  //a = 1 - 2.0*y[0] - BETA_DERIVATIVE_N * y[1]; 
  
  return a;
}	
 
double jac_01(Parameter_Model *P, const double *y)
{
  double a;

  //a = - ( BETA_DERIVATIVE_P * y[1] + Functional_Response(P,y) );

  return a;
}

double jac_10(Parameter_Model *P, const double *y)
{
  double a;

  //a = P->Efficiency * BETA_DERIVATIVE_N * y[1];

  return a;
}

double jac_11(Parameter_Model *P, const double *y)
{
  double a;
  
  //a = P->Efficiency * (BETA_DERIVATIVE_P * y[1] + Functional_Response(P,y)) -  P->Consummer_Death_Rate;

  return a;
}

double Jacobian_Determinant(Parameter_Model *P, const double *y)
{  
  double Det;
  
  Det = jac_11(P,y)*jac_00(P,y) - jac_10(P,y)*jac_01(P,y);

  return (Det);
}

double Jacobian_Trace(Parameter_Model *P, const double *y)
{
  double Tra;

  Tra = jac_11(P,y) + jac_00(P,y);

  return (Tra);
}

