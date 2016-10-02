//
//  字符串和数组的属性.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>

int main00(int argc, const char *argv[]) {
  
  // 1 用字符串来初始化数组
  //char buf2[] = {'a', 'b', 'c', 'd', '\0'};
  // 2 字符串常量初始化一个字符数组
  char buf3[] = {"abcd"}; //结论：会补充零
  char buf4[] = "abcde";
  char buf5[100] = "abcde";
  char *p = "abc";
  
  printf(" strlen==%lu\n", strlen(p)); // 3 , 字符串的长度
  printf(" sizeof==%lu\n", sizeof(p)); // 8 , 指针的长度
  
  printf(" strlen(buf5) :%lu \n", strlen(buf5));
  printf(" sizeof(buf5) :%lu \n", sizeof(buf5));
  
  printf(" strlen(buf4) :%lu \n", strlen(buf4));
  printf(" sizeof(buf4) :%lu \n", sizeof(buf4));
  
  printf(" strlen(buf3) :%lu \n", strlen(buf3));
  printf(" sizeof(buf3) :%lu \n", sizeof(buf3));
  printf("hello...\n");
  
  printf("hello...\n");
  return 0;
}
