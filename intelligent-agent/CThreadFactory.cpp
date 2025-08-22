#include <agent_defs.h>

using namespace AI;


CThrdBase* CThreadFactory::CreateThreadObj(CSimpleSearching *a)
{
	CThrdAgent* threadObj;
	threadObj = new CThrdAgent(a);
	CThrdBase::startThread(threadObj);
	return threadObj;
}

