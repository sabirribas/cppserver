/*
 * RPCServerTCP.h
 *
 *  Created on: Mar 24, 2013
 *      Author: sabir
 */

#ifndef RPCSERVERTCP_H_
#define RPCSERVERTCP_H_

#include "RPCServer.hpp"

#include "sockets/ServerSocket.h"
#include "sockets/SocketException.h"

#include <sstream>

class RPCServerTCP : public RPCServer
{
private:
	int port;
	ServerSocket * server;
public:
	RPCServerTCP(int port):port(port),server(NULL){};
	virtual ~RPCServerTCP(){};
	virtual void init()
	{
		std::cout << "running....\n";

		try
		{
			// Create the socket
			server = new ServerSocket(port);

			while ( true )
			{
				serve();
			}
		}
		catch ( SocketException& e )
		{
			std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
		}
	}
	virtual void serve()
	{
		ServerSocket new_sock;
		if (server != NULL) server->accept ( new_sock );
		else {cerr << "ERROR: server == NULL"; exit(1);};

		try
		{
			// getting query
			std::string msg;
			new_sock >> msg;

			cout << msg << endl;

			/* reading json from message {"method":"name","params":{}} */

			Json::Value root;   // will contains the root value after parsing.
			Json::Reader reader;
			bool parsingSuccessful = reader.parse( msg, root );
			if ( !parsingSuccessful )
			{
			    // report to the user the failure and their locations in the document.
			    std::cout  << "Failed to parse configuration\n"
			               << reader.getFormattedErrorMessages();
			    return;
			}

			std::string method = root.get("method", "test" ).asString();
			Json::Value params = root.get("params", 0);

			// sending result
			new_sock << run(method,params);
		}
		catch ( SocketException& ) {}

	}
	virtual void finish(){}
	virtual string run(string method,Json::Value & params)
	{
		map<string,RPCProc*>::iterator it = methods.find(method);
		if (it == methods.end()) {cout << "ERROR: wrong method" << endl; exit(1);}
		RPCProc * proc = methods[method];
		return proc->run(params);
	}
};

#endif /* RPCSERVERTCP_H_ */
