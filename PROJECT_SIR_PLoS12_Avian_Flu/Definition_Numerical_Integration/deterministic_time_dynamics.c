#include "../Include/MODEL.h"

/* This driver produces the temporal evolution of a ODE 
   system. Sampling times are defined in Time structure 
   when this data structure is setup from scratch 
   at the main program.
   PGPLOTing is also possible at running time.
*/ 

void D_E_T_E_R_M_I_N_I_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S( Parameter_Table * Table )
{
  /* This function perform one stochastic realization (i-th),
     sample the system at times stored in Time->Time_Vector[],
     and save a file corresponding to this i-th stochastic
     realization. 
  */
  FILE *FP; char file[50];
  int I, j, k, kk;
  int TIMES;
  Time_Control * Time;
  double Time_Current, value;

  Time         = Table->T;
  TIMES        = Table->T->I_Time;
  
    /* Each stochastic realization will be saved in a different file */
  file[0]='\0';  fitxer(file, "ODE_output", 0, ".dat"); FP = fopen(file, "w");

  /* BEGIN : Initial Conditions */
  P_O_P_U_L_A_T_I_O_N___I_N_I_T_I_A_L_I_Z_A_T_I_O_N___D_E_T_E_R_M_I_N_I_S_T_I_C ( Table );

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
  
  Time_Current = Time->Time_Vector[0];
  
  if( Table->SUB_OUTPUT_VARIABLES > 1 ){
  
      	int DEVICE_NUMBER = cpgopen("/XSERVE");
      	if (DEVICE_NUMBER <= 0 ) {
      	  printf(" Graphic device cannot be opened\n");
      	  exit(1);
      	}
      	cpgsubp(Table->CPG->CPG__PANEL__X, Table->CPG->CPG__PANEL__Y);
      	cpgask(0);
  }
  
  for( j = 1; j < TIMES; j++ ) {
    /* This loop advances the system sequentially from 
       intitial time 0 to 1st time , ...,  from time (j-1) to j, and so on. 
       Note: When the system is frozen (FROZEN_SYSTEM = 1), then
       this loop does not advance the system any more 
    */
    
    int I = numerical_Integration_Driver( Table, j, &Time_Current );
    
#if defined CPGPLOT_REPRESENTATION
    Table->CPG->x_Time[j] = Time_Current;
#endif
    for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
      kk = Table->IO_VARIABLE_LIST[k]; 
      value = definition_OutPut_Variables(kk, Table);
#if defined CPGPLOT_REPRESENTATION      
      Table->CPG->y_Time[k][j] = value;
#endif  
      Table->Vector_Output_Variables[k] = value;
    }

#if defined CPGPLOT_REPRESENTATION    
    /* BEGIN : PHASE DIAGRAM REPRESENTATION */
    if( Table->SUB_OUTPUT_VARIABLES > 1 ){
      //C_P_G___S_U_B___P_L_O_T_T_I_N_G ( Table, j, Table->CPG->x_Time, Table->CPG->y_Time );
      C_P_G___S_U_B___P_L_O_T_T_I_N_G___D_U_A_L ( Table, j, Table->CPG->x_Time, Table->CPG->y_Time ) ;
      //C_P_G___P_H_A_S_E____D_I_A_G_R_A_M ( Table, 0, 1, j, Table->CPG->y_Time);
    }
    else{
      /* The first argument in the following function
        controls whether plot redrawing is required.
        Redrawing is only perform is that argument 
        is greater than 0
     */
      C_P_G___S_U_B___P_L_O_T_T_I_N_G___S_A_M_E___P_L_O_T ( 1, 
							    Table, j, Table->CPG->x_Time, Table->CPG->y_Time );
    }
    /*   END : PHASE DIAGRAM REPRESENTATION */
#endif
    /*   END: Grafical Representation per time step */
    
    /* BEGIN : Writing a costumized file ... */
    fprintf(FP,"%g", Time_Current); 
    for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
      fprintf(FP,"\t%g", Table->Vector_Output_Variables[k]);
    }
    fprintf(FP,"\n");

#if defined VERBOSE
    printf("%g", Time_Current); 
    for(k=0; k < Table->SUB_OUTPUT_VARIABLES; k++){
      printf("\t%g", Table->Vector_Output_Variables[k]); 
    }
    printf("\n");
#endif
    /*   END: Writing costumized file        */
  }/* go further to the next time            */
  fclose(FP);
}
