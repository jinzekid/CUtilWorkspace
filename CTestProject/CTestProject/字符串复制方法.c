//
//  main.c
//  CTestProject
//
//  Created by JasonLu on 16/9/8.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//字符串copy方法1
void copyStr1(char * from, char * to) {
    
    char * tmpfrom = from;
    char * tmpto   = to;
    
    while ((*tmpto++ = *tmpfrom++)) {
        ;
    }
    printf("to==%s\n", to);
}

//字符串copy方法2
void copyStr2(char * from, char * to) {
    
    while ((*to++ = *from++)) {
        ;
    }
    //不能打印to，因为to的位置已经发生改变，移动到最后一个字符'\0'
    printf("to==%s\n", to);
}

//字符串的拼接
char *str_cnct(char *x, char* y)     /*简化算法*/
{
    char str3[80];
    char *z=str3; 	/*指针z指向数组str3*/
    while((*z++=*x++));
    z--;	               /*去掉串尾结束标志*/
    while((*z++=*y++));
    z=str3;		 /*将str3地址赋给指针变量z*/
    return(z);
}


int main11(int argc, const char * argv[]) {
    // insert code here...
    
    int size = 0;
    char buf3[] = "abcd";
    int len = strlen(buf3);
    printf("buf3 length:%d \n", len); //4
    size = sizeof(buf3); //
    printf("buf3 size:%d \n", size); //5
    
    
    /*
    char * string1 = "1234567890";
    char buf[100];
    strcpy(buf, string1);
    char * string2 = "747DC8";
    unsigned long length;
    //在字符str1中查找，与str2中任意字符有公共交集的位置
    length = strcspn(string1, string2);
    printf("Character where strings intersect is at position %lu\n", length);
    */
     
    /*
    char * s1 = "aaaa";
    char * s2 = "bacd";
    char * resultStr = NULL;
    
    resultStr = str_cnct(s1, s2);
    printf("resultStr==%s\n", resultStr);
    */

    
    /*
    //字符串copy
    char * from = "abcd";
    char buf2[100];
    
    printf("sizeof:%lu\n", sizeof(from));
    printf("length:%lu\n", strlen(from));
    
    copyStr1(from, buf2);
    printf("buf2==%s\n", buf2);
    */
    
    printf("Hello, World!\n");
    return 0;
}
