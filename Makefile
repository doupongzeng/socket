build : server client  log.h

r : server
	#启动服务器
	./server

server : server.cpp 
	#生成服务器
	g++ -o server server.cpp

client : client.cpp
	#生成客户端
	g++ -o client client.cpp

clean : 
	#清除
	rm server client