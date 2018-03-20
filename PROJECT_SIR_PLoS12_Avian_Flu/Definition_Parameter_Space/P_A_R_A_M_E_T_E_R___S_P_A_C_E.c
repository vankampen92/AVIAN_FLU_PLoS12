#include "../Include/MODEL.h"

void P_A_R_A_M_E_T_E_R___S_P_A_C_E___A_L_L_O_C( Parameter_Space *S, Parameter_Table * T )
{
  S->P_MAX = gsl_vector_alloc(T->SUB_MODEL_PARAMETERS);
  S->P_min = gsl_vector_alloc(T->SUB_MODEL_PARAMETERS);
  S->Accuracy = gsl_vector_alloc(T->SUB_MODEL_PARAMETERS);
  S->I =(int *)calloc(T->SUB_MODEL_PARAMETERS, sizeof(int) );
#if defined DATA_ANALYSIS
  S->I_B = (int *)calloc(T->no_Func, sizeof(int) );
#endif
}

void P_A_R_A_M_E_T_E_R___S_P_A_C_E___U_P_L_O_A_D( Parameter_Space * S, Parameter_Table * T, 
						  double A_n, double A_d )
{
  int i,j;
  double a, value_0, value_1; 
  
  /* Pointer to I is exactly the same pointer to Index from Parameter Table Structure */
  /* As a consquence, only Index is allocated onto memmory by 
     P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C(), while I from Parameter Space Structure
     does not need to be neither allocated nor deallocated */
#if defined DATA_ANALYSIS
  for (i=0; i < T->no_Func; i++){
    S->I_B[i] = T->I_B [i];
  }
  S->no_Func  = T->no_Func;
#endif
  
  for (i=0; i<T->SUB_MODEL_PARAMETERS; i++){
    S->I[i]    = T->Index[i];
  }
  S->nPar = T->SUB_MODEL_PARAMETERS;

  Index_Definition(S->I, T);
  Index_Definition(T->Index, T);
  
  printf("Bounding search. Defining parameter space...\n");
  for(i=0; i < S->nPar; i++){

    j = S->I[i];

    Boundary(j, &value_0, &value_1);

    /* * * * * * */
    printf("Parameter: %s [ min_Value[%d] = %g\tMAX_Value[%d] = %g]\n", 
	   T->Name_Parameters[j], i, value_0, i, value_1);
    /* * * * * * */

    gsl_vector_set(S->P_MAX, i, value_1);    
    gsl_vector_set(S->P_min, i, value_0);
  }  

  /* Accuracies ... */
  S->A_n   = A_n;
  S->A_d   = A_d;
  for(i = 0; i < S->nPar; i++){
    /* All parameters are governed by the same accuracy */
    value_0 = gsl_vector_get(S->P_min, i);
    value_1 = gsl_vector_get(S->P_MAX, i);
    a = (value_1 - value_0)/A_d;
    gsl_vector_set(S->Accuracy, i, a);
  }
  /* * * * * * * * * * * * * * * * * * * * * * * * * */

  /* The table also points to the Parameter Space Structure */
  T->S     = S;
}

void P_A_R_A_M_E_T_E_R___S_P_A_C_E___F_R_E_E( Parameter_Space * S )
{
  gsl_vector_free(S->P_MAX);
  gsl_vector_free(S->P_min);
  gsl_vector_free(S->Accuracy);
  free (S->I); 
#if defined DATA_ANALYSIS
  free (S->I_B);
#endif
}
