#include "../../Include/MODEL.h"

/* This driver runs a number of stochastic realizations
   or replicates of a given stochatic model. 
   After all realizations are done, some averages
   for some model output variables are calculated
   and, if required, represented by using the PGPLOT 
   library
*/

int M_O_D_E_L( Parameter_Table * Table )
{
  int i,j,k, n;
  int I_Time, no_Patch;
  int Bad_Times;
  Community ** PATCH;  
  Parameter_Model * P;  

  I_Time    = Table->T->I_Time;
  no_Patch  = Table->no_Patch;

  PATCH = (Community **)malloc( no_Patch * sizeof(Community *) );
  C_O_M_M_U_N_I_T_Y___A_L_L_O_C_A_T_I_O_N ( Table, PATCH ); 
  C_O_M_M_U_N_I_T_Y___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Table, PATCH);
  
  P = (Parameter_Model *)malloc( 1 * sizeof(Parameter_Model) );
  P_A_R_A_M_E_T_E_R___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Table, P);

  printf("Entering Generation of Stochastic Realizations...\n");
  Press_Key();
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  
  F_I_X_E_D___P_O_I_N_T_S( Table );
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */  

  /* BEGIN: Main loop: a number of REALIZATIONS (stochastic temporal evolutions) is computed */
  for (i=0; i < Table->Realizations; i++){
    /* Input variables: */
    /* 
       . i, lable of current realization 
       . Table, a comprehensive model parameter table (see definition in MODEL.h)
    */
    /* Output variables: */
    /* 
       . Bad_Times is a measure of the performance of the sampling frequency. 
         If Bad_Times is high, interval times should be choosen smaller 
    */
    S_T_O_C_H_A_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S ( i, Table, &Bad_Times ) ;
						       
    /* End of the i-th STOCHASTIC REALIZATIONS */
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
  printf( " Averages and Variances over the ensamble of realizations\n");
  printf( " will be calculated now..."); Press_Key();

  int DATA_POINTS = AVE_VAR_SAVING_SUB_OUTPUT_VARIABLES( Table );
  /*   END : Averaging stochastic realizations */

#if defined CPGPLOT_REPRESENTATION 
  C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R___D_R_I_V_E_R ( DATA_POINTS, Table );
#endif  
  
  printf( " Numerical Integration of the ODE system...\n"); Press_Key(); 

  D_E_T_E_R_M_I_N_I_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S( Table );
  
  C_O_M_M_U_N_I_T_Y___F_R_E_E (PATCH, no_Patch);
  free ( P );

  return(0);
}


  

  
