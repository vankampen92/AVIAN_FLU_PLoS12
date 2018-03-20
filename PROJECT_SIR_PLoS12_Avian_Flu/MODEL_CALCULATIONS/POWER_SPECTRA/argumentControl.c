#include "../../Include/MODEL.h" 
/* Global Shared parameters main Program <---> ArgumentControl() */
#include "extern.h"

void ArgumentControl(int argc, char **argv)
{
  int argcount, skip;
  
  for(argcount=1; argcount<argc; argcount+=skip)
    {
      if(argv[argcount][0] == '-')
	{
	  skip = 1;
	  switch(argv[argcount][1])
	    {

#include "../../Include/include.Community.argumentControl.c"
#include "/home/dalonso/C_pro/Demos_UTLs_CPGPLOT/include.CPG.argumentControl.c"
#include "../../Include/include.Output_Variables.argumentControl.c"
#include "../../Include/include.Parameter_Model.argumentControl.c"
#include "../../Include/include.PARAMETER_SPACE.argumentControl.c"
#include "../../Include/include.Stochastic_Realizations.argumentControl.c"
#include "../../Include/include.Time_Control.argumentControl.c"
#include "../../Include/include.Type_Model.argumentControl.c"	      
#include "../../Include/include.Power_Spectra_Control.argumentControl.c"
#include "../../Include/include.Initial_Conditions.argumentControl.c"

  	    default:
	      printf("**invalid command line argument >%c< \n",
		     argv[argcount][1]);
	    case 'h':
	      paramCommand_Line(stdout, P_ARG);
	      printf("\n"); 
	      printf(" As an example,\n"); 
	      printf("        >> [PROGRAM_NAME] -n2 -v0 1 -v1 2 -B0 2\n\n");
	      exit(0);   
	    }
	}
      else
	{
	  printf("**invalid command line flag >%c<\n",argv[argcount][0]);
	  printf("try -h for help.\n");
	  exit(0);
	}
    }
}	




