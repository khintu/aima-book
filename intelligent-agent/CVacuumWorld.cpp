#include <agent_defs.h>

using namespace AI;

extern "C" { void printDistance(struct GVertex* v); }

void CVacuumWorld::GoalFormulation()
{
	grphList = initializeDjGraphContainer(inetMap.intrnt);
	return ;
}

void CVacuumWorld::ProblemFormulation()
{
	graphDijikstraCalcDistance2(TRUE, grphList, inetMap.intrnt, src, inetMap.gIntfTbl);
	return ;
}

void CVacuumWorld::Search()
{
	cout << "Hi!, from Vacuum World!" << endl;

	WIteratorList(grphList, (void (*)(void*))printDistance);
	return ;
}

void CVacuumWorld::Execution()
{
	graphTraceShortstPathFrmSrc2Trgt(grphList, inetMap.intrnt, dst);
	return ;
}

// Populate with human readable message
string CVacuumWorld::serialize()
{
	string s;
	return s;
}