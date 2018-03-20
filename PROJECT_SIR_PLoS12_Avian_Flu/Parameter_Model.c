#include "./Include/MODEL.h"

void  P_A_R_A_M_E_T_E_R___I_N_I_T_I_A_L_I_Z_A_T_I_O_N ( Parameter_Table * Table, 
						        Parameter_Model * P )
{
  P->Beta     = Table->Beta;
  P->Alpha    = Table->Alpha;
  P->Gamma    = Table->Gamma;
  P->Delta    = Table->Delta;
  P->Mu       = Table->Mu;
  P->Imm_V    = Table->Imm_V;

  P->Birth_V  = Table->Birth_V;
  P->Death_V  = Table->Death_V;
  P->Rho      = Table->Rho;
  P->Tau      = Table->Tau;

  P->b_1      = Table->b_1;
  P->Per      = Table->Per;
  
  P->N_V      = Table->N_V;
  P->N        = Table->N;

  
  P->MODEL_VARIABLES      = Table->MODEL_VARIABLES;
  P->Growth_Function_Type = Table->Growth_Function_Type;
  P->Time_Scale_Unit      = Table->T->Time_Scale_Unit;

  Table->P  = P;
}

void P_A_R_A_M_E_T_E_R___M_O_D_E_L___F_R_E_E( Parameter_Model * P)
{
  free ( P );
}
