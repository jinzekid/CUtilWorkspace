//
//  SocketClient.h
//  CTestProject
//
//  Created by JasonLu on 16/10/13.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#ifndef SocketClient_h
#define SocketClient_h

#include <stdio.h>

//-----第一套API接口-----

int cltSocketInit(void **handler /*out*/);
//发送报文
int cltSocketSend(void *handler /*in*/, char buf[] /*in*/, int length);
//接受报文
int cltSocketRev(void *handler /*in*/, char buf[] /*in*/, int *length);

int cltSocketDestory(void *handler /*int*/);

//-----第二套API接口-----
int cltSocketInit2(void **handler /*in*/);
//发送报文
int cltSocketSend2(void *handler, unsigned char *buf, int length);
//接受报文
int cltSocketRev2(void *handler, unsigned char **buf, int *length);

int cltSocketRev2_Free(unsigned char **buf /*in*/);

int cltSocketDestory2(void **handler);
#endif /* SocketClient_h */
