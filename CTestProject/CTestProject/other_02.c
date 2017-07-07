//
//  other_02.c
//  CTestProject
//
//  Created by JasonLu on 2017/5/5.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char *ptr_to_char;
//正确声明了a，但是b却被声明了一个字符
#define d_ptr_to_char char *
d_ptr_to_char a, b;

//效果一样
int const ca;
const int cb;

int *pi;
int const *pci; //指向一个整型常量的指针
int * const cpi;//指向一个整型的常量指针
int const * const cpci;//指向常量的常量指针
enum Jar_Type {
  CUP = 8,
  PINT= 16,
  QUART = 32
};

//字符串的逆序
void revserStr(char *from, char *to) {
  int len = strlen(from);
  char *tmpFrom = from + len - 1;
  char *tmpTo = to;
  
  printf("from==%s\n", from);
  
  while (len >= 0) {
    *tmpTo++ = *tmpFrom--;
    len--;
  }
  tmpTo += '\0';
  
  printf("to==%s\n", to);
}

char* intToStr(int n) {
  char* s = malloc(sizeof(char *));
  char* ret = malloc(sizeof(char *));
  
  int cnt = 0;
  while (n > 0) {
    *s = n % 10 + '0';
    n /= 10;
    cnt++;
    s++;
  }
  
   s -= cnt;
  
  revserStr(s, ret);
  printf("%s\n", ret);
  
  return ret;
}

int str2IP(char s[]) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  
  sscanf(s, "%u.%u.%u.%u", &a, &b, &c, &d);
  
  int ip = 0;
  unsigned char* p = &ip;
  *p++ = a;
  *p++ = b;
  *p++ = c;
  *p   = d;
  
  unsigned char* p11 = &ip;
  printf("%u.%u.%u.%u\n", *p11,*(p11+1),*(p11+2),*(p11+3));
  
  return ip;
}

char* ip2Str(int ip) {
  unsigned char* p = &ip;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  
  a = *p++;
  b = *p++;
  c = *p++;
  d = *p;
  
  char* pa = intToStr(a);
  strcat(pa, ".");
  char* pb = intToStr(b);
  strcat(pa, pb);
  strcat(pa, ".");
  char* pc = intToStr(c);
  strcat(pa, pc);
  strcat(pa, ".");
  char* pd = intToStr(d);
  strcat(pa, pd);
  return pa;
}

struct aStr {
  char a;//1
  char c;//1
  signed b;//4
//  int d;//4
  long e;//8
};

int main_other_02() {
  
  printf("struct size %d\n", sizeof(char));
  printf("struct size %d\n", sizeof(signed));
  printf("struct size %d\n", sizeof(int));
  printf("struct size %d\n", sizeof(long));

  printf("struct size %d\n", sizeof(struct aStr));
  
  int i = 10;
  printf("%d, %d, %d\n", i--, ++i, i--);
  ;
  
  //注意赋值表达的意思
  char *message;
  message = "Hello world!";
  ptr_to_char a;
  
  
  int a2 = 255;
  unsigned char* p2 = &a2;
  printf("p2:%u\n", *p2);

  int aa = 0x12345679;
  char* pp = &aa;
  printf("%x\n", *(pp+1));
  ;
  printf("sizeof char:%d\n", sizeof(char));
  printf("sizeof int:%d\n", sizeof(int));

  char s[] = "192.168.1.252";
  int my_ip2Int = str2IP(s);
  char* mt_int2IP = ip2Str(my_ip2Int);
  printf("ip to int :%d\n", my_ip2Int);
  printf("int to ip :%s\n", mt_int2IP);
  

  return EXIT_SUCCESS;
}




