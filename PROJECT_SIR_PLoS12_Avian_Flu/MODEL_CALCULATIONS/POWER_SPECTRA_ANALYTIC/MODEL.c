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
  double R_0;
  int I_Time;
  Parameter_Model * P;  
  Power_Spectra_Control * PSD = Table->PSD;
  
  I_Time    = Table->T->I_Time;
  
  P = (Parameter_Model *)malloc( 1 * sizeof(Parameter_Model) );
  P_A_R_A_M_E_T_E_R___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Table, P);

  printf("Entering Power Spectra Analytic Calculation...\n");
  
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  /* F_I_X_E_D___P_O_I_N_T_S( Table ); */
  /* Press_Key(); */
  /* double R_0 = R__0( P ); */
  /* printf("\tR_0 = %g\n", R_0); */
  /* Press_Key(); */
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  

  /* BEGIN: Analytic Calculation */
  int n_0 = Table->IO_VARIABLE_LIST[0]%Table->MODEL_VARIABLES;
  int n_1 = Table->IO_VARIABLE_LIST[1]%Table->MODEL_VARIABLES;
  THEORETICAL_POWER_SPECTRA( PSD, P, n_0, n_1 );
  /*   END: Analytic Calculation */
  Saving_to_File_float_float("sd_Theor", PSD->Frequency_Vector, PSD->px, PSD->no_Fr, 0, 0);
  Saving_to_File_float_float("sd_Theor", PSD->Frequency_Vector, PSD->py, PSD->no_Fr, 1, 0);

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
  
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  F_I_X_E_D___P_O_I_N_T_S( Table );
  Press_Key();
  R_0 = R__0( P );
  printf("\tR_0 = %g\n", R_0);
  Press_Key();
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  

  free ( P );

  return(0);
}




  
