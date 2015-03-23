/*
 * RPCServer.h
 *
 *  Created on: Mar 24, 2013
 *      Author: sabir
 */

#ifndef RPCSERVER_H_
#define RPCSERVER_H_

// sudo apt-get install libjsoncpp-dev libjsoncpp0 # Ubuntu
#include <json/json.h>

class RPCProc
{
public:
	RPCProc(){};
	virtual string run(Json::Value & params){return "Not implemented yet!";};
	virtual ~RPCProc(){};
};

class RPCServer
{
protected:
	map<string,RPCProc* > methods;
public:
	RPCServer(){};
	virtual ~RPCServer(){};
	virtual void init(){}
	virtual void serve(){}
	virtual void finish(){}
	virtual string run(string method,Json::Value & params){return "";}
	virtual void addmethod(string methodname,RPCProc * method)
	{
		methods[methodname] = method;
	}
};

#endif /* RPCSERVER_H_ */
