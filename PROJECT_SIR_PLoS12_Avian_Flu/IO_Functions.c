#include "./Include/MODEL.h"

void fprintf_Input_Parameters(FILE * fp, Parameter_Table * P)
{
  int i,k;

  if( MODEL_PARAMETERS_MAXIMUM >= P->MODEL_PARAMETERS ) {
    fprintf(fp, "Input Parameter:\t\t[-Input Code\tDefault Value]\n");
    for(i=0; i < P->MODEL_PARAMETERS; i++){
      fprintf(fp, "%d: %s:\t[ %s\t%g]\n", 
	      i, P->Name_Parameters[i], P->Code_Parameters[i], P->Default_Vector_Parameters[i] );
    }
  }
  else {
    fprintf(fp, "Input Parameter\t Input Code\t Default Value:\n");
    for(i=0; i < P->MODEL_PARAMETERS; i++){
      k = P->Index[i];
      fprintf(fp, "%d: %s:\t[ %s\t%g]\n", 
	      k, P->Name_Parameters[k], P->Code_Parameters[k], P->Default_Vector_Parameters[k] );
    }
    
  }
}

void fprintf_Output_Variables(FILE *fp, Parameter_Table * P)
{
  int i,k;

  if( OUTPUT_VARIABLES_MAXIMUM >= P->SUB_OUTPUT_VARIABLES ) {
    fprintf(fp, "Potential Output Variables:\n");

    for(i=0; i < OUTPUT_VARIABLES_MAXIMUM; i++){
      fprintf(fp, "%d: Variable Name: %s\n", i, P->Variable_Name[i]);
    }
  }
  else{
    fprintf(fp, "Represented Output Variables:\n");

    for(i=0; i<P->SUB_OUTPUT_VARIABLES; i++){
      k = P->IO_VARIABLE_LIST[i];
      fprintf(fp, "%d: Variable Name: %s\n", k, P->Variable_Name[k]);
    }
  }
}

int AVE_VAR_SAVING_SUB_OUTPUT_VARIABLES ( Parameter_Table * Table )
{
  /* This function is usually called after completing 
     a set of stochastic realizations. */
  /*
     Notice that the corresponding vectors for
     each output variable summ[][] and summ_var[][]
     are used to calculate the averages and standard deviations
     respectively per time point.
  */
  int i,j,k, jj;
  int n        = Table->SUB_OUTPUT_VARIABLES;
  int I_TIMES  = Table->T->I_Time;
  double ave, var;
  
  FILE ** fp    = (FILE **)malloc( n * sizeof(FILE *) );
  char ** Files = (char **)calloc( n, sizeof(char *) );  
  for(i=0; i < n; i++){
    jj = Table->IO_VARIABLE_LIST[i];
    Files[i] = (char *)calloc( 50, sizeof(char) );
    Files[i][0]='\0';   
    fitxer(Files[i], "output_VAR_", jj, ".dat");
  }

  /*Opening files */
  for(i=0; i < n; i++) fp[i]=fopen(Files[i],"w");
  
  /* Re-scaling times (daily), if necessary */
  /* ...                                    */
  /* Not done here                          */
  jj = 0;
  for (j=0; j<I_TIMES; j++){
    /* Saving the strain temporal evolution */
    if(Table->T->count[j] > 0){
      for(k=0; k < n; k++){
	ave = Table->T->summ[k][j]/(double)Table->T->count[j];
	var = Table->T->summ_var[k][j]/(double)Table->T->count[j] - ave*ave;
	if(var >= 0)
	  var = sqrt(var);
	else
	  var = 0.;
	fprintf(fp[k],"%g\t%g\t%g\n",Table->T->Time_Vector[j], ave, var);
	
	Table->T->AVE[k][jj] = ave;
	Table->T->VAR[k][jj] = var;
      }
      Table->T->time_DEF[jj] = Table->T->Time_Vector[j];
      jj++;
    }
  }
  /*Closing files and deallocating memmory */
  for(i=0; i < n; i++) { fclose(fp[i]); free (Files[i]); }
  free ( fp );
  free ( Files );

  return(jj);
}


