//
//  tcpClient.c
//  test
//
//  Created by 张宝坤 on 16/10/15.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include "tcpClient.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void tcpClient_error(int socketFD, const char* errorDesc){
    printf("tcpClient_error errorDesc:%s\n", errorDesc);
    if(socketFD != -1){
        close(socketFD);
    }
}

void tcpClient_connect(const char* hostname, unsigned short port){
    
    int socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketFD == -1){
        tcpClient_error(socketFD,"socket create error");
        return;
    }
    struct hostent *host;
    host = gethostbyname(hostname);
    if (!host){
        tcpClient_error(socketFD,"host error");
        return;
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr = *((struct in_addr*)host->h_addr);
    if(connect(socketFD, (struct sockaddr *)&sa, sizeof(struct sockaddr_in)) == -1){
        tcpClient_error(socketFD,"socket connect error");
        return;
    }
    char buf[2048];
    ssize_t ret = recv(socketFD, buf,sizeof(buf),0);
    while(ret==sizeof(buf)){
        buf[ret] = '\0';
        printf("tcpClient_connect recv:%s\n", buf);
        ret = recv(socketFD, buf,sizeof(buf),0);
    }
    tcpClient_close(socketFD);
}

void tcpClient_close(int socketFD){
    if(socketFD != -1){
        close(socketFD);
        socketFD = -1;
    }
}




