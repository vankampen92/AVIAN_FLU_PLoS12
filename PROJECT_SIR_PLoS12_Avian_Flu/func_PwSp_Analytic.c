#include "./Include/MODEL.h"

void THEORETICAL_POWER_SPECTRA( Power_Spectra_Control * PSD, Parameter_Model * P, 
				int n_1, int n_2 )
{
  int i;
  double w;

  if ( n_1 == 3 ) n_1 = 2;
  if ( n_2 == 3 ) n_2 = 2;

  assert ( n_1 == 0 || n_1 == 1 || n_1 == 2 );
  assert ( n_2 == 0 || n_2 == 1 || n_2 == 2 );

  for(i=0; i <= PSD->no_Fr; i++){
	w = 2.0 * M_PI * PSD->Frequency_Vector[i];
	PSD->px[i] = (float)power_Spectrum( P, n_1, w );
	PSD->py[i] = (float)power_Spectrum( P, n_2, w );
  }
}

double power_Spectrum(Parameter_Model *P, int I, double w)
{
  double p;
  double Dw2;
  double Alpha, Beta, Gamma;

  /* This power spectrum is two-sided. Therefore you need a factor of two 
     Furthermore, when w < 0, the value will be considered to be zero */
  if(w >= 0){
    Dw2 = Denominator_FUNCTION(P,w);

    Alpha = Alpha_FUNCTION(P,I); Beta =  Beta_FUNCTION(P,I); Gamma = Gamma_FUNCTION(P,I);
    
    p = 2.0  * ( Alpha + Beta *w*w*w*w + Gamma *w*w ) / Dw2;

    printf(" I = %d\t Alpha = %g\tBeta = %g\tGamma = %g\n", I, Alpha, Beta, Gamma);
    printf(" N(w, %d) = %g + %g * w^4 + %g * w^2\n", I, Alpha, Beta, Gamma);
  }
  else{
    p = 0.;
  }
  
  return p;
}

double Denominator_FUNCTION( Parameter_Model * P, double w) 
{
  double x, Psi, trA, detA;
 
  Psi  = Psi_FUNCTION( P ); /* $\Psi1$, according to Mapple document */ 
  trA  = Trace_PwSp( P );  
  detA = Determinant__PwSp( P );
  
  x = trA*trA*w*w*w*w -2.0*trA*detA*w*w +detA*detA +w*w*w*w*w*w -2.0*w*w*w*w*Psi +Psi*Psi*w*w; 

  return x;
}

double Psi_FUNCTION( Parameter_Model * P )
{
  double x;

  x = a_11(P)*a_22(P) +a_11(P)*a_33(P) +a_33(P)*a_22(P) -a_23(P)*a_32(P) -a_12(P)*a_21(P);

  return x;
}

double Gamma_FUNCTION( Parameter_Model * P, int I )
{
  double x;
  double a11,a21,a31, a12,a22,a32, a13,a23,a33;
  double B11,B21,B31, B12,B22,B32, B13,B23,B33;
  double V11, V12, V21,V22, V33;

  B11 = Beta_FUNCTION(P, 0);
  B22 = Beta_FUNCTION(P, 1);
  B33 = Beta_FUNCTION(P, 2);
  B12 = B_12(P);
  
  a11 = a_11(P); a12 = a_12(P); a13 = a_13(P);
  a21 = a_21(P); a22 = a_22(P); a23 = a_23(P);
  a31 = a_31(P); a32 = a_32(P); a33 = a_33(P);

  V11 = V_11(P); V12 = V_12(P); V21 = V_21(P); V22 = V_22(P); V33 = V_33(P);
  if(I == 0){
    x = B11*(a22*a22+a33*a33) +B22*a12*a12 +B33*a13*a13 +2.0*(B11*a22*a33 -B12*a12*a22 -B12*a12*a33 +B11*V11 +B12*V12);
  }
  else if(I == 1){
    x = B22*(a11*a11+a33*a33) +B11*a21*a21 +B33*a23*a23 +2.0*(B22*a11*a33 -B12*a11*a21 -B12*a21*a33 +B12*V21 +B22*V22);  
  }
  else if(I == 2){
    x = B33*(a11*a11+a22*a22) +B22*a32*a32 + 2.0*(B33*a11*a22 + B33*V33); 
  }
  else{
    printf("Error in function Alpha_FUNCTION() [func_PwSp_Analytic.c]\n");
    exit(0);
  }

  return (x);
}

