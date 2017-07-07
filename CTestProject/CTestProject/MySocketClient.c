//
//  MySocketClient.c
//  CTestProject
//
//  Created by JasonLu on 16/10/14.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cltSocketInit(void **handler) { return 0; }
//发送报文
int cltSocketSend(void *handler, char buf[], int length) { return 0; }
//接受报文
int cltSocketRev(void *handler, char buf[], int *length) { return 0; }

int main111(int argc, const char *argv[]) {
  int ret = 0;
  void *handler = NULL;

  char buf[128];
  int buflen = 3;

  char outbuf[128];
  int outbuflen = 3;
  strcpy(buf, "aaabbbccc");

  ret = cltSocketInit(&handler);
  if (ret != 0) {
    printf("func cltSocketInit err:%d\n", ret);
    return ret;
  }

  //发送报文
  ret = cltSocketSend(handler, buf, buflen);
  if (ret != 0) {
    printf("func cltSocketSend err:%d\n", ret);
    return ret;
  }
  //接受报文
  ret = cltSocketRev(handler, buf, &outbuflen);
  if (ret != 0) {
    printf("func cltSocketRev err:%d\n", ret);
    return ret;
  }

  printf("hello...\n");
  return 0;
}

int main001(int argc, const char *argv[]) {
  int ret = 0;
  void *handler = NULL;

  char buf[128];
  int buflen = 3;

  char *pout = NULL;
  int poutlen = 0;
  strcpy(buf, "aaabbbccc");

  //  ret = cltSocketInit2(&handler);
  //  if (ret != 0) {
  //    printf("func cltSocketInit err:%d\n", ret);
  //    return ret;
  //  }
  //
  //  //发送报文
  //  ret = cltSocketSend2(handler, buf, buflen);
  //  if (ret != 0) {
  //    printf("func cltSocketSend err:%d\n", ret);
  //    return ret;
  //  }
  //  //接受报文
  //  ret = cltSocketRev2(handler, &pout, &poutlen);
  //  if (ret != 0) {
  //    printf("func cltSocketRev err:%d\n", ret);
  //    return ret;
  //  }
  //
  //  ret = cltSocketRev2_Free(&pout /*in*/);

  printf("hello...\n");
  return 0;
}