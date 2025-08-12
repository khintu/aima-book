#include <agent_defs.h>

extern "C" {
	int insert_in_main_algolib_unittestsuit(int argc, char* argv[]);
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
}

int main(int argc, char* argv[])
{
	//insert_in_main_router_unittestsuit(argc, argv);
	
	try {
		
		AI::CThrdAgent threadObj[4];

		pthread_create(&threadObj[0].thread, NULL, AI::CThrdBase::threadObjectStartExecCb, &threadObj[0]);
		pthread_create(&threadObj[1].thread, NULL, AI::CThrdBase::threadObjectStartExecCb, &threadObj[1]);
		pthread_create(&threadObj[2].thread, NULL, AI::CThrdBase::threadObjectStartExecCb, &threadObj[2]);
		pthread_create(&threadObj[3].thread, NULL, AI::CThrdBase::threadObjectStartExecCb, &threadObj[3]);
		threadObj[0].waitToExit();
		threadObj[1].waitToExit();
		threadObj[2].waitToExit();
		threadObj[3].waitToExit();
	}
	catch (AI::Exception e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "Unexpected error! shutting down" << endl;
	}
	return 0;
}