#include <agent_defs.h>

extern "C" {
#include <router_defs.h>
	int insert_in_main_router_unittestsuit(int argc, char* argv[]);
};

int main(int argc, char* argv[])
{
	try {
		//insert_in_main_router_unittestsuit(argc, argv);
	}
	catch (AIException) {
		cout << "Error occured, shutting down\n";
	}
	return 0;
}