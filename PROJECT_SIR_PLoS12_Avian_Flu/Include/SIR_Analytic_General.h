/* These functions are intended to calculates stability-instability borders
   and other borders in the paremeter space. They are defined in 
   func_Instability_Borders_Gen.c
*/
double Delta_2(Parameter_Model *P);
double Delta_4(Parameter_Model *P);
float zbrent_Param(float (*func)(Parameter_Model *P, float, float), Parameter_Model *P, 
		      float x1, float x2, float tol, float NS);
float border_beta_delta(float (*Function)(Parameter_Model *, float, float), Parameter_Model *P, 
			float b0, float b1, float Tolerance, float d);
float Determinant(Parameter_Model *P, float b, float d);
float Discriminant_2(Parameter_Model *P, float b, float d);
float Discriminant_4(Parameter_Model *P, float b, float d);

/* Functions in beta_2_4.c */
float beta_2(float d, float signe);
float beta_4(float d, float signe);

/* These functions are intended to calculate equi-period borders
   and other borders in the paremeter space. They are defined in 
   zbrent_Period.c
*/
float endogen_Period(Parameter_Model *P, float b, float d, float Period, int SI);
float border_Period(float (*Function)(Parameter_Model *, float, float, float, int), 
		    Parameter_Model *P, float b0, float b1, float Pe, int SI,
		    float Tolerance, float d);
float zbrent_Endogen(float (*func)(Parameter_Model *P, float, float, float, int), Parameter_Model *P,
		     float x1, float x2, float Pe, int SI, float tol, float NS);


/* Required function to calculate analytical stochastic 
   overall amplification and coherence stored in overall_Amplification.c */
void overall_Amplification_Coherence(Parameter_Model *P, int SI, double f_semi, double f_peak,
				     float *over, float *cohe);
double overall_Amplification(Parameter_Model *, int);
double coherence_value(Parameter_Model *, int, double, double);
double coherence_semi_analytic(Parameter_Model *, int, double, double);
double coherence_value_Simple(double, double);
float qromb_Accuracy(float (*func)(float), float a, float b, float EPS);
float qtrap_EPS(float (*func)(float), float a, float b, float EPS);

/* Functions to calculate the reactivity in reactivity.c */
float reactivity(Parameter_Model *P);

/* Functions to calculate the resilience in resilience.c */
float resilience(Parameter_Model *P);
float Real_Eigen_Value(Parameter_Model *P);
float Imaginary_Eigen_Value(Parameter_Model *P);

