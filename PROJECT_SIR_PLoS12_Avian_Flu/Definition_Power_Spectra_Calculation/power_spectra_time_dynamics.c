#include "../Include/MODEL.h"

/* This driver produces the temporal evolution of the 
   i-th stochastic realization. The sampling time
   are defined in Time structure when this data structure
   is setup from scratch at the main program.
*/ 

int  P_S_D___T_I_M_E___D_Y_N_A_M_I_C_S( int i, 
                                        Parameter_Table * Table, 
				        int * Bad_Times )
{
  /* This function perform one stochastic realization (i-th),
     sample the system at times stored in Time->Time_Vector[],
     and save a file corresponding to this i-th stochastic
     realization. 
  */
  int j, k, kk, j_Good;
  int new; /* Accumulate number of infections */
  int TIMES;
  double Time_Initial, Time_Current, Time_Final, value;
   
  Community ** PATCH           = Table->Patch;
  Power_Spectra_Control * PSD  = Table->PSD;

  Time_Control * Time          = Table->T;
  Stochastic_Rate * Rate       = Time->Rate;

  Time_Initial = Table->T->Time_0;
  Time_Final   = Table->T->Time_1;
  TIMES        = Table->T->I_Time;

  /* BEGIN : Initial Conditions */
  P_O_P_U_L_A_T_I_O_N___I_N_I_T_I_A_L_I_Z_A_T_I_O_N ( Table, PATCH );
  Temporal_Dynamics(PATCH, Table->P, Rate);  
  /* Initial values for Output_Variables */
  for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
    kk = Table->IO_VARIABLE_LIST[k]; 
    value = definition_OutPut_Variables(kk, Table);
    Table->Vector_Output_Variables[k] = value;
  }
  /*   END : Initial Conditions */
  
  /* int DISCARTING_EXTINCTIONS = Table->DISCARTING_EXTINCTIONS;   */
  int FROZEN_SYSTEM               = 0;                               
  (*Bad_Times)                    = 0; j_Good = 0;
  Time_Current = Time->Time_Vector[0];

  for( j = 1; j < TIMES; j++ ) {
    /* This loop advances the system sequentially from 
       intitial time 0 to 1st time , ...,  from time (j-1) to j, and so on. 
       Note: When the system is frozen (FROZEN_SYSTEM = 1), then
             this loop does not advance the system any more 
    */
    new = 0;
    while( Time_Current < Time->Time_Vector[j] && FROZEN_SYSTEM == 0 )
      {
	FROZEN_SYSTEM = ADVANCE_CURRENT_TIME( Table, Rate, &Time_Current, &new );
      }
  
    if( Time_Current > Time->Time_Vector[j] + Table->EPSILON){
      (*Bad_Times)++;
#if defined VERBOSE
      printf("Time too far away from target: skipping this time...\n");
      printf("%d\t%g\t%g\n",j, Time_Current, Time->Time_Vector[j]);
#endif
    }
    else{
      /* Notice that Time_Current is always the last time which is the closest possible to
	 (and a little bit larger than) the time stored in Time->Time_Vector[j].           */
      for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
	    kk = Table->IO_VARIABLE_LIST[k]; 
	    value = definition_OutPut_Variables(kk, Table);
	    Time->summ[k][j] += value;
	    Time->summ_var[k][j] += value * value;	
	    Table->Vector_Output_Variables[k] = value;
      }
      Time->count[j]++;
      if(j >= PSD->TRANSIENT){
	/* Counting good times and storing time series for Power Spectra calculation */
          j_Good++; 					
	  PSD->x[j_Good] = Table->Vector_Output_Variables[0];
	  PSD->y[j_Good] = Table->Vector_Output_Variables[1];
      }
#if defined VERBOSE
      Time_Initial = Time->Time_Vector[j-1];
      Time_Final   = Time->Time_Vector[j];
      printf("Current Time: %g\t Time_Initial(%d) = %g\t Time_Final(%d) = %g", 
	     Time_Current, j-1, Time_Initial, j, Time_Final);
      for(k=0; k < Table->MODEL_VARIABLES; k++){
	printf("\t%g", Table->Vector_Model_Variables[k]); 
      }
      printf("\n");
#endif
    }
  }/* go further to the next j-th time */
  return(FROZEN_SYSTEM);
}
