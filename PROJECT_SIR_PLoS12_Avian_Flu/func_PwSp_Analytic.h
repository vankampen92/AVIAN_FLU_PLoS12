void THEORETICAL_POWER_SPECTRA( Power_Spectra_Control * PSD, Parameter_Model * P, 
				int n_1, int n_2 );

double power_Spectrum(Parameter_Model *P, int I, double w);

double Denominator_FUNCTION( Parameter_Model * P, double w); 

double Psi_FUNCTION( Parameter_Model * P );

double Gamma_FUNCTION( Parameter_Model * P, int I );

double Alpha_FUNCTION(Parameter_Model * P, int I);

double Beta_FUNCTION(Parameter_Model *P, int I);

double V_11( Parameter_Model * P );

double V_12( Parameter_Model * P );

double V_13( Parameter_Model * P );

double V_21( Parameter_Model * P );

double V_22( Parameter_Model * P );

double V_23( Parameter_Model * P );

double V_31( Parameter_Model * P );

double V_32( Parameter_Model * P );

double V_33( Parameter_Model * P );

double Determinant__PwSp(Parameter_Model *P);

double Trace_PwSp(Parameter_Model *P);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the Jacobian matrix A = (A_{ij}): 
   evaluated at stationary point (Fi, Psi, Vir).
   This is the Jacobian governing the evolution of the
   variables (Fi, Psi, Vir) ---the fraction of populations 
   at Susceptible, Infective, and Virus group
 */
double A_11( Parameter_Model * P );

double A_12( Parameter_Model * P );

double A_13( Parameter_Model * P );

double A_21( Parameter_Model * P );

double A_22( Parameter_Model * P );

double A_23( Parameter_Model * P );

double A_31( Parameter_Model * P );

double A_32( Parameter_Model * P );

double A_33( Parameter_Model * P );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the "corrected" Jacobian matrix A = (a_{ij}) 
   used to actually calculate the theoretically predicted
   Power Spectra */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double a_11( Parameter_Model * P );

double a_12( Parameter_Model * P );

double a_13( Parameter_Model * P );

double a_21( Parameter_Model * P );

double a_22( Parameter_Model * P );

double a_23( Parameter_Model * P );

double a_31( Parameter_Model * P );

double a_32( Parameter_Model * P );

double a_33( Parameter_Model * P );
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Entries of the noise covariance matrix B = (B_{ij}): 
   (van Kampen ,1992, chap 10, Large N expansion).
*/
double B_11( Parameter_Model * P );

double B_12( Parameter_Model * P );

double B_13( Parameter_Model * P );

double B_21( Parameter_Model * P );

double B_22( Parameter_Model * P );

double B_23( Parameter_Model * P );

double B_31( Parameter_Model * P );

double B_32( Parameter_Model * P );

double B_33( Parameter_Model * P );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
double Resonance_Frequency(Parameter_Model * P);

double Resonance_Frequency_Peak_Approx(Parameter_Model *P, int I);

double Damping_Frequency(Parameter_Model *P);
  
double Maximum_Power(Parameter_Model *P, int I);

double Resonance_Frequency_Peak(Parameter_Model *P, int I);

int Exact_Condition_Peak(Parameter_Model *P, int I);

double overall_Analytic(Parameter_Model *P, int I);

double coherence_Analytic(Parameter_Model *P, int I, double f_semi, double nu_p);












