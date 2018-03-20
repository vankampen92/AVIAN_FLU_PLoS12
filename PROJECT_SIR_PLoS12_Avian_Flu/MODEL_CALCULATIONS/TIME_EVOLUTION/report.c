#include "../../Include/MODEL.h"

#include "extern.h"

void paramCommand_Line(FILE *fp, Parameter_Table *P)
{
  fprintf_Input_Parameters(fp, P);

#include "../../Include/include.Output_Variables.fprintPar.c"

#include "/home/dalonso/C_pro/Demos_UTLs_CPGPLOT/include.CPG.fprintPar.c"

}

void modelReport(char *File, Parameter_Table *P)
{
  FILE *fp;
  paramCommand_Line(stdout, P);  
  fp = fopen(File, "w");
  paramCommand_Line(fp, P);
  fclose(fp);
}
