#include "./Include/MODEL.h"

void P_O_P_U_L_A_T_I_O_N___I_N_I_T_I_A_L_I_Z_A_T_I_O_N___D_E_T_E_R_M_I_N_I_S_T_I_C ( Parameter_Table  * Table )
{
  int j, no;
#if defined INITIAL_CONDITIONS
  double x;
  /* Initial conditions are optimized with the goal of matching a set of data */
  /* Initial conditions are then searcheable paraemters                       */
  x = Table->Fraction_S_0 + Table->Fraction_I_0;
  if( x > 1 ){
    /* Renormalization occurs: */
    Table->Vector_Model_Variables[0] = Table->Fraction_S_0/x * (double)Table->POPULATION;
    Table->Vector_Model_Variables[1] = Table->Fraction_I_0/x * (double)Table->POPULATION;
    
    Table->Fraction_S_0 /= x; Table->Fraction_I_0 /= x;
    Table->Vector_Model_Variables[2] = (1.0-Table->Fraction_S_0-Table->Fraction_I_0) * (double)Table->POPULATION;
    
    x = (Table->Vector_Model_Variables[0] + Table->Vector_Model_Variables[1] + Table->Vector_Model_Variables[2]);
    if( (int)x > Table->POPULATION ) {
      printf("Initial conditions are ill-defined:\n");
      printf("S_0: Fraction of Susceptibles = %g\n", Table->Fraction_S_0);
      printf("I_0: Fraction of Infectives   = %g\n", Table->Fraction_I_0);
      printf("POPULATION : %d \t S_0 + I_0 + R_0 = %g\n", Table->POPULATION, x);
      Press_Key(); exit(0);
    }
  }
  else {
    Table->Vector_Model_Variables[0] = Table->Fraction_S_0 * Table->POPULATION;
    Table->Vector_Model_Variables[1] = Table->Fraction_I_0 * Table->POPULATION;
    Table->Vector_Model_Variables[2] = (1.0 - x) * Table->POPULATION;
  }
  
  Table->Vector_Model_Variables[3]   = Table->Fraction_V_0 * (double)Table->N_V;
#else
  no = Table->no_Patch;
  if( no == 1){
    Population_Initialization( Table, Table->GLOBAL_I, 0 );
    for( j = 0; j < Table->MODEL_VARIABLES; j++){ 
      Table->Vector_Model_Variables[j] = (double)Table->GLOBAL_I[j];
    }
  }
  else{
    printf(" Warning from Population_Initalization.c !!!\n");
    printf(" Single Patch System!!!\n");
    printf(" For a multi-patch system, another function should be used instead\n");
    printf(" The program will exit\n"); Press_Key();
    exit(0);
  }
#endif 
}

void P_O_P_U_L_A_T_I_O_N___I_N_I_T_I_A_L_I_Z_A_T_I_O_N ( Parameter_Table * Table, Community ** PATCH )
{
  int i, j, no;
  double Rate, max_Probability;

  /* Populations and rates need initialization before the start of any
     new stochastic realization */
  no = Table->no_Patch;  
  for(i=0; i<no; i++){
#if defined POWER_SPECTRAL_DENSITY
    Population_Initialization_Stationarity( Table, PATCH[i]->I, PATCH[i]->no_VARIABLES);
#else
    Population_Initialization( Table, PATCH[i]->I, i );
#endif
  }

  if( no == 1){
#if defined POWER_SPECTRAL_DENSITY
    Population_Initialization_Stationarity( Table, Table->GLOBAL_I, Table->MODEL_VARIABLES );
#else
    Population_Initialization ( Table, Table->GLOBAL_I, 0 );
#endif

    for( j = 0; j < Table->MODEL_VARIABLES; j++){ 
      Table->Vector_Model_Variables[j] = (double)Table->GLOBAL_I[j];
    }
  }
  else{
    printf("Check whether step.c and tempRate.c have been designed for a multi-patch system\n");
    printf("For a multi-patch system, another function should be used instead\n");
    printf("The program will exit\n"); Press_Key();
    exit(0);
  }
}

void Population_Initialization ( Parameter_Table * Table, 
				 int * I, int i )
{
  double x;
  int N = Table->Patch[i]->N;

#if defined INITIAL_CONDITIONS    
  x = Table->Fraction_S_0 + Table->Fraction_I_0;
  if( x > 1 ){
    I[2] = 0;
    I[0] = (int)( Table->Fraction_S_0/x * (double)N ); 
    I[1] = (int)( Table->Fraction_I_0/x * (double)N ); 
    
    Table->Fraction_S_0 =  (double)I[0]/(double)N;
    Table->Fraction_I_0 =  (double)I[1]/(double)N;
    
    I[2] = N - I[0] - I[2];  
  }
  else{
    I[0] = (int)(Table->Fraction_S_0 * (double)N);
    I[1] = (int)(Table->Fraction_I_0 * (double)N);
    I[2] = N - I[0] - I[1];
  }
  I[3]   = (int)T(able->Fraction_V_0 * (double)Table->N_V);
#else
  /* Different Initalization can be coded */
  I[0] = N - 10;          /* S */
  I[1] = 10;              /* I */
  I[2] = 0;               /* R */
  I[3] = Table->N_V;      /* V */
#endif
}

void Population_Initialization_Stationarity ( Parameter_Table *T, 
					      int * I, int n )
{
  int N = T->POPULATION;
  /* Different Initalization can be coded */
  I[0] = (int)T->Vector_Model_Variables_Stationarity[0];     /* S */
  I[1] = (int)T->Vector_Model_Variables_Stationarity[1];     /* I */
  I[2] = (int)T->Vector_Model_Variables_Stationarity[2];     /* R */
  I[3] = (int)T->Vector_Model_Variables_Stationarity[3];     /* R */
}

