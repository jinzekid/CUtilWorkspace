//
//  字符串基本操作.c
//  CTestProject
//
//  Created by JasonLu on 16/9/8.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void stringLen(char * pStr) {
    int i = 0;
    while (*pStr++) {
        i++;
    }
    printf("i===%d\n", i);
    ;
}

//字符串的逆序
void revserString(char * from, char * to){
    int len = strlen(from);
    char * tmpFrom = from+len-1;
    char * tmpTo = to;
    
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
    printf("buf3 length:%lu \n", len); //4
    size = sizeof(buf3); //
    printf("buf3 size:%d \n", size); //5
}

int main(int argc, const char * argv[]) {
    
    // insert code here...
    char buf[] = "a1234567";
    char * to = (char *)malloc(sizeof(buf));
    
    revserString(buf, to);
    printf("to===%s\n", to);

    printf("hello...\n");
    return 0;
}