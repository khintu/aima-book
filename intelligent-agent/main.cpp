#include <agent_defs.h>

extern "C" {
	int insert_in_main_algolib_unittestsuit(int argc, char* argv[]);
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
}

int main(int argc, char* argv[])
{
	try {
		insert_in_main_router_unittestsuit(argc, argv);
	}
	catch (AI::Exception) {
		cout << "Error occured, shutting down\n";
	}
	return 0;
}