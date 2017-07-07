//
//  other_二级指针运用_合并并排序字符串.c
//  CTestProject
//
//  Created by JasonLu on 2017/6/27.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int other_04_sort(char** const p1, int num1, char* p2[30], int num2, char*** p3, int* num) {
    int ret = 0;
    int i,j,len = 0;
    
    char** tmp = (char**)malloc(sizeof(char*) + (num1 + num2));
    char* tmpStr = NULL;
    //开始拼接
    for (i = 0; i< num1; i++) {
        size_t len = strlen(*(p1+i))+1;
        tmp[i] = (char*)malloc(len);
        strcpy(tmp[i], *(p1+i));
    }
    ;
    for (j=0; j< num2; j++) {
        size_t len = strlen(*(p2+j))+1;
        *(tmp+i+j) = (char*)malloc(len);
        strcpy(*(tmp+i+j), *(p2+j));
    }
    
    //开始排序
    len = num1 + num2;
    for (i = 0; i < len; i++) {
        for (j = i+1; j < len; j++) {
            if (strcmp(*(tmp+i), *(tmp+j)) > 0) {
                tmpStr = *(tmp+i);
                *(tmp+i) = *(tmp+j);
                *(tmp+j) = tmpStr;
            }
        }
    }
    
    *p3 = tmp;
    *num = len;
    return ret;
}

void other_04_printWithArr(char** p, int num) {
    for (int i = 0; i < num; i++) {
        printf("%s,length=%lu\n", *(p+i),strlen(p[i]));
    }
}

int other_04_safeFree(char*** p, int num) {
    char** tmp = NULL;
    if (p == NULL) {
        return -1;
    }
    tmp = *p;
    for (int i = 0; i < num; i++) {
        free(*(tmp+i));
    }
    
    *p = NULL;
    return 1;
}

int main_other_二级指针运用() {
    
    int num1, num2, num3 = 0;
    char* p1[] = {"aaaa", "bbbb", "ccc"};
    char* p2[] = {"111","222","333", "bb"};
    char** p3 = NULL;
    
    num1 = sizeof(p1) / sizeof(char*);
    num2 = sizeof(p2) / sizeof(char*);
    
    other_04_sort(p1, num1, p2, num2, &p3, &num3);
    other_04_printWithArr(p3, num3);

    if (other_04_safeFree(&p3, num3)) {
        printf("free success....\n");
    }

    return EXIT_SUCCESS;
}
