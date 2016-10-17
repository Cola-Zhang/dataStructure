//
//  tcpServer.c
//  test
//
//  Created by 张宝坤 on 16/10/15.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#include <stdio.h>
#include "tcpServer.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* tcpServer_test(void* arg){
    int socketFD = *(int *)arg;
    char str[2048];
    sprintf(str, "socketFD->%d HelloClient", socketFD);
    printf("tcpServer_test %s\n", str);
    send(socketFD, str, sizeof(str), 0);
    tcpServer_close(socketFD);
    return (void *)0;
}


void tcpServer_socket(unsigned short port){
    int socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketFD == -1){
        tcpServer_error(socketFD,"socket create error");
        return;
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(socketFD, (const struct sockaddr *)&sa, sizeof(struct sockaddr_in)) == -1){
        tcpServer_error(socketFD,"socket bind error");
        return;
    }
    if(listen(socketFD, 10)==-1){
        tcpServer_error(socketFD,"socket listen error");
        return;
    }
    
    while(1){
        int newSocketFD = accept(socketFD, NULL, NULL);
        pthread_t tid1;
        pthread_create(&tid1, NULL, tcpServer_test, &newSocketFD);
    }
    return;
}

void tcpServer_error(int socketFD, const char* errorDesc){
    printf("tcpServer_error errorDesc:%s\n", errorDesc);
    tcpServer_close(socketFD);
}

void tcpServer_close(int socketFD){
    if(socketFD != -1){
        close(socketFD);
        socketFD = -1;
    }
}
