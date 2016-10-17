//
//  tcpServer.h
//  test
//
//  Created by 张宝坤 on 16/10/15.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef tcpServer_h
#define tcpServer_h

void tcpServer_socket(unsigned short port);

void tcpServer_error(int socketFD, const char* errorDesc);

void tcpServer_close(int socketFD);

#endif /* tcpServer_h */
