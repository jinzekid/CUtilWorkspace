//
//  去除字符串前后的空格.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char *trimStrSpace(const char * in/*in*/ , char ** out/*out*/) {
  
  int ret = 0;
  if (in == NULL) {
    ret = -1;
    return NULL;
  }
  
  size_t len = strlen(in);
  char * frontPtr = in;
  char * trailPtr = (in + len-1);
  char * tmpPtr = NULL;
  int i = 0, j = 0;
  
  while(*frontPtr == ' ') {
    frontPtr++;
    i++;
  }
  
  while(*trailPtr == ' ') {
    trailPtr--;
    j++;
  }
  
  char *retStr = (char *)malloc(sizeof(char) * (len - (i + j)) + 1);
  retStr = strncpy(retStr, frontPtr, len - (i + j));
  if (retStr == NULL) {
    return NULL;
  }
  
  *out = retStr;
  return retStr;
}


char *trimStrSpace2(const char * in/*in*/ , char * out/*out*/) {
  
  int ret = 0;
  if (in == NULL) {
    ret = -1;
    return NULL;
  }
  
  size_t len = strlen(in);
  char * frontPtr = in;
  char * trailPtr = (in + len-1);
  int i = 0, j = 0;
  
  while(*frontPtr == ' ') {
    frontPtr++;
    i++;
  }
  
  while(*trailPtr == ' ') {
    trailPtr--;
    j++;
  }

  strncpy(out, frontPtr, len - (i + j));
  return out;
}

//通过二级指针释放内存
int freeMem_1(char ** in) {
  int ret = 0;
  if (in == NULL) {
    ret = -1;
    return ret;
  }
  
  char *tmp = NULL;
  tmp = *in;
//  printf("in address:%p\n", in);
//  printf("*in address:%p\n", *in);
//  printf("**in address:%c\n", *(*in+2));
  if (tmp != NULL) {
    free(tmp);
  }
  
  *in = NULL;
  return ret;
}

//这样也可以，但是不能把实参修改成null
int freeMem_2(char * in) {
  int ret = 0;
  if (in == NULL) {
    ret = -1;
    return ret;
  }
  
  char * tmp = in;
  printf("in address:%s\n", in);
  printf("&in address:%p\n", &in);
  if (tmp != NULL) {
    free(tmp);
  }
  return ret;
}

int main66(int argc, const char *argv[]) {
  
  char *p = " aabb ";
  char *r = NULL;
  trimStrSpace(p, &r);
  if (r == NULL) {
    printf("error:\n");
  }
  printf("before trim space string:%s\n", p);
  printf("after trim space string:%s\n", r);
  
  printf("r address:%p\n", &r);
  printf("r:%s\n", r);
  int ret = freeMem_2(r);
  if (ret == 0)
    printf("free mem is ok\n");
  
  printf("after trim space string:%s\n", r);
  
  /*
   char *p = " aabb ";
   char buf[1024];
   trimStrSpace2(p, buf);
   if (r == NULL) {
   printf("error:\n");
   }
   printf("after trim space string:%s\n", buf);
   */
  
  printf("hello...\n");
  return 0;
}
