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

/* This function advances the system one single time step, by changing
   system configuration by one single discrete event.  Since
   the stochastic dynamics is implemented following Gillespie algorithm
   the exact time at which this occurs is sampled from an exponential
   distribution at rate the represents the total rate at which the
   system changes configuration at any given time (Stochastic_Rate->Total_Rate).

   This function calls two fundamental functions, step() and Temporal_Dynamics(), 
   where the actual model specific stochastic dynamics is defined.
*/

extern gsl_rng * r;   /* Global generator (define at the main program level */
#define RANDOM gsl_rng_uniform_pos(r)

int ADVANCE_CURRENT_TIME( Parameter_Table * Table, 
			  Stochastic_Rate * Rate, double * Time_Current, int * New )
{
  /* (*New) counts the number of infection events */ 
  int k;
  double inter_event_time; 
  int Event;
  double Max_Probability     = Rate->max_Probability;

  int no_Patch               = Table->no_Patch;
  if( no_Patch > 1 ) {
    printf("This function is designed for a mono-patch system\n");
    printf("For a multi-patch system, another execute_step () function should be used instead\n");
    printf("The program will exit..."); Press_Key();
    exit(0);
  }
  
  Community ** Village       = Table->Patch;   
  Parameter_Model * par      = Table->P;
  int * Sum_I                = Table->GLOBAL_I;
  int TIME_DEPENDENT_PARAM   = Table->TIME_DEPENDENT_PARAM;
  int DISCARTING_EXTINCTIONS = Table->DISCARTING_EXTINCTIONS;  
  double time_Factor         = Table->Time_Scale_Unit;
  
  if( (Rate->Total_Rate) > 0){

    inter_event_time = -1./(Rate->Total_Rate) * log(RANDOM);
    (*Time_Current) += inter_event_time;
    
    /* BEGIN : Stochastic Dynamic is actually performed : Village is updated accoundingly */
    Event = execute_Step(Village, par, Max_Probability, Sum_I);
    /*   END : Stochasctic Dynamics * * * * * */
    if(Event == 0) (*New)++; /* Accumulating infection events... */

    for(k=0; k < Table->MODEL_VARIABLES; k++){
      Table->Vector_Model_Variables[k] = (double)Sum_I[k];
    }
  }
  else{    
    printf(" Total System Probability Rate of Change = %g\n",  Rate->Total_Rate);
    printf(" When the total Rate is zero, the average time to the next event is infinite!!!\n");
    printf(" So, events can no longer occur. The system does not react any more.\n");
    for(k=0; k < Table->MODEL_VARIABLES; k++){
      Table->Vector_Model_Variables[k] = (double)Sum_I[k];
    }
    return(1);  
  }
  
  /* BEGIN: Calculation of the Total Rate of Change for the system       */
  
  /*  Note: Model parameters may have changed if they are time-dependent */
#if defined TIME_DEPENDENCE 
  Time_Dependent_Parameters( par, (*Time_Current) );
   
  printf("Evolving parameters at tempRate.c under debugging and construction"); Press_Key();  
#endif
  
  Temporal_Dynamics(Village, par, Rate);
  /*   END: Calculation of Total Rate of Change */
  return(0);
}
  
  





