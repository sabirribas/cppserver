#define DEBUG true

#include <cstdio>
#include <cstdlib>
using namespace std;
#include "../cppserver.h"

int main()
{
	printf("Testing cppserver\n");

	RPCServerTCP server(5001);
	server.addmethod("test",new RPCProc());
	//server.addmethod("wp_consult",new WPConsult());
	server.init();

	printf("\nSuccess!\n");
	return 0;
}
