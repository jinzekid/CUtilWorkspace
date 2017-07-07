//
//  other_文件基本操作.c
//  CTestProject
//
//  Created by JasonLu on 2017/6/28.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_other_文件基本操作() {
    FILE* fp =NULL;
    FILE* fp_toEncrypt =NULL;
    FILE* fp_toDecrypt =NULL;

    fp = fopen("/Users/Jasonlu/Desktop/1.txt", "r+");
    fp_toEncrypt = fopen("/Users/Jasonlu/Desktop/2.txt", "w+");
    fp_toDecrypt = fopen("/Users/Jasonlu/Desktop/3.txt", "w+");

    if (fp == NULL) {
        printf("open file failed...");
        return EXIT_FAILURE;
    }
    
    if (fp_toEncrypt == NULL) {
        printf("open file failed...");
        return EXIT_FAILURE;
    }
    
    
    
    /*
    char buf[] = "hello world";
    for (int i = 0;i < strlen(buf); i++) {
        fputc(buf[i], fp);
    }
    */
    
    //读取 内存打包技术
    char buf[1024];
    char* p = NULL;
    while (!feof(fp)) {
        p = fgets(buf, 1024, fp);
        if (p == NULL)
            break;

        printf("buf=%s\n", p);
        
        do {
            fputc(*p+1, fp_toEncrypt);
        } while (*p++);
    }
    fclose(fp);
    fclose(fp_toEncrypt);

    
    //解密文件
    p = NULL;
    fp_toEncrypt = fopen("/Users/Jasonlu/Desktop/2.txt", "r+");
    while (!feof(fp_toEncrypt)) {
        //    1.读取加密文件
        p = fgets(buf, 1024, fp_toEncrypt);
        if (p == NULL)
            break;
        
        printf("p==%s\n", p);
        // 2.解密
        do {
            if (*p-1 == EOF)
                break;
            fputc((*p-1), fp_toDecrypt);

        } while (*p++);
    }
    
    
    fclose(fp_toEncrypt);
    fclose(fp_toDecrypt);
    
    
    return EXIT_SUCCESS;
}
