//
//  字符串基本操作.c
//  CTestProject
//
//  Created by JasonLu on 16/9/8.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void stringLen(char *pStr) {
  int i = 0;
  while (*pStr++) {
    i++;
  }
  printf("i===%d\n", i);
  ;
}

//字符串的逆序
void revserString(char *from, char *to) {
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
  stringLen(to);
}

//计算数组的字符串的长度和sizeof长度
void cntStrLen() {
  int size = 0;
  char buf3[] = "abcd";
  unsigned long len = strlen(buf3);
  printf("buf3 length:%lu \n", len); // 4
  size = sizeof(buf3);               //
  printf("buf3 size:%d \n", size);   // 5
}

//去除字符串前后的空格
char *trimSpace(char *inBuf, char **outBuf) {
  //    if (inBuf == NULL) {
  //        return -1;
  //    }

  char *retBuf = (char *)malloc(1024);
  char *frontInBuf = inBuf;
  char *trailInBuf = frontInBuf + strlen(inBuf) - 1;

  while (*frontInBuf == ' ') {
    frontInBuf++;
  }

  while (*(trailInBuf - 1) == ' ') {
    trailInBuf--;
  }

  char *tmpRetBuf = retBuf;
  while (frontInBuf != trailInBuf) {
    *retBuf++ = *frontInBuf++;
  }
  *retBuf = '\0';
  *outBuf = tmpRetBuf;
  return tmpRetBuf;
}

//指针做输出，被调用函数分配内存－－OK
//指针做输入，主调用函数分配内存
//求文件中国年的两端话的长度
int getMem(char **p1, int *len1, char **p2, int *len2) {
  char *tmp1 = NULL;
  tmp1 = (char *)malloc(100);
  if (tmp1 == NULL)
    return -1;

  strcpy(tmp1, "abcdefg");
  *len1 = strlen(tmp1);

  *p1 = tmp1;

  char *tmp2 = NULL;
  tmp2 = (char *)malloc(100);
  if (tmp2 == NULL)
    return -1;

  strcpy(tmp2, "111222333");
  *len2 = strlen(tmp2);

  *p2 = tmp2;

  return 0;
}

//释放内存
int getMem_Free(char **p1) {
  char *tmp = NULL;
  if (p1 == NULL)
    return -1;

  tmp = *p1;
  free(tmp);  //释放完指针变量所指向的内存空间
  *p1 = NULL; //把实参修改成null

  return 0;
}

//这样也可以，但是不能把实参修改成null
int getMem_Free0(char *p1) {
  if (p1 == NULL)
    return -1;

  free(p1);
  return 0;
}

//分配内存
// void getMem_3(char ***p) {
//  char **tmp = NULL;
//  tmp = (char *)malloc(sizeof(char *));
//}

int cntStrWithSign(char *str, char *sign) {
  int cnt = 0;
  while (*str) {
    if (*str == ',') {
      cnt++;
    }
    str++;
  }
  return cnt + 1;
}

int create1PStr(char **p, char *str, int num) {
  char *pNewStr = NULL;
  pNewStr = (char *)malloc(sizeof(char) * (num));
  if (pNewStr == NULL)
    return -1;
  //拷贝字符串
  strncpy(pNewStr, str, num - 1);
  *p = pNewStr;
  return 0;
}

int create2PStr(char *str, int num, char **newP) {
  char *pNewStr = NULL;
  pNewStr = (char *)malloc(sizeof(char) * (num));
  if (pNewStr == NULL)
    return -1;
  //拷贝字符串
  strncpy(pNewStr, str, num - 1);
  *newP = pNewStr;
  return 0;
}

