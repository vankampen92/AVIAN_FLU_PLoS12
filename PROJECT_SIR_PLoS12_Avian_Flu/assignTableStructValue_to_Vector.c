#include "./Include/MODEL.h"

/* In this file the label for all the parameter of the models
   is defined for the first time and stored in a structure for
   further use in the program
*/

/* Model Dynamics:
   dydx[0]  = -Beta * y[0]*y[1] - Imm*y[0] + (Delta+Mu) *(1. -y[0]-y[1]) + (Delta+Alpha) *y[1]; 
   dydx[1]  = +Beta * y[0]*y[1] + Imm*y[0] - Gamma *y[1] - (Delta+Alpha) *y[1];  
*/
   
double AssignStructValue_to_VectorEntry(int j, Parameter_Table *P)
{
  double value;

    switch(j)
      {
      /* BEGIN: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */      
      case 0:   /* Beta: force of infection parameter */
              value = P->Beta;  
              ; 
	      break;
      case 1:   /* Alpha */
              value = P->Alpha; 
              ; 
	      break;
      case 2:   /* Delta */
	      value = P->Delta;
      	      ; 
	      break;
      case 3:   /* Gamma */
	      value = P->Gamma;
      	      ; 
	      break;
      case 4:   /* Mu    */
              value = P->Mu;
      	      ; 
	      break;
      case 5:   /* Imm_V   */
              value = P->Imm_V; 
      	      ; 
	      break;
      case 6:   /* b_1    */
              value = P->b_1;
      	      ; 
	      break;
      case 7:   /* Per   */
              value = P->Per; 
      	      ; 
	      break;
      case 8:   /* Birth_V    */
              value = P->Birth_V;
      	      ; 
	      break;
      case 9:   /* Death_V   */
              value = P->Death_V; 
      	      ; 
	      break;
      case 10:   /* Rho    */
              value = P->Rho;
      	      ; 
	      break;
      case 11:   /* Tau   */
              value = P->Tau; 
      	      ; 
	      break;
      /*   END: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      case 12:   /* Realizations */
              value = P->Realizations;
	      ;
	      break;
      case 13:   /* Extinctions */
              value = P->DISCARTING_EXTINCTIONS;
	      ;
	      break;
      /*   END: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      /* BEGIN: * * * * * * * TIME CONTROL * * * * * * * * * * * */      
      case 14:
	      value = P->I_Time;
      	      ; 
	      break;
      case 15:
	      value = P->Time_0;
      	      ; 
	      break;
      case 16:
	      value = P->Time_1;
      	      ; 
	      break;
      case 17:
	      value = P->Time_Scale_Unit;
      	      ; 
	      break;
      case 18:
              value = P->TIME_DEPENDENT_PARAM;
      	      ; 
	      break;
      /*   END: * * * * * * * TIME CONTROL * * * * * * * * * * * */       
      /* BEGIN: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      case 19:
              value = P->SUB_MODEL_PARAMETERS;   
      	      ; 
	      break;
      case 20:
	      value = P->A_n;
	      ; 
	      break;
      case 21:
	      value = P->A_d; 
	      ; 
	      break;
      /*   END: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      /* BEGIN: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 22:
	      value = P->SUB_OUTPUT_VARIABLES;
	      ; 
	      break;
      /*   END: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 23:
              value = P->Growth_Function_Type;          
	      ; 
	      break;
      /* BEGIN: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 24:
              value = P->N;          
	      ; 
	      break;
      case 25:
              value = P->POPULATION;          
	      ; 
	      break;
      case 26:
              value = P->no_Patch;          
	      ; 
	      break;
      case 27:
              value = P->N_V;
              ;
              break;
      /*   END: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 28:
              value = P->EPSILON;          
	      ; 
	      break;
      /* BEGIN: * * * * * * INITIAL ONDITIONS  * * * * * * * * * */      	      
      case 29:   /*  Fraction_S_0   */
              value = P->Fraction_S_0; 
      	      ; 
	      break;
      case 30:   /* Fraction_I_0   */
              value = P->Fraction_I_0; 
      	      ; 
	      break;
      case 31:   /* Fraction_V_0   */
              value = P->Fraction_V_0; 
      	      ; 
	      break;
      /*   END: * * * * * * INITIAL CONDITIONS  * * * * * * * * * */   	      
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      
#if defined POWER_SPECTRAL_DENSITY
      case 32:   /* PSD_TIMES  */
              value = P->PSD_TIMES; 
      	      ; 
	      break;
      case 33:   /* TRANSIENT */
              value = P->TRANSIENT; 
      	      ; 
	      break;
      case 34:   /* k_Sets   */
              value = P->k_Sets; 
      	      ; 
	      break;
      case 35:   /* STEP_SIZE  */
              value = P->STEP_SIZE; 
      	      ; 
	      break;
#endif
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
      default:
      printf(".... assignTableStructureValue_to_Vector.c: INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Input_Parameters(stdout, P);	      
      exit(0);
      }
    
    return(value);
}
