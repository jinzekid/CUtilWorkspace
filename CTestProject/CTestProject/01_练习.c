//
//  01_练习.c
//  CTestProject
//
//  Created by JasonLu on 2017/4/30.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 1000

int main01(){
  printf("Hello world!\n");
  return 0;
}

int main02() {
  
  char* input = malloc(sizeof(char));
  int i = 1;
  int ret = 0;
  while ((ret = scanf("%s", input))) {
    printf("ret:%d %d: %s\n",ret, i, input);
    i++;
  }
  
  printf("Hello world!\n");
  return 0;
}

//01_2
int main_01_2() {
  int ch;
  int cnt = 0;
  int line = 0;
  
  char *input = malloc(sizeof(char *));
  char *output[MAX_INPUT];
  
  while ((ch=getchar()) != EOF) {
    if (ch == '\n') {
      output[line] = malloc(sizeof(char *));
      strcpy(output[line], (input-cnt));
      line++;
      cnt = 0;
      input = malloc(sizeof(char *));
    } else {
      *input++=ch;
      cnt++;
    }
  }
  
  for (int i=0; i<line; i++) {
    printf("%d:%s\n",i+1 ,output[i]);
  }
  
  printf("\n");
  return EXIT_SUCCESS;
}

//01_3
int checksum(char const *input);
int main_01_3(){
  
  //方法一
  printf("\n=====方法一=====\n");
  char* input = malloc(sizeof(char));
  while (gets(input) != NULL) {
    printf("original input: %s\n", input);
    unsigned char sum = checksum(input);
    printf("sum: %d\n", sum);
  }
  
  //方法二
  printf("\n=====方法二=====\n");
  int ch;
  unsigned char sum = -1;
  while ((ch=getchar()) != EOF) {
    if (ch == '\n') {
      break;
    }
    unsigned char c = toascii(ch);
    sum += c;
  }
  unsigned char c = toascii('\n');
  sum += c;
  printf("sum: %d\n", sum);

  return 0;
}

int checksum(char const *input) {
  signed char sum = -1;
  
  while (*input != '\0') {
    unsigned char c = toascii(*input++);
    printf("%d ", c);
    sum += c;
  }
  unsigned char c = toascii('\n');
  sum += c;
  printf("\n");
  return sum;
}

//01_4
int calculatorCount(char const *input);
int calculatorCount(char const *input) {
  int cnt = 0;
  while (*input++ != '\0') {
    cnt++;
  }
  
  if (cnt > MAX_INPUT) {
    cnt = MAX_INPUT;
  }
  return cnt;
}

int main_01_4_01() {
  int ch;
  int line = 0;
  int idx = 0;
  int maxLen = 0;
  char output[MAX_INPUT];
  char input[MAX_INPUT];
  
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      line++;
      input[idx++] = '\0';
      idx = 0;
      
      int tmpLen = calculatorCount(input);
      if (tmpLen > maxLen) {
        maxLen = tmpLen;
        strcpy(output, input);
      }
      
    } else {
      input[idx++] = ch;
    }
  }
  
  printf("max length: %d\n", maxLen);
  printf("max string is: %s\n", output);
  
  printf("\n");
  return EXIT_SUCCESS;
}

int main_01_4_02() {
  int maxLen = 0;
  char* output = malloc(sizeof(char *));
  char* input = malloc(sizeof(char *));
  
  while (gets(input) != NULL) {
    int len = calculatorCount(input);
    printf("len==%d\n", len);
    if (len > maxLen) {
      maxLen = len;
      strcpy(output, input);
    }
  }
  printf("max length: %d\n", maxLen);
  printf("max string is: %s\n", output);
  
  printf("\n");
  return EXIT_SUCCESS;
}
