#/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#/*                                                                           */
#/*                  SIR MODEL WITH ENVIRONMETAL TRANSMISSION                 */
#/*                                                                           */
#/*                             AVIAN FLU                                     */
#/*                                                                           */
#/*                        David Alonso, 2010 (c)                             */
#/*                                                                           */
#/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
## Used directories:
## If Numerical Recipes libraries are locally built, C_NR should be:
C_NR=/home/dalonso/C_NumRecip# See also custumized ./bashrc file on ${HOME} directory.
## If the current and correct Numerical Recipes library are in C_pro, then C_NR should be: 
### C_NR =/home/dalonso/C_pro/C_NumRecip/
C_DIR =/home/dalonso/C_pro/#
PROJECT_DIR=${C_DIR}Stochastics/SIR_AVIAN_FLU/#
HEAD.H =${PROJECT_DIR}Include/MODEL.h##########
CPGPLOT = ${C_DIR}Demos_UTLs_CPGPLOT/##########
###EXTRA_LIBRARY_PATH=${LD_LIBRARY_PATH}#######
###EXTRA_INCLUDE_PATH=${LD_INCLUDE_PATH}####### See custumized ./bashrc file on ${HOME} directory. 
EXTRA_LIBRARY_PATH=/usr/local/pgplot###########
EXTRA_INCLUDE_PATH=/usr/local/pgplot########### See custumized ./bashrc file on ${HOME} directory. 
##############################################################################################################
##############################################################################################################
## C O M P I L A T I O N   O P T I O N S   C O N T R O L I N G   N U M E R I C A L   I N T E G R A T I O N  ##
T=NON_TIME_DEPENDENCE###################################### /'NON_TIME_DEPENDENCE' / 'TIME_DEPENDENCE'/ 
ODE_DIR=${PROJECT_DIR}Definition_Numerical_Integration/#########
ODE_DEF=${PROJECT_DIR}ODE_Definitions/##########################
TYPE_NUMERICAL_INTEGRATION=GSL_RK4##############################
ODE_MODEL=CONSTANT##############################################
##############################################################################################################
STOCHASTIC_DIR=${PROJECT_DIR}Definition_Stochastic_Dynamics/####
POWER_SPECTRA_DIR=${PROJECT_DIR}Definition_Power_Spectra_Calculation/####
##############################################################################################################
## C O M P I L A T I O N   O P T I O N S   C O N T R O L I N G   P R O G R A M   O U T P U T 
CPG=CPGPLOT_REPRESENTATION############## Possibilities: 'NON_CPGPLOT_REPRESENTATION' / 'CPGPLOT_REPRESENTATION' 
V=NON_VERBOSE########################### 'VERBOSE' / 'VERY_VERBOSE' / 'NON_VERBOSE'
##############################################################################################################
##############################################################################################################
RANDOM_SEED=CURRENT_TIME_RDN_SEED####### 'CURRENT_TIME_RDN_SEED' / 'FILE_RND_SIDE' 
##############################################################################################################
##############################################################################################################
## C O M P I L A T I O N   O P T I O N S   C O N T R O L I N G   T H E   D E F I N I T I O N   O F 
## T H E   P A R A M E T E R   S P A C E 
TYPE_of_BOUNDARY=_00################### 
TYPE_of_INDEX=_00_3p################### 
##############################################################################################################
##############################################################################################################
##############################################################################################################
##############################################################################################################
EXE=${ODE_MODEL}__${CPG}_B${TYPE_of_BOUNDARY}_I${TYPE_of_INDEX}
########################################
EXTERN=##-static######################## Possibilities: 
######################################## 'void' (locally executed) / '-static' (exported for execution) ###### 
LDFLAGS+=-lgsl -lm -lgslcblas -lNumRec -lNRUTL -L${C_NR} -L${C_DIR} -L${EXTRA_LIBRARY_PATH}
CXXFLAGS+=-I${C_NR} -I${EXTRA_INCLUDE_PATH} -I${C_DIR} -I${CPGPLOT} -g ${EXTERN} -D${V} -D${CPG} -D${RANDOM_SEED} -D${T} -D${TYPE_NUMERICAL_INTEGRATION} -DPOWER_SPECTRAL_DENSITY -DHAVE_INLINE #-Wall #-O3
##
LIBS=-L/usr/lib -lX11
PGPLOT_LIB=-L/usr/lib -lpgplot -L/usr/lib -lpng
CPGPLOT_LIB=-L/usr/lib -lcpgplot -lpgplot -L/usr/lib -lpng
##   
OBJECTS = stat.o GSL_stat.o GSL_Discrete_Sampling.o GSL_Init_Random_Seed.o cpgplot_UTL.o main.o argumentControl.o MODEL.o Parameter_Table.o Parameter_Model.o Parameter_CPGPLOT.o Time_Control.o P_A_R_A_M_E_T_E_R___S_P_A_C_E.o index.Definition${TYPE_of_INDEX}.o boundary${TYPE_of_BOUNDARY}.o  definition_OutPut_Variables.o assignCode_to_Input_Parameters.o assignLabel_to_Input_Parameters.o assignLabel_to_Output_Variables.o assignLabel_to_Model_Variables.o assignTableStructValue_to_Vector.o assignVectorEntry_to_TableStructure.o CPG_Drawing_X_Y_Drivers.o IO_Functions.o functions_SIR.o report.o jacobian_Entries_${ODE_MODEL}.o Fixed_Points_${ODE_MODEL}.o func_SIR_AVIAN_FLU.o Power_Spectra_Control.o func_PwSp_Analytic.o
# stochastic_time_dynamics.o advance_Time.o step.o tempRate.o   Community.o  # Stochastic Dynamics 
# evolving_Parameters.o deterministic_time_dynamics.o numerical_Integration_Driver.o Population_Initialization.o JAC_sys_${ODE_MODEL}.o ODE_sys_${ODE_MODEL}.o                                   # Deterministic Dynamics 
# power_spectra_time_dynamics.o IO_Functions_Power_Spectra.o powerSpectrum.o spectral_Density.o autoVar.o 
                                                                             # Power Specitrum Stochastic Averaging
