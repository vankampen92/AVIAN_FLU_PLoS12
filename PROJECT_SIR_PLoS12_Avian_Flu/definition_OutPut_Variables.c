#include "./Include/MODEL.h"

/* -n 2 -v0 0 -v1 2 */

double definition_OutPut_Variables(int j, Parameter_Table *T)
{
  /* T->Vector_Model_Variables is a copy of T->GLOBAL_I vector
     which contains the global state of the syste: number of
     individuals belonging to each class in the whole system
     at any given time */
  double x;
  Community * P;
  double N = (double)T->POPULATION;
  double N_V = (double)T->N_V;

  P = T->Patch[0];

  if (j < T->MODEL_VARIABLES ){
    if(j == (T->MODEL_VARIABLES-1)){
      x = T->Vector_Model_Variables[j]/(double)P->N_V;
    }
    else {
      x = T->Vector_Model_Variables[j]/(double)P->N;
    }
  }
  else if ( j >=   T->MODEL_VARIABLES && j < 2*T->MODEL_VARIABLES ){
    x = T->Vector_Model_Variables[j%T->MODEL_VARIABLES];
  }	
  else if ( j >= 2*T->MODEL_VARIABLES && j < 3*T->MODEL_VARIABLES ){
    x = (double)T->GLOBAL_I[j%T->MODEL_VARIABLES];
  }
  else if ( j >= 3*T->MODEL_VARIABLES && j < 4*T->MODEL_VARIABLES ){
    x = T->Vector_Model_Variables_Stationarity[j%T->MODEL_VARIABLES]; 
  }
  else if ( j >= 4*T->MODEL_VARIABLES && j < 5*T->MODEL_VARIABLES ){
    double Fi = T->Vector_Model_Variables_Stationarity[j%T->MODEL_VARIABLES];
    double X  = T->Vector_Model_Variables[j%T->MODEL_VARIABLES];
    if ( j%T->MODEL_VARIABLES == 3) {
      x = (X - Fi)/sqrt(N_V);
    }
    else{
      x = (X - Fi)/sqrt(N);
    }
  }
  else {
    /* switch(j) */
    /*   {    */
    /*   case 0: */
    /* 	x = T->Vector_Model_Variables[k]; */
    /* 	break;   */
    /*   case 1: */
    /* 	x = Global_Density(1, T);         */
    /* 	break;   */
    /*   case 2: */
    /* 	x = Local_Density(0, T);          */
    /* 	break;    */
    /*   case 3: */
    /* 	x = Local_Density(1, T);          */
    /*   break;   */
    /*   default: */
	printf(" INVALID VARIABLE CODE in ./defintion_OutPut_Variables.c (variable = %d)\n", j);
	printf(" Program will exit!  "); Press_Key();
	exit(0);
    /*  }         */ 
  }
  
  T->Default_Vector_Output_Variables[j] = x;
 
  return (x);
}

