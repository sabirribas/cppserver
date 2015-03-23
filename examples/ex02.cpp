#define DEBUG true

#include <cstdio>
#include <cstdlib>
using namespace std;
#include "../cppserver.h"

class Echo : public RPCProc
{
public:
	Echo():RPCProc(){};
	virtual string run(Json::Value & params)
	{
		/* reading query from parameters */
		string query(params.get("query","").asString());
		cout << "Query: '" << query << "'" << endl;
		/* filling results */
		return "{\"result\":\"" + query + "\"}";
	};
	virtual ~Echo(){};
};

int main()
{
	printf("Testing cppserver\n");

	RPCServerTCP server(5001);
	server.addmethod("test",new RPCProc());
	server.addmethod("echo",new Echo());
	server.init();

	printf("\nSuccess!\n");
	return 0;
}
