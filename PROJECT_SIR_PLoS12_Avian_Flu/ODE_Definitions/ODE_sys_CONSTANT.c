/*
   
  SIR MODEL WITH ENVIRONMENTAL TRANSMISSION (with constant community size)

*/
#include "../Include/MODEL.h"

int 
function (double t, const double y[], double dydt[],
	  void *params)
{

  Parameter_Model * P;

  P = (Parameter_Model *)params;

  /* Rain and Temperature Environmental Forcing Implemented 
     This function updates parameter structure according to
     rainfall and temperature at time t ...
  */
  P->Beta_Effective = P->Beta;
  P->Imm            = P->Rho * y[3] / (double)P->N_V;
#if defined TIME_DEPENDENCE
  /* Beta Effective is changed according to time dependence */
  Time_Dependent_Parameters(P,t);
#endif
    
  double B = P->Beta_Effective/(y[0]+y[1]+y[2]); /* True mass action: Frequency dependene transition rate */
  
  /* Natural births balancing total deaths: zero-sum assumption */
  /* If there is disease-induced mortality, then zero-sum does not work */
  assert(P->Alpha == 0.0);
  assert(P->MODEL_VARIABLES == 4);
  
  dydt[0]  =  P->Delta*(y[0]+y[1]+y[2]) + P->Mu*y[2] + P->Alpha*y[1]- B*y[0]*y[1] - P->Imm *y[0] - P->Delta *y[0]; 
  dydt[1]  = +B * y[0]*y[1] + P->Imm *y[0] - P->Gamma *y[1] - (P->Delta + P->Alpha) *y[1]; 
  dydt[2]  =  P->Gamma *y[1] - P->Delta *y[2] - P->Mu *y[2]; 
  dydt[3]  =  P->Birth_V*y[3] - P->Death_V*y[3] + P->Tau*y[1];

  return GSL_SUCCESS;
}




