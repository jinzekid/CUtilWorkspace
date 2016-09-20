//
//  指针测试.c
//  CTestProject
//
//  Created by JasonLu on 16/9/20.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>

void onePrt(int *p) {
  int num = 500;
  p = &num;
  printf("p==%p,*p==%d\n", p, *p);
}

void twoPrt(int **p) { **p = 200; }

int main(int argc, const char *argv[]) {

  int i = 100;
  int *p = &i;
  *p = 200;
  int *twoP = NULL;

  onePrt(p);
  printf("after onePrt p==%p,*p==%d,i==%d\n", p, *p, i);
  onePrt(twoP);
  printf("after twoPrt p==%p,*p==%d,i==%d\n", p, *p, i);
  ;
  printf("hello...\n");
  return 0;
}