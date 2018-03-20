/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                             SIR AVIAN FLUE MODEL                          */
/*	                                                                     */
/*                          (CONSTANT COMMUNITY SIZE)                        */
/*                                                                           */
/*                             David Alonso, 2000 (c)                        */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "../Include/MODEL.h"

extern gsl_rng * r;   /* Global generator (define at the main program level */
#define RANDOM gsl_rng_uniform_pos(r)

int execute_Step(Community ** Pop, Parameter_Model *pa, double max_Probability, int * Sum_I) 
{
  /* 
     Here a rejection method is implemented to choose the event to occur.
     This involves that the Village within the system is elected at random, and
     that the Total_Probability is in fact the largest transition rate for any
     species within the whole patch system.
  */
  int x, I;
  double P1;
  Community *pVil;
  int Event;

  /* Hierarchic procedure to find the even to occur... */  
  /* The event occurs within the villages... */
  if(pa->No_of_Patches == 1) x = 0;
  else                       x = which_Village(max_Probability, Pop, pa);
  pVil = Pop[x];

  int no_MODEL_VARIABLES = pVil->no_VARIABLES;
  
  I = Discrete_Sampling(pVil->rToI, 1+no_MODEL_VARIABLES) - 1; 
  
  /* I = 0, 1, 2, 3 */
  if(I == 0){                      
    /* The event is affecting the Susceptible population: Infection Event */
    Sum_I[1]++; pVil->I[1]++; 
    Sum_I[0]--; pVil->I[0]--; 
  }
  else if(I==1){
    P1 = pa->Gamma/pVil->rate[1]; 
    if(RANDOM < P1){
      /* The event is affecting the Infected population: Recovery Event */
      Sum_I[1]--;  pVil->I[1]--; 
      Sum_I[2]++;  pVil->I[2]++;  
    }
    else{
      /* The event is affecting the Infected population: Birth-Death Event */
      Sum_I[1]--; pVil->I[1]--; 
      Sum_I[0]++; pVil->I[0]++; 
    }
  }
  else if(I==2){
    /* This event is affecting on already recovered individual: Death-ReBirth */
    Sum_I[2]--; pVil->I[2]--; 
    Sum_I[0]++; pVil->I[0]++; 
  }
  else if(I==3){
    /* This event is affecting virus particles: either for death or reproduction */
    P1 = pa->Death_V/pVil->rate[3]; 
    if(RANDOM < P1){              /* Decay of virus particles */     
      Sum_I[3]--; pVil->I[3]--; 
    }
    else{
      Sum_I[3]++; pVil->I[3]++;   /* Birth of virus particles due 
				     virus replication */
    }
  }
  else if(I==4){
      Sum_I[3]++; pVil->I[3]++;   /* Release of virus particles to the environment
				     by infected humans*/
  }
  else{
    /* Something is very very wrong!!! */
    printf("I should be between either 0, 1, 2, 3\n");
    printf("I = %d\n", I);
    Press_Key();
  }
  
  Event = I;
  return (Event);
}






