/*
 * examples.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: sabir
 */

#include <cstdio>
#include <cstdlib>
using namespace std;
#include "../cppserver.h"

class EchoMethod : public Method
{
public:
	EchoMethod():Method(){};
	virtual Json::Value run(Json::Value & params)
	{
		Json::Value result;
		result["echo"] = params.get("query","").asString();
		result["list"] = Json::arrayValue;
		result["list"].append(1);
		result["list"].append(2);
		result["dict"] = Json::Value();
		result["dict"]["key"] = "value";
		return result;
	};
	virtual ~EchoMethod(){};
};

int main()
{
	printf("Testing cppserver\n");

	RPCServerTCP server(5001);
	server.addmethod("test",new Method());
	server.addmethod("echo",new EchoMethod());
	server.init();

	printf("\nSuccess!\n");
	return 0;
}
