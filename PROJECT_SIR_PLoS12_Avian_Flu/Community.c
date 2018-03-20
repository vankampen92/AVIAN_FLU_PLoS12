#include "./Include/MODEL.h"

void C_O_M_M_U_N_I_T_Y___A_L_L_O_C_A_T_I_O_N ( Parameter_Table * Table, Community ** PATCH )
{  
  int i;
  int no;

  no = Table->no_Patch;
  for(i=0; i<no; i++){
    PATCH[i] = (Community *)calloc( 1, sizeof(Community) );
    PATCH[i]->I = (int *)calloc( Table->MODEL_VARIABLES, sizeof( int ));
    PATCH[i]->rate = (double *)calloc( Table->MODEL_VARIABLES, sizeof( double ));
    PATCH[i]->rToI = (double *)calloc( 1 + Table->MODEL_VARIABLES, sizeof( double ));
  }
}

void C_O_M_M_U_N_I_T_Y___F_R_E_E (Community ** PATCH, int n)
{
  int i;
  /* BEGIN: Patch Total Destruction */
  for (i=0; i<n; i++){
    free(PATCH[i]->I);
    free(PATCH[i]->rate);
    free(PATCH[i]->rToI);
    free(PATCH[i]);	
  } 
  free( PATCH );
  /*   END: Patch Total Destruction */
}

void C_O_M_M_U_N_I_T_Y___I_N_I_T_I_A_L_I_Z_A_T_I_O_N (Parameter_Table * Table, Community ** PATCH)
{
  int i, no;

  no = Table->no_Patch;
  for(i=0; i<no; i++){
    PATCH[i]->N_V          = Table->N_V;
    PATCH[i]->no_VARIABLES = Table->MODEL_VARIABLES;
    PATCH[i]->N            = Table->N;
    PATCH[i]->ratePatch    = 0.0;  /* Transition probability at this patch                    */
    PATCH[i]->H_infect     = 0.0;
  }
  /* When PATCH represents a multi-patch network, patch connections
     should be initialized
  */

  /* The Parameter Table structure also keeps the memmory address pointing to 
     the multi-species multi-patch structure */
  Table->Patch = PATCH;
}

/* void C_O_M_M_U_N_I_T_Y___I_N_I_T_I_A_L_I_Z_A_T_I_O_N___S_T_A_T_I_O_N_A_R_I_T_Y( Parameter_Table * Table,  */
/* 									        Community ** PATCH) */
