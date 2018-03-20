#include "./Include/MODEL.h"

void P_O_W_E_R___S_P_E_C_T_R_A___C_O_N_T_R_O_L___A_L_L_O_C( Power_Spectra_Control * PSD, Parameter_Table * P, 
							    int PSD_TIMES)
{
  /* Old code: 
    x = vector(1,TIMES); y = vector(1,TIMES);
    time = vector(1, TIMES);
    px = vector(0,TIMES); set_to_value_float(px, TIMES, 0.);
    py = vector(0,TIMES); set_to_value_float(py, TIMES, 0.);
    fr = vector(0,TIMES);
   */
  PSD->x = vector(1, PSD_TIMES);
  PSD->y = vector(1, PSD_TIMES);

  /* PSD->px = (float *)calloc( PSD_TIMES+1 , sizeof(float) ); */
  /* PSD->py = (float *)calloc( PSD_TIMES+1 , sizeof(float) ); */
  /* PSD->Frequency_Vector = (float *)calloc( PSD_TIMES+1, sizeof(float) ); */

  PSD->px = vector( 0, PSD_TIMES ); //(float *)calloc( PSD_TIMES+1 , sizeof(float) );
  PSD->py = vector( 0, PSD_TIMES ); //(float *)calloc( PSD_TIMES+1 , sizeof(float) );
  PSD->Frequency_Vector = vector ( 0, PSD_TIMES ); // (float *)calloc( PSD_TIMES+1, sizeof(float) );
  
  set_to_value_float(PSD->px, PSD_TIMES, 0.);  
  set_to_value_float(PSD->py, PSD_TIMES, 0.); 
}

void  P_O_W_E_R___S_P_E_C_T_R_A___C_O_N_T_R_O_L___U_P_L_O_A_D( Power_Spectra_Control * PSD, 
							       Parameter_Table * Table, 
							       int PSD_TIMES )
{
  int i;
  
  PSD->TRANSIENT = Table->TRANSIENT;
  PSD->PSD_TIMES = Table->PSD_TIMES;
  PSD->k_Sets    = Table->k_Sets;
  PSD->STEP_SIZE = Table->STEP_SIZE;

  PSD->mm = PSD->PSD_TIMES/4/PSD->k_Sets;
  if(PSD->k_Sets > 1) PSD->no_Fr = PSD->mm;
  else                PSD->no_Fr = PSD->PSD_TIMES/2;
  printf("Actual number of frequency points: %d\n", PSD->no_Fr);

  /* Setup for the frequency vector         */
  for (i=0; i<=PSD->no_Fr; i++) 
    PSD->Frequency_Vector[i] = (float)i/2./(float)PSD->no_Fr/PSD->STEP_SIZE;// *365.0;

  Table->PSD = PSD;  
}

void P_O_W_E_R___S_P_E_C_T_R_A___T_I_M_E___U_P_L_O_A_D( Time_Control * Time, 
							Power_Spectra_Control * PSD,
							Parameter_Table * Table)
{
  int i;

  Table->T = Time;

  Time->EPSILON = Table->EPSILON;   
  Time->I_Time  = Table->PSD_TIMES + Table->TRANSIENT;
  Time->Time_0  = Table->Time_0;
  Time->Time_1  = Table->Time_1;

  /* Setup for the vector of sampling times */
  for(i=0; i < (PSD->PSD_TIMES + PSD->TRANSIENT); i++){
    Time->Time_Vector[i] = Time->Time_0 + (double)i * PSD->STEP_SIZE;
    Time->count[i]       = 0;
  }
  Time->Time_1 = (Time->I_Time - 1) * PSD->STEP_SIZE;
}

void P_O_W_E_R___S_P_E_C_T_R_A___C_O_N_T_R_O_L___F_R_E_E( Power_Spectra_Control * PSD )
{  
  free_vector(PSD->x, 1,PSD->PSD_TIMES); 
  free_vector(PSD->y, 1,PSD->PSD_TIMES);
 
  free_vector( PSD->Frequency_Vector, 0, PSD->PSD_TIMES ); 
  free_vector( PSD->px, 0, PSD->PSD_TIMES ); 
  free_vector( PSD->py, 0, PSD->PSD_TIMES );
  
  //free( PSD->Frequency_Vector ); free( PSD->px ); free( PSD->py );
}
