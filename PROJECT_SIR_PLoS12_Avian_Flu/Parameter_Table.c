#include "./Include/MODEL.h"

#include "/home/dalonso/C_pro/Demos_UTLs_CPGPLOT/include.CPG.extern.h"
#include "./Include/include.Community.extern.h"
#include "./Include/include.Time_Control.extern.h"
#include "./Include/include.Type_Model.extern.h"
#include "./Include/include.Output_Variables.extern.h"
#include "./Include/include.Parameter_Model.extern.h"
#include "./Include/include.PARAMETER_SPACE.extern.h"
#include "./Include/include.Stochastic_Realizations.extern.h"
#include "./Include/include.Initial_Conditions.extern.h"

#if defined POWER_SPECTRAL_DENSITY
#include "./Include/include.Power_Spectra_Control.extern.h"
#endif

void P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C( Parameter_Table *T )
{
  int i;
  
  T->Code_Parameters = (char **)malloc( MODEL_PARAMETERS_MAXIMUM * sizeof(char *) );
  for (i=0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    T->Code_Parameters[i] = (char *)malloc( 100 * sizeof(char) );
  }
  
  T->Name_Parameters = (char **)malloc( MODEL_PARAMETERS_MAXIMUM * sizeof(char *) );
  for (i=0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    T->Name_Parameters[i] = (char *)malloc( 100 * sizeof(char) );
  }
  T->Default_Vector_Parameters = (double *)malloc( MODEL_PARAMETERS_MAXIMUM * sizeof(double) );

  T->Index = (int *)malloc( MODEL_PARAMETERS_MAXIMUM * sizeof(int) );
  T->Vector_Parameters = (double *)malloc( MODEL_PARAMETERS_MAXIMUM * sizeof(double) );

  T->Variable_Name = (char **)malloc( OUTPUT_VARIABLES_MAXIMUM * sizeof(char *) );
  for (i=0; i<OUTPUT_VARIABLES_MAXIMUM; i++){
    T->Variable_Name[i] = (char *)malloc( 100 * sizeof(char) );
  }
  T->Default_Vector_Output_Variables = (double *)malloc( OUTPUT_VARIABLES_MAXIMUM * sizeof(double) );

  T->Model_Variable_Name = (char **)malloc( MODEL_VARIABLES_MAXIMUM * sizeof(char *) );
  for (i=0; i<MODEL_VARIABLES_MAXIMUM; i++){
    T->Model_Variable_Name[i] = (char *)malloc( 100 * sizeof(char) );
  }
  T->Vector_Model_Variables = (double *)malloc( MODEL_VARIABLES_MAXIMUM * sizeof(double) );
  T->Vector_Model_Variables_Stationarity = (double *)malloc( MODEL_VARIABLES_MAXIMUM * sizeof(double) );

  T->GLOBAL_I = (int *)calloc( MODEL_VARIABLES_MAXIMUM , sizeof(int) );
  
  T->IO_VARIABLE_LIST = (int *)malloc( OUTPUT_VARIABLES_MAXIMUM * sizeof(int) );
  T->Vector_Output_Variables = (double *)malloc( OUTPUT_VARIABLES_MAXIMUM * sizeof(double) );
}

