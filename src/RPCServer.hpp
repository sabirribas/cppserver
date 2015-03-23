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

class Method
{
public:
	Method(){}
	virtual Json::Value run(Json::Value &params)
	{
		return Json::Value("Not implemented yet!");
	}
	virtual ~Method(){}
};

class RPCServer
{
protected:
	map<string,Method* > methods;
public:
	RPCServer(){}
	virtual ~RPCServer(){}
	virtual void init(){}
	virtual void serve(){}
	virtual void finish(){}
	virtual Json::Value run(string method,Json::Value & params)
	{
		return Json::Value();
	}
	virtual void addmethod(string methodname,Method * method)
	{
		methods[methodname] = method;
	}
};

#endif /* RPCSERVER_H_ */
