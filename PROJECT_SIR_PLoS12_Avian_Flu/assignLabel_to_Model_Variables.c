#include "./Include/MODEL.h"

void AssignLabel_to_Model_Variables(int j, char * Label, Parameter_Table *P)
{
  switch(j)
    {
    case 0:   /* S */
              label_Name(Label, " [ S ] : D e n s i t y   o f   S  ");

              ; 
	      break;
    case 1:   /* I */
              label_Name(Label, " [ I ] : D e n s i t y   o f   I  ");
	       
              ; 
	      break;
    case 2:   /* R */
              label_Name(Label, " [ R ] : D e n s i t y   o f   R  ");
	       
              ; 
	      break;
    case 3:   /* V */
              label_Name(Label, " [ V ] : D e n s i t y   o f   V  ");
	       
              ; 
	      break;
    default:
      printf(".... assignLabel_to_Model_Variables.c: INVALID MODEL VARIABLE KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Output_Variables(stdout, P);	      
      exit(0);
    }
}	



