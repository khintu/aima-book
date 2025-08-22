#include <agent_defs.h>

using namespace AI;

void* CThrdBase::threadObjectStartExecCb(void* arg) {
	
	CThrdBase* thrdHndl = static_cast<CThrdBase*>(arg);
	
	thrdHndl->thrdInitialize();
	thrdHndl->thrdExecution();
	thrdHndl->thrdFinalize();

	return NULL;
}

void CThrdBase::startThread(CThrdBase* threadObj)
{
	pthread_create(&threadObj->thread, NULL, CThrdBase::threadObjectStartExecCb, threadObj);
	return;
}