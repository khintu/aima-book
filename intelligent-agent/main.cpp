#include <agent_defs.h>

extern "C" {
	int insert_in_main_algolib_unittestsuit(int argc, char* argv[]);
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
}

int main(int argc, char* argv[])
{
	//insert_in_main_router_unittestsuit(argc, argv);
	pthread_t thread;
	try {
		
		

	}
	catch (AI::Exception e) {
		cout << e << endl;
	}
	catch (...) {
		cout << "Unexpected error! shutting down" << endl;
	}
	return 0;
}