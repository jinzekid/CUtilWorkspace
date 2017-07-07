//
//  02_练习.c
//  CTestProject
//
//  Created by JasonLu on 2017/5/4.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "increment.h"
#include "negate.h"

int main_02_01(){
  
  printf("%d %d %d",increment(10), increment(0), increment(-10));
  
  printf("%d %d %d",negate(10), negate(0), negate(-10));
  return EXIT_SUCCESS;
}

int main_02_02() {
  
  /*自己的*/
  /*
  int ch;
  int leftBrace = 0;
  int rightBrace = 0;
  
  printf("请输入字符串:\n");
  while ((ch = getchar()) != EOF) {
    
    if (ch == '{') {
      leftBrace++;
    }
    
    if (ch == '}') {
      if (leftBrace == 0) {
        printf("Extra closing brace!\n");
      } else {
        rightBrace++;
      }
    }
  }
  
  
  if (leftBrace > rightBrace) {
    printf("%d unmatched opening brace(s)!\n", leftBrace-rightBrace);
  }
  */
  
  int ch;
  int braces = 0;
  
  while ((ch = getchar()) != EOF) {
    if (ch == '{') {
      braces++;
    }
    
    if (ch == '}') {
      if (braces == 0) {
        printf("Extra closing brace!\n");
      } else {
        braces--;
      }
    }
  }
  
  if (braces > 0) {
    printf("%d unmatched opening brace(s)!\n", braces);
  }
  
  return EXIT_SUCCESS;
}
