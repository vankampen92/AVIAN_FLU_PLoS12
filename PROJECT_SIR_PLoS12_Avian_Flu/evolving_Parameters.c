#include "./Include/MODEL.h" 

void Time_Dependent_Parameters( Parameter_Model * P, double t)
{
  /* time (days) = Time (dimless units) /  time_Factor; */
  /* time_Factor (P->turns time into a time measured in days. 
     If time is already measured in days, then time_Factor should
     be 1.
     Notice that the forcing period $Per$ should be measured in the 
     same time units as times.
     Here, time_Factor is defined as with T^(-1) units.
  */
  double B;
  double Term, lnBeta;
  
  int Type = P->Growth_Function_Type; /* Type of forcing */
  
  switch (Type) {
  case 0: /* Sinusoidal Seasonal Forcing */
    B = P->Beta * (1. + P->b_1 * sin(2.* M_PI * t/P->Per));
    break;
  case 1: /* School term Seasonal Forcing (Keeling-Rohani-Grenfell, 2001) */
    Term = Time_of_the_Year(t / P->Time_Scale_Unit);
    lnBeta = log(P->Beta) + Term * log(1. + P->b_1);
    B = exp(lnBeta);
    break;
  case 2: /* School term Seasonal Forcing (Earn-Rohani-Bolker-Grenfell) */
    Term = Time_of_the_Year(t/ P->Time_Scale_Unit);
    B = P->Beta * (1.+ P->b_1 * Term);
    break;
  default:
      printf(" Invalid Seasonal Forcing (0, 1, 2)\n");
      printf(" TIME_DEPENDENCE type = %d\n", Type);
      printf(" but only 0, 1, and 2 are allowed\n");
      exit(0);
  }
  
  P->Beta_Effective = B;
}

double Time_of_the_Year(double time)
{
  /* School Terms in England */
  /* Time should be given as an input in days */
  double rest;
  double School_Term;
  
  rest = (int)time%365;  /* The current day of the current year */
  
  if(rest >=1. && rest <= 6.)
    School_Term = -1.;  
  else if(rest >=100. && rest <= 115.)
    School_Term = -1.;
  else if(rest >=200. && rest <= 251.)
    School_Term = -1.;
  else if(rest >=300. && rest <= 307.)
    School_Term = -1.;
  else if(rest >=356. && rest <= 365.)
    School_Term = -1.;
  else
    /* During School Terms */
    School_Term = +1.;
  
  return(School_Term);
}

double Time_of_the_Year_Two_Terms(double time)
{
  /* Two Terms within a year in England */
  /* Time should be given as an input in days */
  double rest;
  double School_Term;
  
  rest = (int)time%365;  /* The current day of the current year */
  
  if(rest >=1. && rest <= 182.56)
    /* During the first half of the year */
    School_Term = -1.;  
  else
    /* During the second half of the year */
    School_Term = +1.;
  
  return(School_Term);
}
