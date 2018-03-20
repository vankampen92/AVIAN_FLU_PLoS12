#include "./Include/MODEL.h"

/* The prototypes of the following functions are  
   defined in 
   /home/dalonso/C_pro/Demo_UTLs_CPGPLOT/CPGPLOT_Drawing_X_Y.h"

   The functions in the following include are generic drivers 
   provided the defintion of the specific Parameter_Table 
   structure has been previously given.
*/

#include "/home/dalonso/C_pro/Demos_UTLs_CPGPLOT/CPGPLOT_Drawing_X_Y.c"

void C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R___D_R_I_V_E_R ( int DATA_POINTS,
									 Parameter_Table * Table)
{
  
  int DEVICE_NUMBER = cpgopen("/XSERVE");
  if (DEVICE_NUMBER <= 0 ) {
    printf(" Graphic device cannot be opened\n");
    exit(1);
  }
  printf(" PANEL__X = %d\tPANEL__Y = %d\n",
         Table->CPG__PANEL__X, Table->CPG__PANEL__Y);
  cpgsubp(Table->CPG__PANEL__X, Table->CPG__PANEL__Y);
  cpgask(0);
  C_P_G___S_U_B___P_L_O_T_T_I_N_G___E_R_R_O_R___B_A_R ( Table, DATA_POINTS,
                                                        Table->T->time_DEF,
                                                        Table->T->AVE,
							Table->T->VAR );
}

