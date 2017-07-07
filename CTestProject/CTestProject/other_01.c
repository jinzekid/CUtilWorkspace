//
//  other_01.c
//  CTestProject
//
//  Created by JasonLu on 2017/5/3.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>

void fun(int m, int a[10]) {
  int i;
  for (i = 0; i < 10; i++) {
    a[i] = 0;
  }
  
  while (m > 0) {
    i = m % 10;
    a[i]++;
    m = m /10;
  }
}

int main_other_01() {
  int m, a[10], i;
  printf("请输入一个整数:");
  scanf("%d", &m);
  fun(m, a);
  for (i = 0; i<10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