//创建对应字符串
int createStr(char ***p, char *str, int num) {
  //手工二维内存
  char **p3 = NULL;
  char *tmp = NULL;
  char *tmp2 = NULL;
  int index = 0;
  int cnt3 = 0;

  //分配num个字符串指针
  p3 = (char **)malloc(num * sizeof(char *));

  tmp = str;
  tmp2 = str;
  while (*tmp) {
    if (*tmp == ',') {
      //简化版
      create2PStr(tmp2, (cnt3 + 1), &(p3[index]));
      tmp2 += (cnt3 + 1);
      cnt3 = 0;
      index++;
    } else {
      cnt3++;
    }
    tmp++;
  }

  // 复杂版
  // 1.创建内存空间
  char *pNewStr = NULL;
  create1PStr(&pNewStr, tmp2, (cnt3 + 1));
  // 2.创建完后需要保存
  p3[index] = pNewStr;
  // 3.移动需要下一次拷贝的指针地址
  tmp2 += (cnt3 + 1);
  // 4.计数清零
  cnt3 = 0;
  // 5.指向下一个保存地址
  index++;
  printf("tmp==%s\n", pNewStr);
  ;

  *p = p3;
  return 0;
}

int main(int argc, const char *argv[]) {

  // insert code here...
  //    char buf[] = "a1234567";
  //    char * to = (char *)malloc(sizeof(buf));
  //    revserString(buf, to);
  //    printf("to===%s\n", to);

  //    char buf[] = " adbdfd ";
  //    char * retBuf = NULL;
  //    char * retBuf2 = NULL;
  //    printf("before trim space==%s\n", buf);
  //    printf("length==%ld\n", strlen(buf));
  //    printf("sizeof==%ld\n", sizeof(buf));
  //    retBuf = trimSpace(buf, &retBuf2);
  //    printf("after trim space==%s\n", retBuf);
  //    printf("after trim space==%s\n", retBuf2);
  //    printf("length==%ld\n", strlen(retBuf));
  //    printf("sizeof==%ld\n", sizeof(retBuf));

  //  char *p1 = NULL;
  //  int len1 = 0;
  //
  //  char *p2 = NULL;
  //  int len2 = 0;
  //
  //  int ret = 0;
  //  ret = getMem(&p1, &len1, &p2, &len2);
  //
  //  printf("p1==%s\n", p1);
  //  printf("p2==%s\n", p2);
  //
  //  getMem_Free(&p1);
  //  getMem_Free0(
  //      p2);
  //      //在被调用函数中，把p2所指向的内存给释放掉，但是实参p1不能被修改成null,有野指针现象
  //
  //  printf("p1==%s\n", p1);
  //  printf("p2==%s\n", p2);
  //
  //  char myArray[10][30] = {"aaaa", "bbbb", "ccccc"};
  //  {
  //    // myArray: 编译器只会关心，有10行，每行30列。。。
  //    //就是为了解决:myArray+1,
  //    int len1 = sizeof(myArray);
  //    int len2 = sizeof(myArray[0]);
  //    int size = len1 / len2;
  //    printf("size:%d,len2=%d\n", size, len2);
  //    ;
  //  }

  {
    int i = 0;

    //指针数组
    char *p1[] = {"123", "456", "789"};

    //二维数组
    char p2[3][4] = {"123", "456", "789"};

    //手工二维内存
    char **p3 = (char **)malloc(3 * sizeof(char *)); // int array[3];

    for (i = 0; i < 3; i++) {
      p3[i] = (char *)malloc(10 * sizeof(char)); // char buf[10]

      sprintf(p3[i], "%d%d%d", i, i, i);
    }
  }

  char *pStr = "abcdef,accccd,eeeee,dddd,33333";
  char **p = NULL;
  char *tmp = NULL;
  char *sign = ",";
  printf("str==%s\n", pStr);

  //首先需要判断出有多少,

  tmp = pStr;
  int cnt = cntStrWithSign(pStr, sign);
  printf("cnt==%d\n", cnt);

  createStr(&p, pStr, cnt);

  for (int i = 0; i < cnt; i++) {
    printf("p[%d]==%s\n", i, p[i]);
  }

  printf("hello...\n");
  return 0;
}
