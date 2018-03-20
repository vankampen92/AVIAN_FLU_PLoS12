#include "../Include/MODEL.h"

void Index_Definition(int * Index, Parameter_Table * T)
{
  /* Definition of the dimensions to explore */
  
  /* Number of parameter to explore: 3       */
  
  if (T->SUB_MODEL_PARAMETERS == 3) {
  
  Index[0]=1;   /* Beta            */
  Index[1]=2;   /* Gamma           */ 
  Index[2]=5;   /* Imm             */

  }
  else{
    printf(" The number of parameters to explore does not match\n");
    printf(" the number of dimensions defined in the Index vector\n");
    printf(" Unless this condition is fulfilled the program cannot\n");
    printf(" continue, and, unfortunately, will exit\n");
    printf(" Revise ./Parameter_Space_Definition/index.Defintion_xx.c\n");
    printf(" and the value of the input variable SUB_MODEL_PARAMETERS\n");
  }
}