void P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( Parameter_Table * T )
{
  int i;
  /* Time Control Upload */
  T->I_Time = I_Time;
  T->Time_0 = Time_0;
  T->Time_1 = Time_1;
  T->Time_Scale_Unit = Time_Scale_Unit;;
  T->TIME_DEPENDENT_PARAM = TIME_DEPENDENT_PARAM;
  T->EPSILON         = EPSILON;
  /* Parameter Model Upload */
  T->Beta   = Beta;
  T->Alpha  = Alpha;
  T->Gamma  = Gamma;
  T->Delta  = Delta;
  T->Mu     = Mu;
  T->Imm_V  = Imm_V;
  T->b_1    = b_1;
  T->Per    = Per;
  T->Birth_V = Birth_V;
  T->Death_V = Death_V;
  T->Rho     = Rho;
  T->Tau     = Tau;
  
   /* Initial Conditions */
  T->Fraction_S_0         = Fraction_S_0;
  T->Fraction_I_0         = Fraction_I_0;
  T->Fraction_V_0         = Fraction_V_0;

  /* Parameter Space Upload */
  T->SUB_MODEL_PARAMETERS = SUB_MODEL_PARAMETERS;
  T->A_n = A_n;
  T->A_d = A_d;
  /* * * * * * * * * * * * */
  T->MODEL_PARAMETERS     = MODEL_PARAMETERS_MAXIMUM;
  T->SUB_OUTPUT_VARIABLES = SUB_OUTPUT_VARIABLES;
  /* Community Upload     */
  T->N_V                  = N_V;                     /* Single Virus Patch Capacity */
  T->N                    = N;                       /* Single Patch Capacity: Human Constant Population  */
  T->MODEL_VARIABLES      = MODEL_VARIABLES_MAXIMUM; /* Number of variables needed to describe the state
							of the system at any given time */
  T->POPULATION           = POPULATION;      /* Total System Capacity (adding up all patches)    */
  T->no_Patch             = no_Patch;        /* Total number of patches                          */

#if defined POWER_SPECTRAL_DENSITY
  T->TRANSIENT = TRANSIENT;
  T->PSD_TIMES = PSD_TIMES;
  T->k_Sets    = k_Sets;
  T->STEP_SIZE = STEP_SIZE;
#endif

#if defined CPGPLOT_REPRESENTATION
  /* CPG PLOT Upload      */
  T->CPG__PANEL__X       = CPG__PANEL__X;
  T->CPG__PANEL__Y       = CPG__PANEL__Y;

  T->CPG_SCALE_X         = CPG_SCALE_X;
  T->CPG_RANGE_X_0       = CPG_RANGE_X_0;
  T->CPG_RANGE_X_1       = CPG_RANGE_X_1;

  T->CPG_SCALE_Y         = CPG_SCALE_Y;
  T->CPG_RANGE_Y_0       = CPG_RANGE_Y_0;
  T->CPG_RANGE_Y_1       = CPG_RANGE_Y_1;
#endif

  /* Type of Model upload  */
  T->Growth_Function_Type= Growth_Function_Type;

  /* Stochastic Realizations Upload */
  T->Realizations = Realizations;
  T->DISCARTING_EXTINCTIONS = DISCARTING_EXTINCTIONS;

  /* BEGIN: Parameter default values into vector structure */
  for(i = 0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    T->Default_Vector_Parameters[i] = AssignStructValue_to_VectorEntry(i, T);
  }
  /*   END: Parameter default values into vector structure */
  /* BEGIN: Names and codes for model parameters */
  for(i = 0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    AssignLabel_to_Parameters(i, T->Name_Parameters[i], T);
    AssignCodes_to_Parameters(i, T->Code_Parameters[i], T);
  }
  /*   END: Names and codes for model parameter  */
  /* BEGIN: Names for output variables */
  for(i = 0; i<OUTPUT_VARIABLES_MAXIMUM; i++){
    AssignLabel_to_OutPut_Variables(i, T->Variable_Name[i], T);
  }
  /*   END: Names for output variables */
  /* BEGIN: Names for model variables */
  for(i = 0; i<MODEL_VARIABLES_MAXIMUM; i++){
    AssignLabel_to_Model_Variables(i, T->Model_Variable_Name[i], T);
  }
  /*   END: Names for output variables */
  
  /* BEGIN: Output variable current actual values into IO_VARIABLE_LIST vector */
  T->IO_VARIABLE_LIST[0] = variable_0;
  T->IO_VARIABLE_LIST[1] = variable_1;
  T->IO_VARIABLE_LIST[2] = variable_2;
  T->IO_VARIABLE_LIST[3] = variable_3;
  T->IO_VARIABLE_LIST[4] = variable_4;
  T->IO_VARIABLE_LIST[5] = variable_5;
  T->IO_VARIABLE_LIST[6] = variable_6;
  T->IO_VARIABLE_LIST[7] = variable_7;
  T->IO_VARIABLE_LIST[8] = variable_8;
  /*   END: Output variable current actual values into IO_VARIABLE_LIST vector */
}

void P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E( Parameter_Table * T )
{
  int i;
  
  for (i=0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    free( T->Code_Parameters[i] );
  }
  free(T->Code_Parameters);
  
  for (i=0; i<MODEL_PARAMETERS_MAXIMUM; i++){
    free( T->Name_Parameters[i] );
  }
  free(T->Name_Parameters);
  free(T->Default_Vector_Parameters);

  free(T->Index);
  free(T->Vector_Parameters);
  
  for (i=0; i<OUTPUT_VARIABLES_MAXIMUM; i++){
    free(T->Variable_Name[i]);
  }
  free(T->Variable_Name);
  free(T->Default_Vector_Output_Variables);
 
  for (i=0; i<MODEL_VARIABLES_MAXIMUM; i++){
    free(T->Model_Variable_Name[i]);
  }
  free(T->Model_Variable_Name);
  free(T->Vector_Model_Variables);
  free(T->Vector_Model_Variables_Stationarity);

  free(T->GLOBAL_I);
 
  free(T->IO_VARIABLE_LIST);
  free(T->Vector_Output_Variables);
}

