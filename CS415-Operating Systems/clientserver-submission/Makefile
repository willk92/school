#
# File:   makefile
# Author: Adam.Lewis@athens.edu
# Purpose:
# Makefile for CS415 lab06.
#

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o

# Uncomment the following lines for the lab program
#server_objects = ServerSocket.o Socket.o server.o
#client_objects = ClientSocket.o Socket.o client.o

# Comment the following line and uncomment the next set of lines for the lab
all : simple_server simple_client
#all : simple_server simple_client server client
#server : $(server_objects)
#	g++ -o server $(server_objects)

#client : $(client_objects)
#	g++ -o client $(client_objects)

#server : server.cpp
#client : client.cpp

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)

simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects)

Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp

clean:
	rm -f *.o simple_server simple_client
