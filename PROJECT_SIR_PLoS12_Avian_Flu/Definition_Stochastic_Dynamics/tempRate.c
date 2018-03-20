/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                                  SIR MODEL                                */
/*	                                                                     */
/*                          (CONSTANT COMMUNITY SIZE)                        */
/*                                                                           */
/*                             David Alonso, 2000 (c)                        */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Include/MODEL.h"

void Temporal_Dynamics(Community ** Village, Parameter_Model *pa, Stochastic_Rate * Rate)
{
  int i,j,k;
  Community *P;
  int no_MODEL_VARIABLES;
  int No_of_Villages;

  No_of_Villages = pa->No_of_Patches;

  P = Village[0];
  no_MODEL_VARIABLES = P->no_VARIABLES;

  Rate->max_Probability = 0.0;
  Rate->Total_Rate      = 0.0;
  /* Transitions allowed within the patch system:
     Events are grouped in 5 competing types:
     1. Events affecting S humans
     2. Events affecting I humans
     3. Events affecting R humans
     4. Events affecting V virus
     5. Shedding events by which virus are released to the environment
        by infected humans
  */
  for(i=0; i<No_of_Villages; i++, P++){
  
    P->rate[0] = 0.;
    /* Infection rate of susceptibles through human contact or 
       environmental virus infection (per individual) */
    P->rate[0]+=pa->Beta*P->I[1]/(double)P->N + pa->Rho*P->I[3]/(double)P->N_V;           //(1. S)
    P->H_infect = P->rate[0];
    
    /* Recovery plus Death-Birth (Constant Population) rate of infected 
       individuals (per individual) */
    P->rate[1] = pa->Delta + pa->Alpha + pa->Gamma;                                       //(2. I)
    
    /* Death-Birth (Constant population) of Recovered Individuals 
       (per individual) */
    P->rate[2] = pa->Mu + pa->Delta;                                                      //(3. R)

    /* Death of virus particles (per virus): Decay vs Reproduction 
       in the environment*/
    
    P->rate[3] = pa->Death_V + pa->Birth_V;                                               //(4. V)
    
    /* Vilage Transition Rate */  
    P->ratePatch = 0.;
    for(k=0; k<no_MODEL_VARIABLES; k++) {
      P->ratePatch += (double)P->I[k] * P->rate[k];
      P->rToI[k] = (double)P->I[k] * P->rate[k];
    }
    
    /* Shedding event */                                                                  //(5. V)
    P->rToI[no_MODEL_VARIABLES] = pa->Tau*P->I[1] + pa->Imm_V; 
    P->ratePatch               += pa->Tau*P->I[1] + pa->Imm_V;

    Rate->Total_Rate += P->ratePatch;
    Rate->max_Probability = MAX( Rate->max_Probability, P->ratePatch);
    
    if(Rate->Total_Rate <= 0.){
      printf("\n");
      printf(" R is the total temporal rate of system configuration change\n");
      printf(" R = %g\n", Rate->Total_Rate );
      printf(" As R is zero or negative, no change is possible\n");
      printf(" R shouldn't be negative. If it is, there are definitely some errors in the code\n");
      printf("\n");
      if( Rate->Total_Rate < 0.) exit(0);
    }
  }
}







