#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
int main ( int argc, char* argv[] )
{
	std::cout << "running....\n";

	try
	{
		// Create the socket
		ServerSocket server ( 30000 );

		while ( true )
		{

			ServerSocket new_sock;
			server.accept ( new_sock );

			try
			{
				//while ( true )
				{
					// getting query
					std::string query;
					new_sock >> query;

					// sending result
					new_sock << "1.000\thttp://" << query << "0.com\n";
					new_sock << "0.900\thttp://" << query << "1.com\n";
					new_sock << "0.700\thttp://" << query << "2.com\n";
					new_sock << "0.500\thttp://" << query << "3.com\n";
				}
			}
			catch ( SocketException& ) {}

		}
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}
