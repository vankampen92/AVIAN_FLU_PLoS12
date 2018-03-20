int jacobian (double t, const double y[], double *dfdy, double dfdt[], void *params);

int function (double t, const double y[], double dydt[], void *params);

double jac_00(Parameter_Model *P, const double *y);
 
double jac_01(Parameter_Model *P, const double *y);

double jac_10(Parameter_Model *P, const double *y);

double jac_11(Parameter_Model *P, const double *y);

double Jacobian_Determinant(Parameter_Model *P, const double *y);

double Jacobian_Trace(Parameter_Model *P, const double *y);

double det(Parameter_Model *P, const double *y);

double tra(Parameter_Model *P, const double *y);

