//
//  字符串的出现次数.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//获取字符串出现的次数
int getSubStrCnt(char * str/*in*/,const char * subStr/*in*/, int * cnt/*out*/) {
  char *tmpStr = str;
  char *tmpSubStr = subStr;
  int subStrCnt = 0;
  int isSubStr = 0;
  int i = 0,j = 0;
  int ret = 0;
  size_t strlength = strlen(subStr);
  
  if (str == NULL || subStr == NULL || cnt == NULL) {
    ret = 1;
    return ret;
  }
  
  do {
    isSubStr = 1;
//    for (i = 0, j = 0; *(tmpSubStr + i) != '\0' ; i++, j++) {
    for (i = 0, j = 0; j < strlength ; i++, j++) {
      if (tmpStr[i] != tmpSubStr[j]) {
        isSubStr = 0;
        break;
      }
    }
    
    //有子串，并且计数加1
    if (isSubStr == 1) {
      subStrCnt++;
      tmpStr += strlen(subStr);
    }
    else
      tmpStr++;
    
  }while(*tmpStr);

  *cnt = subStrCnt;
  return ret;
}

int main55(int argc, const char *argv[]) {
  
  char *p = "abcd11111abcd2222abcdqqqqq";
  char buf[] = "a";
  int cnt = 0;
  int ret;
  
  ret = getSubStrCnt(p, buf, &cnt);
  if (ret == -1) {
    printf("error: %d\n", ret);
  }
  printf("sub cnt: %d\n", cnt);
  
  printf("hello...\n");
  return 0;
}
