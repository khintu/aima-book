#include <agent_defs.h>

extern "C" {
	int insert_in_main_algolib_unittestsuit(int argc, char* argv[]);
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
}


using namespace AI;

int main(int argc, char* argv[])
{
	//insert_in_main_router_unittestsuit(argc, argv);
	
	try {
		
		CAbstractFactory* factory = new CThreadFactory();
		CSimpleSearching* agent = new CVacuumWorld();
		CThrdBase* threadObj[4];

		threadObj[0] = factory->CreateThreadObj(agent);
		threadObj[1] = factory->CreateThreadObj(agent);
		threadObj[2] = factory->CreateThreadObj(agent);
		threadObj[3] = factory->CreateThreadObj(agent);


		threadObj[0]->waitToExit(); delete threadObj[0];
		threadObj[1]->waitToExit(); delete threadObj[1];
		threadObj[2]->waitToExit(); delete threadObj[2];
		threadObj[3]->waitToExit(); delete threadObj[3];
	
		delete factory;
	
	}
	catch (AI::Exception& e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "Unexpected error! shutting down" << endl;
	}
	return 0;
}
