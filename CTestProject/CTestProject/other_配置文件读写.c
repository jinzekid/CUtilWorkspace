//
//  other_配置文件读写.c
//  CTestProject
//
//  Created by JasonLu on 2017/6/29.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include "other_配置文件读写.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//获取字符串出现的次数 pzwj:配置文件
int getSubStrCnt_pzwj(char * str/*in*/,char * subStr/*in*/, int * cnt/*out*/, char* out_p_value) {
    char *tmpStr = str;
    char *tmpSubStr = subStr;
    int subStrCnt = 0;
    int isSubStr = 0;
    int i = 0,j = 0;
    int ret = 0;
    size_t strSublength = strlen(subStr);
    size_t strlength = strlen(str);

    if (str == NULL || subStr == NULL || cnt == NULL) {
        ret = 1;
        return ret;
    }
    
    do {
        isSubStr = 1;
        for (i = 0, j = 0; j < strSublength ; i++, j++) {
            if (tmpStr[i] != tmpSubStr[j]) {
                isSubStr = 0;
                break;
            }
        }
        
        //有子串，并且计数加1
        if (isSubStr == 1) {
            strlcpy(out_p_value, (tmpStr+strSublength+1), strlength-strSublength+1);
//            memcpy(out_p_value, (tmpStr+strSublength+1), strlength-strSublength+1);
            subStrCnt++;
            tmpStr += strlen(subStr);
            break;
        }
        else
            tmpStr++;
        
    }while(*tmpStr);
    
    *cnt = subStrCnt;
    return 0;
}

int getCfgItem(char* in_p_fileName, char* in_p_key, char* out_p_value, int* out_p_valueLen) {
    int ret = 0;
    if (in_p_fileName == NULL ||
        in_p_key == NULL ||
        out_p_value == NULL ||
        out_p_valueLen == NULL) {
        ret = -1;
        goto END;
    }
    
    
    char* pFileName = in_p_fileName;
    char buf[1024] = {0};
    FILE* fp = fopen(pFileName, "r+");
    if (fp == NULL){
        ret = -1;
        goto END;
    }
    
    int cnt = 0;
    char* p = NULL;
    do {
        p = fgets(buf, 1024, fp);
        if (p == NULL)
            break;
        
        printf("buf=%s\n", p);
        //搜索字符串
        ret = getSubStrCnt_pzwj(buf, in_p_key, &cnt, out_p_value);
        if (ret == -1) {
            ret = -1;
            goto END;
        }
            
        if (cnt > 0) {
            break;
        }

    } while (!feof(fp));
    
END:
    if(fp != NULL) {
        fclose(fp);
    }
    return ret;

}

int setCfgItem(char* in_p_fileName, char* in_p_itemName, char* in_p_itemValue, int itemValueLen) {
    int ret = 0;

    if (in_p_fileName == NULL ||
        in_p_itemName == NULL ||
        in_p_itemValue == NULL) {
        ret = -1;
        goto END;
    }
    
    char* pFileName = in_p_fileName;
    FILE* fp = fopen(pFileName, "a+");
    if (fp == NULL){
        ret = -1;
        goto END;
    }
    
    fputs(in_p_itemName, fp);
    fputs("=", fp);
    fputs(in_p_itemValue, fp);
    fputs("\n", fp);
    fclose(fp);

END:
    return ret;
}


int main_other_配置文件读写(){
    
    int ret = 0;
    int len = 0;
    int int_action = 0;
    char buf_key[1024] = {0};
    char buf_value[1024] = {0};
    char* pFileName = "/Users/Jasonlu/Desktop/4.txt";
    
    
    while (1) {
        printf("请输入你要的操作(1:设置配置文件;2:读取配置文件;0:退出\n");
        scanf("%d",&int_action);
        if (int_action == 0) {
            ret = 0;
            goto END;
        }
        
        //设置配置文件
        if (int_action == 1) {
            printf("请输入key值:\n");
            scanf("%s", buf_key);
            printf("请输入value值:\n");
            scanf("%s", buf_value);
            printf("key:%s,value:%s\n", buf_key, buf_value);
            
            int len = (int)strlen(buf_value);
            ret = setCfgItem(pFileName, buf_key, buf_value, len);
            if (ret == -1) {
                goto ERROR;
            }
        }
        //读取配置文件
        else if (int_action == 2) {
            printf("请输入key值:\n");
            scanf("%s", buf_key);
            printf("key:%s,value:%s\n", buf_key,buf_value);
            
            ret = getCfgItem(pFileName, buf_key, buf_value, &len);
            if (ret == -1) {
                goto ERROR;
            }
            
            printf("搜索结果：key:%s,value:%s\n", buf_key, buf_value);
        }
    }

ERROR:
    if (ret == -1) {
        printf("打开文件失败...\n");
    }
    
END:
    if (ret == 0) {
        printf("程序结束...\n");
    }
    
    system("pause");
    return EXIT_SUCCESS;
}
