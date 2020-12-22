build : server client log.h

r : server client
	./server

s : server.cpp 
	g++ -o server.cpp server

c : client.cpp
	g++ -o client.cpp client

clean : server client
	rm server client