double Alpha_FUNCTION(Parameter_Model * P, int I)
{
  /* I = 0, Fist equation; I = 1, Second Equation in your ODE system */
  double x;
  double B12,B11,B22,B33;
  double V11,V12,V13,V21,V22,V23,V31,V32,V33;
  
  B11 = Beta_FUNCTION(P, 0);
  B22 = Beta_FUNCTION(P, 1);
  B33 = Beta_FUNCTION(P, 2);
  B12 = B_12(P);
  
  V11 = V_11(P); V12 = V_12(P); V13 = V_13(P);
  V21 = V_21(P); V22 = V_22(P); V23 = V_23(P);
  V31 = V_31(P); V32 = V_32(P); V33 = V_33(P);
  
  if(I == 0){
    x = B11*V11*V11 + B22*V12*V12 + B33*V13*V13 + 2.0*B12*V11*V12;
  }
  else if(I == 1){
    x = B11*V21*V21 + B22*V22*V22 + B33*V23*V23 + 2.0*B12*V22*V21;
  }
  else if(I == 2){
    x = B11*V31*V31 + B22*V32*V32 + B33*V33*V33 + 2.0*B12*V31*V32;
  }
  else{
    printf("Error in function Alpha_FUNCTION() [func_PwSp_Analytic.c]\n");
    exit(0);
  }

  return (x);
}

double Beta_FUNCTION(Parameter_Model *P, int I)
{
  /* I = 0, Fist equation; I = 1, Second Equation in your ODE system */
  double x;

  if(I == 0){
    x = B_11(P);
  }
  else if(I == 1){
    x = B_22(P);
  }
  else if(I == 2){
    x = B_33(P);
  }
  else{
    printf("Error in function Beta_FUNCTION() [func_PwSp_Analytic.c]\n");
    exit(0);
  }

  return (x);
}

/* Definition of auxiliary functions V_ij, 
   which depend on the entries of the Jacobian 
   matrix A
*/ 
double V_11( Parameter_Model * P )
{
  double x;
  
  x = a_23(P)*a_32(P) - a_33(P)*a_22(P);
  
  return x;
}

double V_12( Parameter_Model * P )
{
  double x;
  
  x = a_12(P)*a_33(P) - a_13(P)*a_32(P);
  
  return x;
}

double V_13( Parameter_Model * P )
{
  double x;
  
  x = a_13(P)*a_22(P) - a_12(P)*a_23(P);
  
  return x;
}

double V_21( Parameter_Model * P )
{
  double x;
  
  x = a_21(P)*a_33(P);
  
  return x;
}

double V_22( Parameter_Model * P )
{
  double x;
  
  x = -a_11(P)*a_33(P);
  
  return x;
}

double V_23( Parameter_Model * P )
{
  double x;
  
  x = a_23(P)*a_11(P) - a_13(P)*a_21(P);
  
  return x;
}

double V_31( Parameter_Model * P )
{
  double x;
  
  x = -a_21(P)*a_32(P);
  
  return x;
}

double V_32( Parameter_Model * P )
{
  double x;
  
  x = a_11(P)*a_32(P);
  
  return x;
}

double V_33( Parameter_Model * P )
{
  double x;
  
  x = a_12(P)*a_21(P) - a_11(P)*a_22(P);
  
  return x;
}

double Determinant__PwSp(Parameter_Model *P)
{ 
  double Determinant;
  
  Determinant = a_11(P)*a_22(P)*a_33(P)  + a_21(P)*a_13(P)*a_32(P) + a_12(P)*a_23(P)*a_31(P) 
              - a_12(P)*a_21(P)*a_33(P) - a_23(P)*a_32(P)*a_11(P) - a_13(P)*a_31(P)*a_22(P);

  return (Determinant);
}

