#if defined POWER_SPECTRAL_DENSITY
void  AVE_VAR_SAVING__POWER_SPECTRA( Power_Spectra_Control * PSD, 
				     int count_Realizations,
				     double SQ_Amplitude_x, double SQ_Amplitude_y,
				     double Amplitude_x, double Amplitude_y);
#endif

int AVE_VAR_SAVING_SUB_OUTPUT_VARIABLES ( Parameter_Table * Table );

void fprintf_Input_Parameters(FILE *fp, Parameter_Table * P);

void fprintf_Output_Variables(FILE *fp, Parameter_Table * P);

