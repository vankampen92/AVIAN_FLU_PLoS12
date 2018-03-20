#include "./Include/MODEL.h"

/* In this file the label for all the parameter of the models
   is defined for the first time and stored in a structure for
   further use in the program
*/

/* Model Dynamics:
   dydx[0]  = -Beta * y[0]*y[1] - Imm*y[0] + (Delta+Mu) *(1. -y[0]-y[1]) + (Delta+Alpha) *y[1]; 
   dydx[1]  = +Beta * y[0]*y[1] + Imm*y[0] - Gamma *y[1] - (Delta+Alpha) *y[1];  
*/
   
void AssignLabel_to_Parameters(int j, char * Label, Parameter_Table *P)
{
  
    switch(j)
      {
      /* BEGIN: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */      
      case 0:   /* Beta: force of infection parameter */
              label_Name(Label, "Transmission Rate");  
              ; 
	      break;
      case 1:   /* Alpha */
              label_Name(Label, "Disease-induced Mortality rate"); 
              ; 
	      break;
      case 2:   /* Delta */
	      label_Name(Label, "Natural Mortality Rate");
      	      ; 
	      break;
      case 3:   /* Gamma */
	      label_Name(Label, "Recovery Rate  (I --> R)");
      	      ; 
	      break;
      case 4:   /* Mu    */
              label_Name(Label, "Loss of Immunity Rate (R --> S)");
      	      ; 
	      break;
      case 5:   /* Imm_V   */
              label_Name(Label, "Virus External Immigration Rate"); 
      	      ; 
	      break;
      case 6:   /* b_1    */
              label_Name(Label, "Seasonal Forcing Amplitud ");
      	      ; 
	      break;
      case 7:   /* Per   */
              label_Name(Label, "Seasonal Forcing Period"); 
      	      ; 
	      break;
      case 8:   /* Birth_V    */
              label_Name(Label, "Virus Percapita Replication Rate");
      	      ; 
	      break;
      case 9:   /* Death_V   */
              label_Name(Label, "Virus Percapita Decaying Rate"); 
      	      ; 
	      break;
      case 10:   /* Rho    */
              label_Name(Label, "Environmental Infection Rate");
      	      ; 
	      break;
      case 11:   /* Tau   */
              label_Name(Label, "Virus Shedding Rate"); 
      	      ; 
	      break;
      /*   END: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      case 12:   /* Realizations */
              label_Name(Label, "Number of Stochastic Realizations");
	      ;
	      break;
      case 13:   /* Extinctions */
              label_Name(Label, "Discarting extinctions (1: YES / 0: NO)");
	      ;
	      break;
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      /* BEGIN: * * * * * * * TIME CONTROL * * * * * * * * * * * */      
      case 14:
	      label_Name(Label, "I_Time: Number of discrete simulated times");
      	      ; 
	      break;
      case 15:
	      label_Name(Label, "Initial Time");
      	      ; 
	      break;
      case 16:
	      label_Name(Label, "Final Time");
      	      ; 
	      break;
      case 17:
	      label_Name(Label, "Time Scale");
      	      ; 
	      break;
      case 18:
              label_Name(Label, "Time dependence (YES: 1 / NO: 0)");
      	      ; 
	      break;
      /*   END: * * * * * * * TIME CONTROL * * * * * * * * * * * */       
      /* BEGIN: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      case 19:
              label_Name(Label, 
			 "SUB_MODEL_PARAMETERS: Number of parameters defining the parameter subset to explore");   
      	      ; 
	      break;
      case 20:
              label_Name(Label, 
			 "A_n: Integer Accuracy");
	      ; 
	      break;
      case 21:
              label_Name(Label, 
			 "A_d: Double Accuracy");
	      ; 
	      break;
      /*   END: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      /* BEGIN: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 22:
              label_Name(Label, 
			 "SUB_OUTPUT_VARIABLES: Number of output variables defining the subset to explore");
	      ; 
	      break;
      /*   END: * * * * * * OUTPUT VARIABLES  * * * * * * * * * */      
      case 23:
              label_Name(Label, "Model Type");          
	      ; 
	      break;
      /* BEGIN: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 24:
              label_Name(Label, "Single Patch Capacity");          
	      ; 
	      break;
      case 25:
              label_Name(Label, "Total System Capacity");          
	      ; 
	      break;
      case 26:
              label_Name(Label, "Total Number of Patches in the System");          
	      ; 
	      break;
      case 27:
              label_Name(Label, "Single Virus Patch Capacity");
              ;
              break; 
     /*   END: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 28:
              label_Name(Label, "EPSILON: Sampling Time Precision Value");          
	      ; 
	      break;
      /* BEGIN: * * * * * * INITIAL ONDITIONS  * * * * * * * * * */      	      
      case 29:   /*  Fraction_S_0   */
              label_Name(Label, "S_0 Initial Fraction"); 
      	      ; 
	      break;
      case 30:   /* Fraction_I_0   */
              label_Name(Label, "I_0 Initial Fraction"); 
      	      ; 
	      break;
      case 31:   /* Fraction_V_0   */
              label_Name(Label, "V_0 Initial Fraction"); 
      	      ; 
	      break;
      /*   END: * * * * * * INITIAL CONDITIONS  * * * * * * * * * */   
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
#if defined POWER_SPECTRAL_DENSITY
      case 32:   /* Per   */
              label_Name(Label, "Number of Sampling Times"); 
      	      ; 
	      break;
      case 33:   /* Per   */
              label_Name(Label, "Number of Transient Times"); 
      	      ; 
	      break;
      case 34:   /* Per   */
              label_Name(Label, "k_Sets: Number of K sets"); 
      	      ; 
	      break;
      case 35:   /* Per   */
              label_Name(Label, "STEP_SIZE"); 
      	      ; 
	      break;
#endif
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
    default:
      printf(".... assignLabel_to_Input_Parameters.c: INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Input_Parameters(stdout, P);	      
      exit(0);
    }
}
