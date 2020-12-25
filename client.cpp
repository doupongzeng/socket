#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "log.h"

int main()
{
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(4000);

    char buffer[10];
    while(strcmp(buffer, "end") != 0)
    {
        int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

        scanf("%9s", buffer);
        write(sock, buffer, sizeof(buffer)-1);
        close(sock);
    }

    printf("CLIENT-OVER!!!\n");

    return 0;
}