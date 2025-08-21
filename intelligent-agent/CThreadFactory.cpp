#include <agent_defs.h>

using namespace AI;


CThrdBase* CThreadFactory::CreateThreadObj(CSimpleSearching *a)
{
	CThrdAgent* threadObj;
	threadObj = new CThrdAgent(a);
	pthread_create(&threadObj->thread, NULL, CThrdBase::threadObjectStartExecCb, threadObj);
	return threadObj;
}

