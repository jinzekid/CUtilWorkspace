//
//  01.c
//  CTestProject
//
//  Created by JasonLu on 2017/4/24.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20       /*能够处理的最大列号*/
#define MAX_INPUT 1000    /*每个输入行的最大长度*/

void printArray(int* output, int length);

int read_colum_numbers(int colums[], int max);
void rearrange(char* output, char const *input, int n_colums, int const columns[]);


void printArray(int* output, int length) {
  printf("=====Print Array=====\n");
  for (int i = 0; i < length; i++) {
    printf("%d:%d ", i , *(output+i));
  }
  printf("\n=====Print Array=====\n");
}

int main_01() {
  
  int n_columns;
  int columns[MAX_COLS];
  char input[MAX_INPUT];
  char output[MAX_INPUT];

  /*
  int a = 0;
  int b = 0;
  char str[MAX_INPUT];
  scanf("%d %d %s", &a, &b, str);
  printf("a=%d,b=%d,str=%s\n", a, b, str);
  */
  
  
  //读取该串列标号
  n_columns = read_colum_numbers(columns, MAX_COLS);
  printf("n_columns=%d\n", n_columns);
  printArray(columns, n_columns);
  
//  读取，处理和打印剩余的输入行
//  gets函数从标准输入读取一行文本并存储保存在input数组中
  while (gets(input) != NULL) {
    printf("original input: %s\n", input);
//    printf("string length=%d\n", sizeof(input));
    rearrange(output, input, n_columns, columns);
    printf("Rearranged line: %s\n", output);
  }
  
  
  printf("Hello world!\n");
  return EXIT_SUCCESS;
}

/*
 读取列标号，如果超出规定范围则不予理会
 */
int read_colum_numbers(int colums[], int max) {
  int num = 0;
  int ch = 0;
//  取得列标号，如果所读取的数小于0则停止
  while (num < max &&
         scanf("%d", &colums[num]) == 1 &&
         colums[num] >= 0) {
    num++;
  }
  
//  确认已尽读取的标号为偶数个，因为它们是以成对的形式出现的
  if (num%2 != 0) {
    puts("Last column number is not paired.");
    exit(EXIT_FAILURE);
  }
  
  while ((ch = getchar()) != EOF &&
         ch != '\n') {
    printf("ch=%d\n", ch);
  }
  return num;
}

void rearrange(char* output, char const *input, int n_colums, int const columns[]) {
  int col;
  int output_col;
  int len;
  
  len = strlen(input);
  output_col = 0;
  
//  处理每对列表号
  for (col = 0; col < n_colums; col += 2) {
    int nchars = columns[col+1] - columns[col] + 1;
    
    //01_5
    if ((columns[col] >= len && columns[col] < 0) ||
        output_col == MAX_INPUT -1){
      break;
    }
    
    if (output_col + nchars > MAX_INPUT -1) {
      nchars = MAX_INPUT - output_col - 1;
    }
    
//    strncpy(output + output_col, input + columns[col], nchars);
    //01_6
    strcpy(output + output_col, input + columns[col]);
    output_col += nchars;
  }
  
  
  output[output_col] = '\0';
}
