#include "./Include/MODEL.h"

/* In this file the label for all the parameter of the models
   is defined for the first time and stored in a structure for
   further use in the program
*/

/* Model Dynamics:
   dydx[0]  = -Beta * y[0]*y[1] - Imm*y[0] + (Delta+Mu) *(1. -y[0]-y[1]) + (Delta+Alpha) *y[1]; 
   dydx[1]  = +Beta * y[0]*y[1] + Imm*y[0] - Gamma *y[1] - (Delta+Alpha) *y[1];  
*/
   
void AssignVectorEntry_to_Structure(Parameter_Table *P, int j, double value)
{

    switch(j)
      {
      /* BEGIN: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */      
      case 0:   /* Beta: */
              P->Beta = value;  
              ; 
	      break;
      case 1:   /* Alpha */
              P->Alpha = value; 
              ; 
	      break;
      case 2:   /* Delta */
	      P->Delta = value;
      	      ; 
	      break;
      case 3:   /* Gamma */
	      P->Gamma = value;
      	      ; 
	      break;
      case 4:   /* Mu    */
              P->Mu = value;
      	      ; 
	      break;
      case 5:   /* Imm_V   */
              P->Imm_V = value; 
      	      ; 
	      break;
      case 6:   /* b_1    */
              P->b_1 = value;
      	      ; 
	      break;
      case 7:   /* Per   */
              P->Per = value; 
      	      ; 
	      break;
      case 8:   /* Birth_V    */
              P->Birth_V = value;
      	      ; 
	      break;
      case 9:   /* Death_V   */
              P->Death_V = value; 
      	      ; 
	      break;
      case 10:   /* Rho    */
              P->Rho = value;
      	      ; 
	      break;
      case 11:   /* Tau   */
              P->Tau = value; 
      	      ; 
	      break;
      /*   END: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      case 12:   /* Realizations */
              P->Realizations = value;
	      ;
	      break;
      case 13:   /* Extinctions */
              P->DISCARTING_EXTINCTIONS = value;
	      ;
	      break;
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      /* BEGIN: * * * * * * * TIME CONTROL * * * * * * * * * * * */      
      case 14:
	      P->I_Time = value;
      	      ; 
	      break;
      case 15:
	      P->Time_0 = value;
      	      ; 
	      break;
      case 16:
	      P->Time_1 = value;
      	      ; 
	      break;
      case 17:
	      P->Time_Scale_Unit = value;
      	      ; 
	      break;
      case 18:
              P->TIME_DEPENDENT_PARAM = value;
      	      ; 
	      break;
      /*   END: * * * * * * * TIME CONTROL * * * * * * * * * * * */       
      /* BEGIN: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      case 19:
              P->SUB_MODEL_PARAMETERS = value;   
      	      ; 
	      break;
      case 20:
	      P->A_n = value;
	      ; 
	      break;
      case 21:
	      P->A_d = value; 
	      ; 
	      break;
      /*   END: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      /* BEGIN: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 22:
	      P->SUB_OUTPUT_VARIABLES = value;
	      ; 
	      break;
      /*   END: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 23:
              P->Growth_Function_Type = value;          
	      ; 
	      break;
      /* BEGIN: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 24:
              P->N = value;          
	      ; 
	      break;
      case 25:
              P->POPULATION = value;          
	      ; 
	      break;
      case 26:
              P->no_Patch = value;          
	      ; 
	      break;
      case 27:
              P->N_V = value;
              ;
              break;
      /*   END: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 28:
              P->EPSILON = value;          
	      ; 
	      break;
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
      /* BEGIN: * * * * * * INITIAL ONDITIONS  * * * * * * * * * */      	      
      case 29:   /*  Fraction_S_0   */
              P->Fraction_S_0 = value;  
      	      ; 
	      break;
      case 30:   /* Fraction_I_0   */
              P->Fraction_I_0 = value; 
      	      ; 
	      break;
      case 31:   /* Fraction_V_0   */
              P->Fraction_V_0 = value; 
      	      ; 
	      break;
      /*   END: * * * * * * INITIAL CONDITIONS  * * * * * * * * * */ 
#if defined POWER_SPECTRAL_DENSITY
      case 32:   /* PSD_TIMES  */
              P->PSD_TIMES = value; 
      	      ; 
	      break;
      case 33:   /* TRANSIENT */
              P->TRANSIENT = value; 
      	      ; 
	      break;
      case 34:   /* k_Sets   */
              P->k_Sets = value; 
      	      ; 
	      break;
      case 35:   /* STEP_SIZE  */
              P->STEP_SIZE = value; 
      	      ; 
	      break;
#endif
      /*   END: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
      default:
      printf(".... assignVectorEntry_to_TableStructure.c: INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Input_Parameters(stdout, P);	      
      exit(0);
      }
}
