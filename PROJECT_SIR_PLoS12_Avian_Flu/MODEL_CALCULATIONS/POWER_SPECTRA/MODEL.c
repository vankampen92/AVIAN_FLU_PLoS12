#include "../../Include/MODEL.h"

/* This driver runs a number of stochastic realizations
   or replicates of a given stochastic model. 
   Power spectrum densities are calculated and averaged
   over realizations, and, if requested, represented by 
   using the PGPLOT library
*/

int M_O_D_E_L( Parameter_Table * Table )
{
  int i,j,k, n;
  int I_Time, no_Patch;
  int Bad_Times;
  Community ** PATCH;  
  Parameter_Model * P;  
  Power_Spectra_Control * PSD = Table->PSD;
  double SQ_Amplitude_x, SQ_Amplitude_y;
  double Amplitude_x, Amplitude_y;

  I_Time    = Table->T->I_Time;
  no_Patch  = Table->no_Patch;

  PATCH = (Community **)malloc( no_Patch * sizeof(Community *) );
  C_O_M_M_U_N_I_T_Y___A_L_L_O_C_A_T_I_O_N ( Table, PATCH ); 
  C_O_M_M_U_N_I_T_Y___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Table, PATCH);
  
  P = (Parameter_Model *)malloc( 1 * sizeof(Parameter_Model) );
  P_A_R_A_M_E_T_E_R___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Table, P);

  printf("Entering Generation of Stochastic Realizations...\n");
  Press_Key();
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  F_I_X_E_D___P_O_I_N_T_S( Table );
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  

  /* BEGIN: Main loop: a number of REALIZATIONS (stochastic temporal evolutions) is computed */
  SQ_Amplitude_x = 0; SQ_Amplitude_y = 0;
  Amplitude_x = 0.;   Amplitude_y = 0;
  int count_Realizations = 0;
  for (i=0; i < Table->Realizations; i++){
    /* Input variables: 
       . i, lable of the current realization 
       . Table, a comprehensive model parameter table (see definition in MODEL.h)
    *//*   Output variables: 
	   . Bad_Times is a measure of the performance of the sampling frequency. 
	   If Bad_Times is high, interval times should be choosen smaller
	   . FROZEN is 0 if time dynamics calculations resulted in total success.  
    */
    int FROZEN = P_S_D___T_I_M_E___D_Y_N_A_M_I_C_S( i, Table, &Bad_Times ) ;
    /* BEGIN: Calculating Spectra: Times series without missing values */
    if(Bad_Times == 0 && FROZEN == 0){
      
      SQ_Amplitude_x += mean_squared_amplitude(PSD->x, PSD->PSD_TIMES); 
      SQ_Amplitude_y += mean_squared_amplitude(PSD->y, PSD->PSD_TIMES);
	
      Amplitude_x += mean_amplitude(PSD->x, PSD->PSD_TIMES);
      Amplitude_y += mean_amplitude(PSD->y, PSD->PSD_TIMES);
      
      powerSpectrum_K_Sets(PSD->x, PSD->y, PSD->PSD_TIMES, PSD->k_Sets, PSD->mm);         
      accummulating_PowerSpectrum(PSD->x,PSD->y, PSD->px,PSD->py, PSD->no_Fr);  /* (1) */
      count_Realizations++;
    }
    /*   END: Calculating Spectra: Times series without missing values */
    printf("Realization: %d of a total of %d\n", i+1, Table->Realizations);
    printf("Time failed in %d occasions out of %d time steps\n", Bad_Times, I_Time);
    printf("If the number of failed times is too big, EPSILON might be too small!\n");
    printf("Try to choose a larger EPSILON [Current value: -E %g]\n",Table->EPSILON);
  }
  /* END: End of STOCHASTIC REALIZATIONS */

  /* BEGIN : Averaging and saving stochastic realizations */
  /*         One file per each output variable            */  
  printf( " \nAs many as %d stochastic realizations have been successfully completed\n",
          Table->Realizations);
  printf( " Power Spectrum Densities will be calculated over the ensamble of realizations\n");
  printf( " ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ... ..."); Press_Key();

  /* BEGIN: Averaging and saving Power Spectra of Output Variables */
  if ( count_Realizations > 0 ){
    AVE_VAR_SAVING__POWER_SPECTRA( PSD, count_Realizations,
				   SQ_Amplitude_x, SQ_Amplitude_y,
				   Amplitude_x, Amplitude_y );
    /*   END : Averaging and saving power spectra */

#if defined CPGPLOT_REPRESENTATION  
    /* BEGIN: Grafical Representation Power Spectra of i-th Realization */ 
    for( k=0; k < PSD->no_Fr; k++) {
      Table->CPG->x_Time[k]    = PSD->Frequency_Vector[k];
      Table->CPG->y_Time[0][k] = PSD->px[k];
      Table->CPG->y_Time[1][k] = PSD->py[k];
    }
    C_P_G___S_U_B___P_L_O_T_T_I_N_G ( Table, PSD->no_Fr, Table->CPG->x_Time, Table->CPG->y_Time );
  /*   END: Grafical Representation per time step */
#endif 
  }

/* #if defined CPGPLOT_REPRESENTATION                                                         */
/*   C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R___D_R_I_V_E_R ( PSD->no_Fr, Table ); */
/* #endif                                                                                     */
  
  C_O_M_M_U_N_I_T_Y___F_R_E_E (PATCH, no_Patch);
  free ( P );

  return(0);
}




  
