/* Stable point in the ODE system (Fi, Psi, Vir), Fi being the fraction 
   of the population described by the first equation (usually,
   fraction of susceptibles), Psi the fraction of the population
   described by the second equation (usually, fraction of infective) 
   of our ODE system, and Vir, the fraction of individuals described
   by the third equation.
*/

double R__0( Parameter_Model * P);

double Fi(Parameter_Model *P);

double Psi(Parameter_Model *P);

double Vir(Parameter_Model *P);

void Fixed_Points_General(Parameter_Model *P, double *S, double *I, double *V);

/* End of Fix Point expressions */




