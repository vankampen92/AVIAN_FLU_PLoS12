#include "./Include/MODEL.h"

void  AVE_VAR_SAVING__POWER_SPECTRA( Power_Spectra_Control * PSD, 
				     int count_Realizations,
				     double SQ_Amplitude_x, double SQ_Amplitude_y,
				     double Amplitude_x, double Amplitude_y)
{
  double Factor;
  double Overall_Power;
  double Mean_SQ_Amplitude_x, Mean_SQ_Amplitude_y;
  double Mean_Amplitude_x, Mean_Amplitude_y;
  int i;
  
  printf(" Power Spectra calculated and averaged over %d stochastic realizations\n", count_Realizations);

    if(PSD->k_Sets == 1)
      Factor = 4.*(float)PSD->no_Fr*(float)PSD->no_Fr*(float)count_Realizations;
    else
      Factor = (float)count_Realizations;
    
    averaged_PowerSpectrum(Factor, PSD->px, PSD->py, PSD->no_Fr, count_Realizations, 0); 
    /* Here, if last argument is 0, a non-normalized power spectra is calculated *//* (1) */
    
    Mean_SQ_Amplitude_x = SQ_Amplitude_x/(double)count_Realizations;
    Mean_SQ_Amplitude_y = SQ_Amplitude_y/(double)count_Realizations; 
    Mean_Amplitude_x    = Amplitude_x/(double)count_Realizations;
    Mean_Amplitude_y    = Amplitude_y/(double)count_Realizations;
  
    /* Saving non-standarized power spectra (total power per frequency bin) */
    Saving_to_File_float_float("pwsp", PSD->Frequency_Vector, PSD->px, PSD->no_Fr, 0, 0);
    Saving_to_File_float_float("pwsp", PSD->Frequency_Vector, PSD->py, PSD->no_Fr, 1, 0);
    
    Overall_Power = total_Power(PSD->px, PSD->no_Fr);
    printf("Overall_Power = %g\tMean Squared Amplitude = %g\n", Overall_Power, Mean_SQ_Amplitude_x);
    printf("Px(0) = %g\t(Mean_Amplitude_x)^2 = %g\n", PSD->px[0], Mean_Amplitude_x*Mean_Amplitude_x);
    
    Overall_Power = total_Power(PSD->py, PSD->no_Fr);
    printf("Overall_Power = %g\tMean Squared Amplitude = %g\n", Overall_Power, Mean_SQ_Amplitude_y);
    printf("Py(0) = %g\t(Mean_Amplitude_y)^2 = %g\n", PSD->py[0], Mean_Amplitude_y*Mean_Amplitude_y);
    
    /* Calculating and saving Spectral densities (Density Power per unit frequency) 
       in a way that the sum over the frequency grid produces the Mean Squared Amplitude */
    estimated_Spectral_Density(PSD->px, PSD->Frequency_Vector, PSD->no_Fr);
    Saving_to_File_float_float("spden", PSD->Frequency_Vector, PSD->px, PSD->no_Fr, 0, 0);
  
    estimated_Spectral_Density(PSD->py, PSD->Frequency_Vector, PSD->no_Fr);
    Saving_to_File_float_float("spden", PSD->Frequency_Vector, PSD->py, PSD->no_Fr, 1, 0);
  
}
