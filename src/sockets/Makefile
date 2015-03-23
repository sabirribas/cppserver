# Makefile for the socket programming example
#

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o
consult_server_objects = ServerSocket.o Socket.o consult_server.o


all : simple_server simple_client consult_server

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)


simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects)


consult_server: $(consult_server_objects)
	g++ -o consult_server $(consult_server_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp
consult_server:	consult_server.cpp

clean:
	rm -f *.o simple_server simple_client consult_server