double Trace_PwSp(Parameter_Model *P)
{ 
  double Tr; 

  Tr = a_11(P) + a_22(P) + a_33(P);

  return (Tr);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the Jacobian matrix A = (A_{ij}): 
   evaluated at stationary point (Fi, Psi, Vir).
   This is the Jacobian governing the evolution of the
   variables (Fi, Psi, Vir) ---the fraction of populations 
   at Susceptible, Infective, and Virus group
 */
double A_11( Parameter_Model * P )
{
  double x;

  x = -P->Delta -P->Beta *Psi(P) -P->Rho *Vir(P);

  return(x);
}

double A_12( Parameter_Model * P )
{
  double x;
  
  x = -P->Beta *Fi(P) + P->Alpha;
  
  return(x);
}

double A_13( Parameter_Model * P )
{
  double x;
  
  x = -P->Rho * Fi(P);
  
  return(x);
}

double A_21( Parameter_Model * P )
{
  double x;
  
  x = P->Beta *Psi(P) + P->Rho*Vir(P) ;
  
  return(x);
}

double A_22( Parameter_Model * P )
{
  double x;

  x = P->Beta *Fi(P) - (P->Delta + P->Gamma + P->Alpha); 

  return(x);
}

double A_23( Parameter_Model * P )
{
  double x;
  
  x = P->Rho*Fi(P);
  
  return(x);
}

double A_31( Parameter_Model * P )
{
  double x;
  
  x = 0.0;
  
  return(x);
}

double A_32( Parameter_Model * P )
{
  double x;
  
  x = (double)P->N/(double)P->N_V * P->Tau;
  
  return(x);
}

double A_33( Parameter_Model * P )
{
  double x;

  x = P->Birth_V - P->Death_V;

  return(x);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the "corrected" Jacobian matrix A = (a_{ij}) 
   used to actually calculate the theoretically predicted
   Power Spectra */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double a_11( Parameter_Model * P )
{
  double x;

  x = A_11(P);

  return(x);
}

double a_12( Parameter_Model * P )
{
  double x;
  
  x = A_12(P);
  
  return(x);
}

double a_13( Parameter_Model * P )
{
  double x;
  
  x = sqrt( (double)P->N/(double)P->N_V ) * A_13(P);
  
  return(x);
}

double a_21( Parameter_Model * P )
{
  double x;
  
  x = A_21(P);
  
  return(x);
}

double a_22( Parameter_Model * P )
{
  double x;

  x = A_22(P);

  return(x);
}

double a_23( Parameter_Model * P )
{
  double x;
  
  x = sqrt( (double)P->N/(double)P->N_V ) * A_23(P);
  
  return(x);
}

double a_31( Parameter_Model * P )
{
  double x;
  
  x = A_31(P);
  
  return(x);
}

double a_32( Parameter_Model * P )
{
  double x;
  
  x = sqrt( (double)P->N_V/(double)P->N ) * A_32(P);
  
  return(x);
}

double a_33( Parameter_Model * P )
{
  double x;

  x = A_33(P);

  return(x);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the noise covariance matrix B = (B_{ij}): 
   (van Kampen ,1992, chap 10, Large N expansion).
*/
double B_11( Parameter_Model * P )
{
  double x;

  x = P->Beta *Fi(P)*Psi(P) + P->Rho *Fi(P)*Vir(P) + P->Delta *(1.0-Fi(P));

  return(x);
}

double B_12( Parameter_Model * P )
{
  double x;
  
  x = -P->Beta *Fi(P)*Psi(P) - P->Rho *Fi(P)*Vir(P) - P->Delta *Psi(P);
  
  return(x);
}

double B_13( Parameter_Model * P )
{
  double x;
  
  x = 0.0;
  
  return(x);
}

double B_21( Parameter_Model * P )
{
  double x;
  
  x = B_12(P);
  
  return(x);
}

double B_22( Parameter_Model * P )
{
  double x;

  x = P->Beta *Fi(P)*Psi(P) + P->Rho *Fi(P)*Vir(P) + (P->Delta + P->Gamma)*Psi(P); 

  return(x);
}

double B_23( Parameter_Model * P )
{
  double x;
  
  x = 0.0;
  
  return(x);
}

double B_31( Parameter_Model * P )
{
  double x;
  
  x = 0.0;
  
  return(x);
}

double B_32( Parameter_Model * P )
{
  double x;
  
  x = 0.0;
  
  return(x);
}

double B_33( Parameter_Model * P )
{
  double x;

  x = (P->Birth_V + P->Death_V)*Vir(P) + (double)P->N/(double)P->N_V *P->Tau*Psi(P);

  return(x);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */












