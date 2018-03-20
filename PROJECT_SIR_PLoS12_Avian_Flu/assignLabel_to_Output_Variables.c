#include "./Include/MODEL.h"

/* In this file the label for output variables of the model
   is defined for the first time and stored in a structure for
   further use in the program
*/

void AssignLabel_to_OutPut_Variables(int j, char * Label, Parameter_Table *P)
{
  /* See ../definition_OutPut_Variables.c
     
     to find a the defintion for the same output variables.
     
     Output variable names and labels in that file and here should be
     always in total agreement.
  */
  
  switch(j)
    {
    case 0:   /* S */
              label_Name(Label, " [ S ] : F r a c t i o n   o f   S  ");

              ; 
	      break;
    case 1:   /* I */
              label_Name(Label, " [ I ] : F r a c t i o n   o f   I  ");
	       
              ; 
	      break;
    case 2:   /* R */
              label_Name(Label, " [ R ] : F r a c t i o n   o f   R  ");
	       
              ; 
	      break;
    case 3:   /* V */
              label_Name(Label, " [ V ] : F r a c t i o n   o f   V  ");
	       
              ; 
	      break;
    case 4:   /* S: Number in a given patch or local community */
              label_Name(Label, " [ S ] : L o c a l   N u m b e r   o f   S  ");

              ; 
	      break;
    case 5:   /* I: Number in a given patch or local community */
              label_Name(Label, " [ I ] : L o c a l   N u m b e r   o f   I  ");
	       
              ; 
	      break;
    case 6:   /* R: Number in a given patch or local community */
              label_Name(Label, " [ R ] : L o c a l   N u m b e r   o f   R  ");
	       
              ; 
	      break;
    case 7:   /* V: Number in a given patch or local community */
              label_Name(Label, " [ V ] : L o c a l   N u m b e r   o f   V  ");
	       
              ; 
	      break;
    case 8:   /* Global Population Density Sp 1 (S)*/
              label_Name(Label, " [ S ] : G l o b a l   N u m b e r   o f   S  ");

              ; 
	      break;
    case 9:   /* Global Population Density Sp 2 (I)*/
              label_Name(Label, " [ I ] : G l o b a l   N u m b e r   o f   I ");
	       
              ; 
	      break;
    case 10:   /* Global Population Density Sp 3 (R) */
	      label_Name(Label, " [ R ] : G l o b a l   N u m b e r   o f   R ");
      
	      ; 
	      break;
    case 11:   /* Global Population Density Sp 4 (V) */
	      label_Name(Label, " [ V ] : G l o b a l   N u m b e r   o f   V ");
      
	      ; 
	      break;
    case 12:   /* Standarized Population Density Sp 1 (S)*/
              label_Name(Label, " [ S ] : S t a n d a r i z e d   N u m b e r ");
              ; 
	      break;
    case 13:   /* Standarized Population Density Sp 2 (I)*/
              label_Name(Label, " [ I ] : S t a n d a r i z e d   N u m b e r ");
              ; 
	      break;
    case 14:   /* Standarized Population Density Sp 3 (R) */
	      label_Name(Label, " [ R ] : S t a n d a r i z e d   N u m b e r  ");
	      ; 
	      break;
    case 15:   /* Standarized Population Density Sp 4 (V) */
	      label_Name(Label, " [ V ] : S t a n d a r i z e d   N u m b e r  ");
	      ; 
	      break;
    case 16:   /* Standarized Population Density Sp 1 (S)*/
              label_Name(Label, " [ S ] : S t a t i o n a r y   N u m b e r ");
              ; 
	      break;
    case 17:   /* Standarized Population Density Sp 2 (I)*/
              label_Name(Label, " [ I ] : S t a t i o n a r y   N u m b e r ");
              ; 
	      break;
    case 18:   /* Standarized Population Density Sp 3 (R) */
	      label_Name(Label, " [ R ] : S t a t i o n a r y   N u m b e r  ");
	      ; 
	      break;
    case 19:   /* Standarized Population Density Sp 4 (V) */
	      label_Name(Label, " [ V ] : S t a t i o n a r y   N u m b e r  ");
	      ; 
	      break;
    default:
      printf(".... assignLabel_to_Output_Variables.c: INVALID OUTPUT VARIABLE KEY [key = %d]\n", j);
      printf(".... The permited correspondences are:\n");
      printf("\n");
      fprintf_Output_Variables(stdout, P);	      
      exit(0);
    }
}	



