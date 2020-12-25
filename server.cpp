#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "log.h"

int main()
{
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;  //Address Family ipv4
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip
    serv_addr.sin_port = htons(4000); //Host to Network short
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    cout << "==bind now==" << endl;
    cout << "ip: " << inet_ntoa(serv_addr.sin_addr) << endl;
    cout << "port: " << ntohs(serv_addr.sin_port) << endl;


    cout << "==Now listen : " << TimeNow() << "==" << endl;
    listen(serv_sock, 20);

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    char str[] = "hello world";
    int clnt_sock;
    while(strcmp(str, "end") != 0)
    {
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        read(clnt_sock, str, sizeof(str));
        SEE("%s", str);
        close(clnt_sock);
    }

    close(serv_sock);
    SEE("SERVER-OVER!");

    return 0;
}