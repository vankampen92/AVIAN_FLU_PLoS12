
void Temporal_Dynamics(Community ** Village, Parameter_Model *pa, Stochastic_Rate * Rate);

int execute_Step(Community ** Pop, Parameter_Model *pa, double max_Probability, int Sum_I[]); 

void S_T_O_C_H_A_S_T_I_C___T_I_M_E___D_Y_N_A_M_I_C_S( int i, 
						      Parameter_Table * Table, 
						      int * Bad_Times );

int ADVANCE_CURRENT_TIME( Parameter_Table * Table, 
			  Stochastic_Rate * Rate, double * Time_Current, int * New );








