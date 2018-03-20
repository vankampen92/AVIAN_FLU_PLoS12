#include "../Include/MODEL.h"

/* This driver produces the temporal evolution of the 
   i-th stochastic realization. The sampling time
   are defined in Time structure when this data structure
   is setup from scratch at the main program.
   PGPLOTing is also possible at running time.
*/ 

void S_T_O_C_H_A_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S( int i, 
						      Parameter_Table * Table, 
						      int * Bad_Times )
{
  /* This function perform one stochastic realization (i-th),
     sample the system at times stored in Time->Time_Vector[],
     and save a file corresponding to this i-th stochastic
     realization. 
  */
  FILE *FP; char file[12];
  int j, k, kk, j_Good;
  int new; /* Accumulate number of infections */
  int TIMES;
  Time_Control * Time;
  Community ** PATCH;
  double Time_Initial, Time_Current, Time_Final, value;
  Stochastic_Rate * Rate;
 
  Time         = Table->T;
  Time_Initial = Table->T->Time_0;
  Time_Final   = Table->T->Time_1;
  TIMES        = Table->T->I_Time;
  
  PATCH        = Table->Patch;
 
  Rate         = Time->Rate;   
  /* Each stochastic realization will be saved in a different file */
  file[0]='\0';  fitxer(file, "re_", i, ".dat"); FP = fopen(file, "w");

  /* BEGIN : Initial Conditions */
  P_O_P_U_L_A_T_I_O_N___I_N_I_T_I_A_L_I_Z_A_T_I_O_N ( Table, PATCH );
  Temporal_Dynamics(PATCH, Table->P, Rate);  

#if defined CPGPLOT_REPRESENTATION
  Table->CPG->x_Time[0]      = Time->Time_Vector[0];
#endif
  for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
    kk = Table->IO_VARIABLE_LIST[k]; 
    value = definition_OutPut_Variables(kk, Table);
#if defined CPGPLOT_REPRESENTATION
    Table->CPG->y_Time[k][0] = value;
#endif
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
      /* Saving and representing at values close to Time_values[j] * * * * * * * * * * * * */
      /* Notice that Time_Current is always the last time which is the closest possible to
	 (and a little bit larger than) the time stored in Time->Time_Vector[j].           */
      j_Good++; /* Counting good times */
      for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
	kk = Table->IO_VARIABLE_LIST[k]; 
	value = definition_OutPut_Variables(kk, Table);
	Time->summ[k][j] += value;
	Time->summ_var[k][j] += value * value;	
	Table->Vector_Output_Variables[k] = value;
#if defined CPGPLOT_REPRESENTATION
	Table->CPG->y_Time[k][j_Good] = value;
#endif
      }
#if defined CPGPLOT_REPRESENTATION
      if( FROZEN_SYSTEM == 0 ){ Table->CPG->x_Time[j_Good]    = Time_Current; }
      else {            Table->CPG->x_Time[j_Good]    = Time->Time_Vector[j]; }
#endif
      Time->count[j]++;
      Time->Accumulated_Variable[i][j] = (double)new;
      
      Time_Initial = Time->Time_Vector[j-1];
      Time_Final   = Time->Time_Vector[j];
      
#if defined CPGPLOT_REPRESENTATION    /* Plotting Time evolution */
      /* BEGIN: Grafical Representation per SUCCESSFUL time step */  
      if( Table->SUB_OUTPUT_VARIABLES == 1 ){
	C_P_G___S_U_B___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( i,
							      Table, j_Good,       
							      Table->CPG->x_Time,   
							      Table->CPG->y_Time );
      }
      else {
	//C_P_G___S_U_B___P_L_O_T_T_I_N_G ( Table, j_Good, Table->CPG->x_Time,  Table->CPG->y_Time );
	C_P_G___S_U_B___P_L_O_T_T_I_N_G___D_U_A_L ( Table, 
						    j_Good, Table->CPG->x_Time,  Table->CPG->y_Time );
      }
      /*   END: Grafical Representation per time step */
#endif
      
      /* BEGIN : Writing a costumized file ... */
      fprintf(FP,"%g", Time_Current); 
      for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
	fprintf(FP,"\t%g", Table->Vector_Output_Variables[k]);
      }
      fprintf(FP,"\n");

#if defined VERBOSE
      printf("Current Time: %g\t Time(%d) = %g\t Time(%d) = %g", 
	     Time_Current, j-1, Time_Initial, j, Time_Final);
      for(k=0; k < Table->MODEL_VARIABLES; k++){
	printf("\t%g", Table->Vector_Model_Variables[k]); 
      }
      printf("\n");
#endif
      /*   END: Writing costumized file        */
    }
  }/* go further to the next time           */
  
  fclose(FP);
}
