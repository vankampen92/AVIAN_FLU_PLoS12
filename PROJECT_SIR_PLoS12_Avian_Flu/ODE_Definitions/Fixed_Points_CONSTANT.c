/*
   
  SIR MODEL WITH ENVIRONMENTAL TRANSMISSION (with constant community size)

*/
#include "../Include/MODEL.h"

void  F_I_X_E_D___P_O_I_N_T_S( Parameter_Table * Table )
{
  
  printf("Initial Condition: Population Values at the stationary state (Imm_V = %g):\n",
	 Table->P->Imm_V);
  double Psi, Fi, Vir;
  Fixed_Points_General(Table->P, &Psi, &Fi, &Vir);
  double I_0 = Table->POPULATION*Fi; 
  double S_0 = Table->POPULATION*Psi;
  double V_0 = Table->N_V*Vir;
  printf("Susceptible, S* = %g\tInfective, I* = %g\tVirus Population, V* = %g\n", S_0, I_0, V_0);
    Table->Vector_Model_Variables_Stationarity[0] = S_0;                               /* S */
    Table->Vector_Model_Variables_Stationarity[1] = I_0;                               /* I */
    Table->Vector_Model_Variables_Stationarity[2] = Table->POPULATION - S_0 - I_0;     /* R */
    Table->Vector_Model_Variables_Stationarity[3] = V_0;                               /* V */
}
