//
//  tcpClient.h
//  test
//
//  Created by 张宝坤 on 16/10/15.
//  Copyright © 2016年 张宝坤. All rights reserved.
//

#ifndef tcpClient_h
#define tcpClient_h

void tcpClient_connect(const char* hostname, unsigned short port);

void tcpClient_error(int socketFD, const char* errorDesc);

void tcpClient_close(int socketFD);

#endif /* tcpClient_h */
