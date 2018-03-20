#include "./Include/MODEL.h"

/* In this file the label for all the parameter of the models
   is defined for the first time and stored in a structure for
   further use in the program
*/

/* Model Dynamics:
   dydx[0]  = -Beta * y[0]*y[1] - Imm*y[0] + (Delta+Mu) *(1. -y[0]-y[1]) + (Delta+Alpha) *y[1]; 
   dydx[1]  = +Beta * y[0]*y[1] + Imm*y[0] - Gamma *y[1] - (Delta+Alpha) *y[1];  
*/
   
void AssignCodes_to_Parameters(int j, char * Label, Parameter_Table *P)
{
  
    switch(j)
      {
      /* BEGIN: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */      
      case 0:   /* Beta: force of infection parameter */
              label_Name(Label, "-A0");  
              ; 
	      break;
      case 1:   /* Alpha */
              label_Name(Label, "-A1"); 
              ; 
	      break;
      case 2:   /* Delta */
	      label_Name(Label, "-A2");
      	      ; 
	      break;
      case 3:   /* Gamma */
	      label_Name(Label, "-A3");
      	      ; 
	      break;
      case 4:   /* Mu    */
              label_Name(Label, "-A4");
      	      ; 
	      break;
      case 5:   /* Imm_V   */
              label_Name(Label, "-A5"); 
      	      ; 
	      break;
      case 6:   /* b_1    */
              label_Name(Label, "-A6");
      	      ; 
	      break;
      case 7:   /* Per   */
              label_Name(Label, "-A7"); 
      	      ; 
	      break;
      case 8:   /* Birth_V    */
              label_Name(Label, "-A8");
      	      ; 
	      break;
      case 9:   /* Death_V   */
              label_Name(Label, "-A9"); 
      	      ; 
	      break;
      case 10:   /* Rho    */
              label_Name(Label, "-A10");
      	      ; 
	      break;
      case 11:   /* Tau   */
              label_Name(Label, "-A11"); 
      	      ; 
	      break;
      /*   END: * * * * * * * MODEL PARAMETERS  * * * * * * * * * */
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      case 12:   /* Realizations */
              label_Name(Label, "-R0");
	      ;
	      break;
      case 13:   /* Extinctions */
              label_Name(Label, "-R1");
	      ;
	      break;
      /* BEGIN: * * * * * * * STOCHASTIC CONTROL  * * * * * * * * */      
      /* BEGIN: * * * * * * * TIME CONTROL * * * * * * * * * * * */      
      case 14:
	      label_Name(Label, "-T0");
      	      ; 
	      break;
      case 15:
	      label_Name(Label, "-T1");
      	      ; 
	      break;
      case 16:
	      label_Name(Label, "-T2");
      	      ; 
	      break;
      case 17:
	      label_Name(Label, "-T3");
      	      ; 
	      break;
      case 18:
              label_Name(Label, "-T4");
      	      ; 
	      break;
      /*   END: * * * * * * * TIME CONTROL * * * * * * * * * * * */       
      /* BEGIN: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      case 19:
              label_Name(Label, "-P0");   
      	      ; 
	      break;
      case 20:
              label_Name(Label, "-P1");
	      ; 
	      break;
      case 21:
              label_Name(Label, "-P2");
	      ; 
	      break;
      /*   END: * * * * * * SUBPARAMETER SPACE * * * * * * * * * */      
      /* BEGIN: * * * * * * No OUTPUT VARIABLES  * * * * * * * * * */      
      case 22:
              label_Name(Label, "-n");
	      ; 
	      break;
      /*   END: * * * * * * No OUTPUT VARIABLES  * * * * * * * * * */      
      case 23:
              label_Name(Label, "-M0");          
	      ; 
	      break;
      /* BEGIN: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 24:
              label_Name(Label, "-C0");          
	      ; 
	      break;
      case 25:
              label_Name(Label, "-C1");          
	      ; 
	      break;
      case 26:
              label_Name(Label, "-C2");          
	      ; 
	      break;
      case 27:
              label_Name(Label, "-C3");
              ;
              break;
      /*   END: * * * * * * PATCH SYSTEM DEFINITION  * * * * * * * * * */      	      
      case 28:
              label_Name(Label, "-E");          
	      ; 
	      break;
      /* BEGIN: * * * * * * INITIAL ONDITIONS  * * * * * * * * * */      	      
      case 29:   /*  Fraction_S_0   */
              label_Name(Label, "-Y0"); 
      	      ; 
	      break;
      case 30:   /* Fraction_I_0   */
              label_Name(Label, "-Y1"); 
      	      ; 
	      break;
      case 31:   /* Fraction_V_0   */
              label_Name(Label, "-Y2"); 
      	      ; 
	      break;
      /*   END: * * * * * * INITIAL CONDITIONS  * * * * * * * * * */   
      /* BEGIN: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */      	      
#if defined POWER_SPECTRAL_DENSITY
      case 32:   /* Per   */
              label_Name(Label, "-D0"); 
      	      ; 
	      break;
      case 33:   /* Per   */
              label_Name(Label, "-D1"); 
      	      ; 
	      break;
      case 34:   /* Per   */
              label_Name(Label, "-D2"); 
      	      ; 
	      break;
      case 35:   /* Per   */
              label_Name(Label, "-D3"); 
      	      ; 
	      break;
#endif
      /*   END: * * * * * * POWER SPECTRAL DENSITY  * * * * * * * * * */
      default:
      printf(".... assignCode_to_Input_Parameters.c: INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Input_Parameters(stdout, P);	      
      exit(0);
    }
}
