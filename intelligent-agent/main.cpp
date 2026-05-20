#include <agent_defs.h>

extern "C" {
	int insert_in_main_algolib_unittestsuit(int argc, char* argv[]);
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
}

using namespace AI;

int SimpleSearchingAgent()
{
	struct WLList* inetList;

	try {
		CAbstractFactory* factory;
		//CSimpleSearching* agent1, * agent2;
		CThrdBase* threadObj[4];

		inetList = initializeInternetMap();
		factory = new CThreadFactory();

		threadObj[0] = factory->CreateThreadObj(new CVacuumWorld(inetList, 1, 7));
		threadObj[1] = factory->CreateThreadObj(new CVacuumWorld(inetList, 3, 7));
		//threadObj[2] = factory->CreateThreadObj(agent);
		//threadObj[3] = factory->CreateThreadObj(agent);


		threadObj[0]->waitToExit(); delete threadObj[0];
		threadObj[1]->waitToExit(); delete threadObj[1];
		//threadObj[2]->waitToExit(); delete threadObj[2];
		//threadObj[3]->waitToExit(); delete threadObj[3];

		delete factory;
	}
	catch (AI::Exception& e) {
		cout << e << endl;
	}
	WDeleteList(inetList);
	return 0;
}

int main(int argc, char* argv[])
{
	//insert_in_main_router_unittestsuit(argc, argv);
	try {
		SimpleSearchingAgent();
	}
	catch (...) {
		cout << "Unexpected error! shutting down" << endl;
	}
	return 0;
}