CC=gcc##  
FF=gfortran##

all: ${EXE}

${EXE}:  	$(OBJECTS)   
		$(FF) -o ${EXE} $(OBJECTS) $(LDFLAGS) $(CXXFLAGS) $(CPGPLOT_LIB) $(LIBS)

GSL_stat.o:	${C_DIR}GSL_stat.c ${C_DIR}GSL_stat.h
	${CC} -c ${C_DIR}GSL_stat.c $(CXXFLAGS)

stat.o:	${C_DIR}stat.c ${C_DIR}stat.h
	${CC} -c ${C_DIR}stat.c $(CXXFLAGS)

GSL_Discrete_Sampling.o: ${C_DIR}GSL_Discrete_Sampling.c ${C_DIR}GSL_stat.h
	${CC} -c ${C_DIR}GSL_Discrete_Sampling.c $(CXXFLAGS)

GSL_Init_Random_Seed.o: ${C_DIR}GSL_Init_Random_Seed.c ${C_DIR}GSL_stat.h
	${CC} -c ${C_DIR}GSL_Init_Random_Seed.c $(CXXFLAGS)

cpgplot_UTL.o:	${CPGPLOT}cpgplot_UTL.c ${CPGPLOT}cpgplot_UTL.h
	${CC} -c ${CPGPLOT}cpgplot_UTL.c $(CXXFLAGS) 

main.o: main.c ${HEAD.H} 
	$(CC) -c main.c $(CXXFLAGS)

MODEL.o: MODEL.c ${HEAD.H} 
	$(CC) -c MODEL.c $(CXXFLAGS)

report.o: report.c ${HEAD.H}
	${CC} -c report.c $(CXXFLAGS)

argumentControl.o: argumentControl.c ${HEAD.H}
	${CC} -c argumentControl.c $(CXXFLAGS)

Power_Spectra_Control.o:	${PROJECT_DIR}Power_Spectra_Control.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Power_Spectra_Control.c $(CXXFLAGS)

