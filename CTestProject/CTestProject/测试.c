//
//  测试.c
//  CTestProject
//
//  Created by JasonLu on 16/10/10.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  char *itme;
  struct node *next;
} * NODEPTR;

typedef struct _advTeacher {
  char name[64];
  char *tile;
  char **pStuArray;
  int age;
} Teacher;

#pragma mark - 定义一对相互引用的结构体
//定义一对相互引用的结构体
//方法一
struct a {
  int age;
  struct b *oneB;
};

struct b {
  char name[64];
  struct a *oneA;
};

//方法二
struct aa;
struct bb;
typedef struct aa *aaPtr;
typedef struct bb *bbPtr;
struct aa {
  int age;
  bbPtr oneB;
};

struct bb {
  char name[64];
  aaPtr oneA;
};

#pragma mark - 复杂声明解读
// char *(*pfpc)();
//*(*pfpc)();//是一个char
//(*pfpc)(); //是一个 指向char的指针
//(*pfpc);  //是一个返回char型指针的函数
// pfpc      //是一个放回cahr型指针的函数指针

#pragma mark - 数组
void testArr() {
  int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
  for (int i = 0; i < 2; i++) {
    printf("&matrix[%d]=%p, sizeof(matrix[%d])=%lu\n", i, &matrix[i], i,
           sizeof(matrix[i]));
  }
}

void testArrToPtr() {
  int vector[5] = {1, 2, 3, 4, 5};
  int *p = NULL;
  p = vector;
  printf("p==%d,&p=%d,vector=%d,&vector=%d\n", p, &p, vector, &vector[0]);
}

int createArr(int **ptr, int *length) {
  int size = 5;
  int *pv = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < 5; i++) {
    pv[i] = i + 1;
  }
  *ptr = pv;
  *length = size;
  return 0;
}

void printArr(int *ptr, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d=%d\n", i + 1, *(ptr + i));
  }
}

void printArr2(int buf[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d=%d\n", i + 1, buf[i]);
  }
}

//多维数组传递
void printMArr(int buf[][5], int rows);
void printMArr2(int (*ptr)[5], int rows);
//适合打印连续的数组
void printMArr3(int *arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\n", *(arr + ((i * cols) + j)));
    }
  }
}
void printMArr4(int **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    int *tmp = *(arr + i);

    for (int j = 0; j < cols; j++) {
      printf("%d\n", *(tmp + j));
    }
  }
}
//适合打印不连续的数组
void printMArr5(int **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    int *tmp = arr[i];
    for (int j = 0; j < cols; j++) {
      printf("%d\n", tmp[j]);
    }
  }
}

//分配可能不连续的内存
void createMem(int ***matrix, int rows, int colums) {
  int val = 0;
  int **tmp = (int **)malloc(sizeof(int) * 2);
  for (int i = 0; i < rows; i++) {
    tmp[i] = (int *)malloc(sizeof(int) * colums);
    printf("i:%d tmp address:%p\n", i, &tmp[i]);
    for (int j = 0; j < colums; j++) {
      tmp[i][j] = val++; // i * rows + j;
      printf("%d,%d:%d,address=%p\n", i, j, tmp[i][j], &tmp[i][j]);
    }
  }
  printMArr4(tmp, 2, 3);

  //  *matrix = tmp;
}

int mainceshi(int argc, const char *argv[]) {

  //  int martix[2][3] = {{1, 2, 3}, {4, 5, 6}};
  //  printMArr3(&martix[0][0], 2, 3);
  //
  //  int **matrix = NULL;
  //  createMem(&matrix, 2, 3);
  //  printMArr3(&matrix[0][0], 2, 3);

  char buf[100] = "abcde";
  printf("sizeof(aa)=%ld\n",sizeof(buf));
  
  char *s = NULL;
  s = (char *)malloc(10 * sizeof(char));
  strcpy(s, "abc");
  printf("s value:%s\n", s);

  char **p = NULL;
  p = &s;
  free(*p);
  *p = NULL;
  printf("s value:%s\n", s);

  //  int ret = 0;
  //  void *handler = NULL;
  //
  //  char buf[128];
  //  int buflen = 3;
  //
  //  char outbuf[128];
  //  int outbuflen = 3;
  //  strcpy(buf, "aaabbbccc");
  //
  //  ret = cltSocketInit(&handler);
  //  if (ret != 0) {
  //    printf("func cltSocketInit err:%d\n", ret);
  //    return ret;
  //  }
  //
  //  //发送报文
  //  ret = cltSocketSend(handler, buf, buflen);
  //  if (ret != 0) {
  //    printf("func cltSocketSend err:%d\n", ret);
  //    return ret;
  //  }
  //  //接受报文
  //  ret = cltSocketRev(handler, buf, &outbuflen);
  //  if (ret != 0) {
  //    printf("func cltSocketRev err:%d\n", ret);
  //    return ret;
  //  }

  printf("hello...\n");
  return 0;
}
