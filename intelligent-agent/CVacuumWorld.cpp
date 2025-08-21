#include <agent_defs.h>

using namespace AI;


void CVacuumWorld::GoalFormulation()
{
	return ;
}

void CVacuumWorld::ProblemFormulation()
{
	return ;
}

void CVacuumWorld::Search()
{
	cout << "Hi!, from Vacuum World!" << endl;
	return ;
}

void CVacuumWorld::Execution()
{
	return ;
}

string CVacuumWorld::serialize()
{
	string s;
	return s;
}

CAgntBase* CVacuumWorld::clone() 
{
	return new CVacuumWorld();
}