functions_SIR.o: ${PROJECT_DIR}functions_SIR.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}functions_SIR.c $(CXXFLAGS)

func_SIR_AVIAN_FLU.o: ${PROJECT_DIR}func_SIR_AVIAN_FLU.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}func_SIR_AVIAN_FLU.c $(CXXFLAGS)

IO_Functions.o:	${PROJECT_DIR}IO_Functions.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}IO_Functions.c $(CXXFLAGS)

Parameter_Table.o: ${PROJECT_DIR}Parameter_Table.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Parameter_Table.c $(CXXFLAGS)

Parameter_Model.o: ${PROJECT_DIR}Parameter_Model.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Parameter_Model.c $(CXXFLAGS)

Parameter_CPGPLOT.o: ${CPGPLOT}Parameter_CPGPLOT.c ${HEAD.H}
	${CC} -c ${CPGPLOT}Parameter_CPGPLOT.c $(CXXFLAGS)

CPG_Drawing_X_Y_Drivers.o:	${PROJECT_DIR}CPG_Drawing_X_Y_Drivers.c ${CPGPLOT}cpgplot_UTL.h
	${CC} -c ${PROJECT_DIR}CPG_Drawing_X_Y_Drivers.c $(CXXFLAGS) 

Time_Control.o: ${PROJECT_DIR}Time_Control.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Time_Control.c $(CXXFLAGS)

func_PwSp_Analytic.o: ${PROJECT_DIR}func_PwSp_Analytic.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}func_PwSp_Analytic.c $(CXXFLAGS)

definition_OutPut_Variables.o: ${PROJECT_DIR}definition_OutPut_Variables.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}definition_OutPut_Variables.c ${CXXFLAGS}

assignLabel_to_Input_Parameters.o: ${PROJECT_DIR}assignLabel_to_Input_Parameters.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}assignLabel_to_Input_Parameters.c $(CXXFLAGS)

assignLabel_to_Model_Variables.o: ${PROJECT_DIR}assignLabel_to_Model_Variables.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}assignLabel_to_Model_Variables.c $(CXXFLAGS)

assignLabel_to_Output_Variables.o: ${PROJECT_DIR}assignLabel_to_Output_Variables.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}assignLabel_to_Output_Variables.c $(CXXFLAGS)

assignVectorEntry_to_TableStructure.o: ${PROJECT_DIR}assignVectorEntry_to_TableStructure.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}assignVectorEntry_to_TableStructure.c $(CXXFLAGS)

assignTableStructValue_to_Vector.o:	${PROJECT_DIR}/assignTableStructValue_to_Vector.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}$/assignTableStructValue_to_Vector.c $(CXXFLAGS)

assignCode_to_Input_Parameters.o:	${PROJECT_DIR}/assignCode_to_Input_Parameters.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}$/assignCode_to_Input_Parameters.c $(CXXFLAGS)

jacobian_Entries_${ODE_MODEL}.o: ${ODE_DEF}jacobian_Entries_${ODE_MODEL}.c ${HEAD.H} 
	$(CC) -c ${ODE_DEF}jacobian_Entries_${ODE_MODEL}.c $(CXXFLAGS)

Fixed_Points_${ODE_MODEL}.o: ${ODE_DEF}Fixed_Points_${ODE_MODEL}.c ${HEAD.H} 
	$(CC) -c ${ODE_DEF}Fixed_Points_${ODE_MODEL}.c $(CXXFLAGS)

P_A_R_A_M_E_T_E_R___S_P_A_C_E.o: ${PROJECT_DIR}Definition_Parameter_Space/P_A_R_A_M_E_T_E_R___S_P_A_C_E.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Definition_Parameter_Space/P_A_R_A_M_E_T_E_R___S_P_A_C_E.c $(CXXFLAGS)

boundary${TYPE_of_BOUNDARY}.o:   ${PROJECT_DIR}Definition_Parameter_Space/boundary${TYPE_of_BOUNDARY}.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Definition_Parameter_Space/boundary${TYPE_of_BOUNDARY}.c $(CXXFLAGS)

