//
//  字符串数组的拼接和排序.c
//  CTestProject
//
//  Created by JasonLu on 16/9/23.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int sort(char **p1, int num1, char *p2[], int num2, char ***p3, int *num3) {

  int i = 0, j = 0, tmpNum = 0;
  char **tmpP = NULL;
  char *tp = NULL;
  size_t strlength = 0;
  tmpP =
      (char **)malloc((num1 + num2) * sizeof(char *)); //分配num1+num2个一维指针
  //  memset(*tmpP , 0 , num1+num2);

  if (p1 == NULL || p2 == NULL) {
    return -1;
  }

  for (i = 0; i < num1; i++) {
    strlength = strlen(p1[i]) + 1;
    tp = (char *)malloc(sizeof(char) * strlength);
    if (tp == NULL) {
      return -2;
    }
    tmpP[i] = strcpy(tp, p1[i]);
  }

  for (j = 0; j < num2; j++, i++) {
    strlength = strlen(*(p2+j)) + 1;
    tp = (char *)malloc(sizeof(char) * strlength);
    if (tp == NULL) {
      return -2;
    }
    tmpP[i] = strcpy(tp, *(p2+j));
  }

  //交换指针法
  char *tmpValue = NULL;
  tmpNum = num1 + num2;
  for (i = 0; i < tmpNum; i++) {
    for (j = i; j < tmpNum; j++) {
      if (strcmp(tmpP[i], tmpP[j]) > 0) {
        tmpValue = tmpP[i];
        tmpP[i] = tmpP[j];
        tmpP[j] = tmpValue;
      }
    }
  }

  //  //内容赋值法
  //  char *buf[100] = {0};
  //  tmpNum = num1 + num2;
  //  for (i = 0; i < tmpNum; i++) {
  //    for (j = i; j < tmpNum; j++) {
  //      if (strcmp(tmpP[i], tmpP[j]) > 0) {
  //        strcpy(buf, tmpP[i]);
  //        strcpy(tmpP[i], tmpP[j]);
  //        strcpy(tmpP[j], buf);
  //      }
  //    }
  //  }

  *p3 = tmpP;
  *num3 = tmpNum;
  return 0;
}

void printPrt(char ***p, int num) {
  int i = 0;
  char **tmpP = NULL;
  tmpP = *p;
  for (i = 0; i < num; i++) {
    printf("%s ", tmpP[i]);
  }
  printf("\n");
}

int main44(int argc, const char *argv[]) {
  
  char *p1[] = {"aaa", "ddd", "bbb"};
  char *p2[30] = {"ppp", "111", "333", "222"};
  char **p3 = NULL;
  int num3 = 0;
  int num1 = sizeof(p1) / sizeof(*p1);
  int num2 = 4;
  sort(p1, num1, p2, num2, &p3, &num3);
  printPrt(&p3, num3);
  
  printf("hello...\n");
  return 0;
}
