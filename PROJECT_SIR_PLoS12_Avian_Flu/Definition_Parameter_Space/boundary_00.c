#include "../Include/MODEL.h"

/* Model Dynamics:
   dydx[0]  = -Beta * y[0]*y[1] - Imm*y[0] + (Delta+Mu) *(1. -y[0]-y[1]) + (Delta+Alpha) *y[1]; 
   dydx[1]  = +Beta * y[0]*y[1] + Imm*y[0] - Gamma *y[1] - (Delta+Alpha) *y[1];  
*/
   
void Boundary(int j, double * value_0, double * value_1)
{
  
    switch(j)
    {
      
    case 0:   /* Beta: force of infection parameter */
              /* Transmission Rate */  
             (*value_1) = 1.5; 
	      (*value_0) = 0.0; 
	      break;
    case 1:   /* Alpha */
              /* Disease-induced Mortality rate */ 
             (*value_1) = 0.01; 
	      (*value_0) = 0.0; 
	      break;
    case 2:   /* Delta */
	      /* Natural Mortality Rate */
      	     (*value_1) = 0.005; 
	      (*value_0) = 0.0; 
	      break;
    case 3:   /* Gamma */
	      /* Recovery Rate  (I --> R) */
      	     (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 4:   /* Mu    */
              /* Loss of Immunity Rate (R --> S) */
      	     (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 5:   /* Imm   */
              /* External Force of Infection (Imm) */ 
      	     (*value_1) = 0.001; 
	      (*value_0) = 0.0; 
	      break;
    case 6:   /* Realizations */
              /* Number of Stochastic Realizations */
              (*value_1) = 100.0;
	      (*value_0) = 0.0; 
	      break;
    case 7:   /* Extinctions */
              /* Discarting extinctions (1: YES / 0: NO) */
	      (*value_1) = 1.0;
	      (*value_0) = 0.0; 
	      break;
    case 8:
	      /* I_Time: Number of discrete simulated times */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 9:
	      /* Initial Time */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 10:
	      /* Final Time */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 11:
	      /* Time Scale */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 12:
	      /* Time dependence (YES: 1 / NO: 0) */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 13:
              /* SUB_MODEL_PARAMETERS: Number of parameters defining the parameter subset to explore */   
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 14:
              /* A_n: Integer Accuracy */
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 15:
              /* A_d: Double Accuracy */
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 16:
              /* SUB_OUTPUT_VARIABLES: Number of output variables defining the subset to explore */
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 17:
	      /* CPG__PANEL__X: Number of horizontal subpanels */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 18:
              /* CPG__PANEL__Y: Number of vertical subpanels */
      	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 19:
              /* Growth Function Type */          
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 20:
              /* Single Patch Capacity */          
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 21:
              /* Total System Capacity */          
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 22:
              /* Number of Model Variables */          
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 23:
              /* Total Number of Patches in the System */          
	      (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    case 24:
              /* EPSILON */          
	      (*value_1) = 0.5; 
	      (*value_0) = 0.0; 
	      break;	      
    /* BEGIN: * * * * * * INITIAL ONDITIONS  * * * * * * * * * */      	      
    case 29:   /*  Fraction_S_0   */
              (*value_1) = 1.0; 
	      (*value_0) = 0.0;      
              break;
    case 30:   /* Fraction_I_0   */
              (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
              break;
    case 31:   /* Fraction_V_0   */
              (*value_1) = 1.0; 
	      (*value_0) = 0.0; 
	      break;
    /*   END: * * * * * * INITIAL CONDITIONS  * * * * * * * * * */ 
    default:
      printf(".... INVALID PARAMETER KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");     
      exit(0);
    }
}
