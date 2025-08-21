#include <agent_defs.h>

using namespace AI;

void CThrdAgent::thrdInitialize(){
	// Initialization code for the agent thread
	agent->GoalFormulation();
	agent->ProblemFormulation();
}
void CThrdAgent::thrdExecution(){
	// Execution code for the agent thread
	agent->Search();
}
void CThrdAgent::thrdFinalize(){
	// Finalization code for the agent thread
	agent->Execution();
}
