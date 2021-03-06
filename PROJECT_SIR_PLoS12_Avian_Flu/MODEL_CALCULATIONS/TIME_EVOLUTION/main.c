/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                      SIV MODEL: AVIAN INFLUENZA VIRUS                     */
/*	                                                                     */
/*                          (CONSTANT COMMUNITY SIZE)                        */
/*                                                                           */
/*                            David Alonso, 2010 (c)                         */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../../Include/MODEL.h"

#include "global.h"

#define RANDOM_NUMBER_SETUP "/home/dalonso/C_pro/gsl_random_number_Setup.c"
gsl_rng * r;                  /* Global generator:                      */
                              /* r: It is a reserved variable name!!!   */

int main(int argc, char **argv)
{
  int i;
  Parameter_Space Space;
  Parameter_Table Table;
  Time_Control Time;
 
  P_ARG = &Table;

#include "default.c"    
  
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C(   &Table );
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( &Table );

  /* Command line arguments */
  if(argc>1) ArgumentControl(argc,argv);

  P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E(     &Table );

  P_A_R_A_M_E_T_E_R___T_A_B_L_E___A_L_L_O_C(   &Table );
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___U_P_L_O_A_D( &Table );

  P_A_R_A_M_E_T_E_R___S_P_A_C_E___A_L_L_O_C( &Space, &Table );
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___U_P_L_O_A_D( &Space, &Table, A_n, A_d);

  T_I_M_E___C_O_N_T_R_O_L___A_L_L_O_C( &Time, &Table, I_Time);
  T_I_M_E___C_O_N_T_R_O_L___U_P_L_O_A_D( &Time, &Table, I_Time);
  
#if defined CPGPLOT_REPRESENTATION
  printf(" Number of Output Variables = %d\t Number of Subpanels = %d\n", 
	 SUB_OUTPUT_VARIABLES, CPG__PANEL__X * CPG__PANEL__Y);
  if( SUB_OUTPUT_VARIABLES > CPG__PANEL__X * CPG__PANEL__Y ){
    printf(" Warning!!!\n Not enough subpanels to draw this quantity of output variables.\n");
    Press_Key();
    /*   printf(" The program will exit\n"); */
    /*   exit(0); */
  }
  int DEVICE_NUMBER = cpgopen("/XSERVE");
  if (DEVICE_NUMBER <= 0 ) {
    printf(" Graphic device cannot be opened\n");
    exit(1);
  }
  cpgsubp(CPG__PANEL__X, CPG__PANEL__Y); /* Subdivision of the window in panels.
					    Automatic writing on consecutive panels
					    in CPG__PANEL__X  x  CPG__PANEL__Y grid 
					 */
  cpgask(0);

  Parameter_CPGPLOT * C = (Parameter_CPGPLOT *)malloc( 1 * sizeof(Parameter_CPGPLOT) );
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___A_L_L_O_C (C, SUB_OUTPUT_VARIABLES, I_Time);
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___U_P_L_O_A_D (C);
  Table.CPG = C;
#endif

#include RANDOM_NUMBER_SETUP
#if defined VERBOSE
  /* BEGIN: Checking Random Number Generator Setup */
  for(i=0; i<10; i++){
    printf( "f(%d)=%g, ", i, gsl_rng_uniform(r) );
  }
  printf("\n");Press_Key();
  /*   END: Checking Random Number Generator Setup */
#endif

  M_O_D_E_L( &Table );

  /* BEGIN : Freeing All Memmory * * * * * * * * * * * * * * */
  P_A_R_A_M_E_T_E_R___T_A_B_L_E___F_R_E_E( &Table );
  P_A_R_A_M_E_T_E_R___S_P_A_C_E___F_R_E_E( &Space );
  T_I_M_E___C_O_N_T_R_O_L___F_R_E_E( &Time, &Table );
  /*  END : Freeing  All Memmory * * * * * * * * * * * * * * */

#if defined CPGPLOT_REPRESENTATION
  P_A_R_A_M_E_T_E_R___C_P_G_P_L_O_T___F_R_E_E( C, SUB_OUTPUT_VARIABLES );
  cpgclos();
#endif  

  printf("\nEnd of progam\n");
  return (0);
}





