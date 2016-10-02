//
//  指针测试.c
//  CTestProject
//
//  Created by JasonLu on 16/9/20.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>

void onePtr(int *p) {
  int num = 500;
  p = &num;
  printf("p==%p,*p==%d\n", p, *p);
}

void twoPtr(int **p) {
  **p = 400;
}

int main33(int argc, const char *argv[]) {
  int i = 100;
  int *p = &i;
  *p = 200;
  onePtr(p);
  printf("after onePrt p==%p,*p==%d,i==%d\n", p, *p, i);
  twoPtr(&p);
  printf("after twoPrt p==%p,*p==%d,i==%d\n", &p, *p, i);
  printf("hello...\n");
  return 0;
}