index.Definition${TYPE_of_INDEX}.o: ${PROJECT_DIR}Definition_Parameter_Space/index.Definition${TYPE_of_INDEX}.c ${HEAD.H}
	${CC} -c ${PROJECT_DIR}Definition_Parameter_Space/index.Definition${TYPE_of_INDEX}.c $(CXXFLAGS)

# Non-compiled functions: 
# evolving_Parameters.o: ${PROJECT_DIR}evolving_Parameters.c ${HEAD.H}
#	${CC} -c ${PROJECT_DIR}evolving_Parameters.c $(CXXFLAGS)

# Population_Initialization.o: ${PROJECT_DIR}Population_Initialization.c ${HEAD.H}
#	${CC} -c ${PROJECT_DIR}Population_Initialization.c $(CXXFLAGS)

# deterministic_time_dynamics.o: ${ODE_DIR}deterministic_time_dynamics.c ${HEAD.H} 
#	$(CC) -c ${ODE_DIR}deterministic_time_dynamics.c $(CXXFLAGS)

# numerical_Integration_Driver.o: ${ODE_DIR}numerical_Integration_Driver.c ${HEAD.H} 
#	$(CC) -c ${ODE_DIR}numerical_Integration_Driver.c $(CXXFLAGS)

# JAC_sys_${ODE_MODEL}.o: ${ODE_DEF}JAC_sys_${ODE_MODEL}.c ${HEAD.H} 
#	$(CC) -c ${ODE_DEF}JAC_sys_${ODE_MODEL}.c $(CXXFLAGS)

# ODE_sys_${ODE_MODEL}.o: ${ODE_DEF}ODE_sys_${ODE_MODEL}.c ${HEAD.H} 
#	$(CC) -c ${ODE_DEF}ODE_sys_${ODE_MODEL}.c $(CXXFLAGS)

# powerSpectrum.o: ${C_DIR}/PowerSpectrum/powerSpectrum.c ${C_DIR}/PowerSpectrum/pwsp.h
#	${CC} -c ${C_DIR}/PowerSpectrum/powerSpectrum.c $(CXXFLAGS)

# spectral_Density.o: ${C_DIR}/C_NumRecip/spectral_Density.c 
#	${CC} -c ${C_DIR}/C_NumRecip/spectral_Density.c $(CXXFLAGS)

# autoVar.o: ${C_DIR}/PowerSpectrum/autoVar.c ${C_DIR}/PowerSpectrum/pwsp.h
# 	${CC} -c ${C_DIR}/PowerSpectrum/autoVar.c $(CXXFLAGS)

# Community.o: ${PROJECT_DIR}Community.c ${HEAD.H}
#	${CC} -c ${PROJECT_DIR}Community.c $(CXXFLAGS)

# stochastic_time_dynamics.o: ${STOCHASTIC_DIR}stochastic_time_dynamics.c ${HEAD.H} 
#	$(CC) -c ${STOCHASTIC_DIR}stochastic_time_dynamics.c $(CXXFLAGS)

# power_spectra_time_dynamics.o: ${POWER_SPECTRA_DIR}power_spectra_time_dynamics.c ${HEAD.H} 
#	$(CC) -c ${POWER_SPECTRA_DIR}power_spectra_time_dynamics.c $(CXXFLAGS)

# advance_Time.o: ${STOCHASTIC_DIR}advance_Time.c ${HEAD.H} 
#	$(CC) -c ${STOCHASTIC_DIR}advance_Time.c $(CXXFLAGS)

# step.o: ${STOCHASTIC_DIR}step.c ${HEAD.H}
#	${CC} -c ${STOCHASTIC_DIR}step.c $(CXXFLAGS)

# tempRate.o: ${STOCHASTIC_DIR}tempRate.c ${HEAD.H}
#	${CC} -c ${STOCHASTIC_DIR}tempRate.c $(CXXFLAGS)

clean:  
	rm -f *.o *~ core         

include ${PROJECT_DIR}Makefile.General.Help







