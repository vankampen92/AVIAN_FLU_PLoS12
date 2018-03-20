#include "./Include/MODEL.h"

/* Stable point in the ODE system (Fi, Psi, Vir), Fi being the fraction 
   of the population described by the first equation (usually,
   fraction of susceptibles), Psi the fraction of the population
   described by the second equation (usually, fraction of infective) 
   of our ODE system, and Vir, the fraction of individuals described
   by the third equation.
*/

double R__0( Parameter_Model * P)
{
  double   x;
  
  x = P->Beta/(P->Delta+P->Gamma) + (double)P->N/(double)P->N_V *P->Rho*P->Tau/( (P->Death_V-P->Birth_V) * (P->Delta+P->Gamma) );

  return (x);
}

double Fi(Parameter_Model *P)
{
  /* Stable Point for Fraction of Susceptibles */
  double S;

  S = 1.0/R__0(P);

  return(S);
}

double Psi(Parameter_Model *P)
{
  /* Stable point for Infective */
  double I;

  I = P->Delta/(P->Delta + P->Gamma) * (1.-Fi(P));

  return (I);
}

double Vir(Parameter_Model *P)
{
  double V;

  V = (double)P->N/(double)P->N_V * P->Delta*P->Tau/(P->Death_V-P->Birth_V)/(P->Delta+P->Gamma) * (1.-Fi(P));
  
  return(V);
}

void Fixed_Points_General(Parameter_Model *P, double *S, double *I, double *V)
{
  (*S) = Fi(P);
  (*I) = Psi(P);
  (*V) = Vir(P);
  printf("Populations fractions at Equilibrium (Imm = %g)...\n", P->Imm_V);
  printf("Susceptible: %g\n", *S);
  printf("Infective:   %g\n", *I);
  printf("Virus:       %g\n", *V);
}
/* End of Fix Point expressions */




