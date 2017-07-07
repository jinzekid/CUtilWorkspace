//
//  other_03.c
//  CTestProject
//
//  Created by JasonLu on 2017/5/19.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
static int UpdateCounter(char* b, int c, int a1);

const int arr[4] = {0,1,2,3};

int main_other_03() {
  char* b = NULL;
  int c = 128;
  
  b = (char*)malloc(1024*sizeof(char));
  
  UpdateCounter(b, c, arr[1]);
  
  free(b);
  printf("c=%d,a[1]=%d\n",c, arr[1]);
  
  return EXIT_SUCCESS;
}

static int UpdateCounter(char* b, int c, int a1) {
  int d = 0;
  const int e[4] = {64, 96, 128, 160};
  if (b[c++] > e[a1++]) {
    d++;
  }
  return d;
}
/*
int x = 1;
int y = 2;
void TestFunction(int* arr, int x, int y, double* sum);

int main(){
  int* list_buf;
  double total[4] = {0.0};
  
  list_buf = (int*)malloc(1024 * sizeof(int));
  TestFunction(list_buf, x, y, total);
  
  free(list_buf);
  
  return EXIT_SUCCESS;
}

void TestFunction(int* arr, int x, int y, double* sum) {
  int val = 0;
  
  if ((x + y) < 1024) {
    val = arr[x + y];
  }
  sum[val & 3] += val;
}
*/
