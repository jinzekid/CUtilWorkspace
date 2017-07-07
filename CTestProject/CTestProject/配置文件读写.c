//
//  配置文件读写.c
//  CTestProject
//
//  Created by JasonLu on 16/10/6.
//  Copyright © 2016年 JasonLu. All rights reserved.
//
// 接口要求紧，模块要求松
#include <stdio.h>
#include <string.h>

#define MAXLINE 2048

//写配置文件
int WriteCFGItem(const char *filename /*in*/, const char *key /*in*/,
                 const char *value /*in*/, size_t len);
//读配置文件
//主调函数调用分配内存
int GetCFGItem(const char *filename /*in*/, const char *key /*in*/,
               char *value /*in*/, int *len);
//被调函数分配内存
int GetCFGItem2(const char *filename /*in*/, const char *key /*in*/,
                char **value /*out*/);

//修改配置文件, 有一个前提：用户应该已经知道key
int modifyCFGItem(const char *filename /*in*/, const char *key,
                  const char *value);

//去除前后空格
char *trimStrSpace3(const char *in /*in*/, char **out /*out*/,
                    int *length /*out*/) {

  int ret = 0;
  if (in == NULL) {
    ret = -1;
    return NULL;
  }

  size_t len = strlen(in);
  char *frontPtr = in;
  char *trailPtr = (in + len - 1);
  char *tmpPtr = NULL;
  int i = 0, j = 0;

  while (*frontPtr == ' ') {
    frontPtr++;
    i++;
  }

  while (*trailPtr == ' ') {
    trailPtr--;
    j++;
  }

  if (*trailPtr == '\n') {
    trailPtr--;
    j++;
  }

  char *retStr = (char *)malloc(sizeof(char) * (len - (i + j)) + 1);
  retStr = strncpy(retStr, frontPtr, len - (i + j));
  if (retStr == NULL) {
    return NULL;
  }

  *length = len - (i + j) + 1;
  *out = retStr;
  return retStr;
}

/////////////////////////////////////////////
//写配置文件
int WriteCFGItem(const char *filename /*in*/, const char *key /*in*/,
                 const char *value /*in*/, size_t len) {
  int ret = 0;
  int iTag = 0;
  char lineBuf[1024];

  if (filename == NULL || key == NULL || value == NULL) {
    ret = -1;
    goto End;
  }

  FILE *fp = NULL;
  fp = fopen(filename, "r+");
  if (fp == NULL) {
    ret = -2;
    goto End;
  }

  //如果打开文件失败则新建一个文件
  if (fp == NULL) {
    fp = fopen(filename, "w+r");
    if (fp == NULL) {
      ret = -3;
      goto End;
    }
  }

  //移动到文件末尾
  fseek(fp, 0, SEEK_END); //把文件指针从0位置开始，移动到文件末尾
  long length = ftell(fp); //获取文件长度

  fseek(fp, 0, SEEK_SET); //把文件指针返回头部

  char fileBuf[1024 * 8];
  //如果文件超过8k就不支持
  if (length > 1024 * 8) {
    ret = -4;
    goto End;
  }

  char *pTmp = NULL;
  while (!feof(fp)) {
    memset(lineBuf, 0, sizeof(lineBuf));
    //一行一行读取
    fgets(lineBuf, MAXLINE, fp);
    printf("lineBuf=%s\n", lineBuf);

    pTmp = strstr(lineBuf, key);
    if (pTmp == NULL) { //判断key是不是在所在行, 就把行copy到缓存中
      strcat(fileBuf, lineBuf);
      continue;
    } else {
      sprintf(lineBuf, "%s = %s\n", key, value);
      strcat(fileBuf, lineBuf);
      //若存在key，说明修改
      iTag = 1;
    }
  }

  //如果不存在，就追加到最后
  if (iTag == 0) {
    fprintf(fp, "%s = %s\n", key, value);
  } else {
    if (fp != NULL) {
      fclose(fp);
      fp = NULL; //避免野指针
    }

    //重新新建一个文件
    fp = fopen(filename, "w+t");
    if (fp == NULL) {
      ret = -4;
      goto End;
    }

    fputs(fileBuf, fp);
  }

End:
  if (fp != NULL) {
    fclose(fp);
  }
  return ret;
}

int GetCFGItem(const char *filename /*in*/, const char *key /*in*/,
               char *value /*in*/, int *len) {
  int ret = 0;
  if (filename == NULL || key == NULL || value == NULL) {
    ret = -1;
    return ret;
  }

  char *pTmp = NULL;
  char lineBuf[MAXLINE];
  FILE *fp = NULL;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    ret = -1;
    return ret;
  }

  while (!feof(fp)) {
    memset(lineBuf, 0, sizeof(lineBuf));
    //一行一行读取
    fgets(lineBuf, MAXLINE, fp);
    printf("lineBuf=%s\n", lineBuf);

    pTmp = strchr(lineBuf, '=');
    if (pTmp == NULL) { //没有=号
      continue;
    }

    pTmp = strstr(lineBuf, key);
    if (pTmp == NULL) { //判断key是不是在所在行
      continue;
    }

    pTmp += strlen(key); // mykey1 = myvalue1 ==> '= myvalue1'

    pTmp = strchr(lineBuf, '=');
    if (pTmp == NULL) { //没有=号
      continue;
    }

    pTmp += 1; //'= myvalue1' ==> ' myvalue1'

    //这个时候需要去除前后空格
    char *pRet = NULL;
    int len = 0;
    //注意最后一个'\n'
    pRet = trimStrSpace3(pTmp, &pRet, &len);
    // printf("pTmp:%s\n", pRet);
    //最后结果
    memcpy(value, pRet, len);
  }

  return ret;
}

///////////////////////////////

//#define CFGNAME "/Users/Jasonlu/Desktop/cfg.rtf"
#define CFGNAME                                                                \
  "/Users/Jasonlu/Desktop/Dev/CDev/CUtilWorkspace/CTestProject/cfg"

void mymenu() {
  printf("===============\n");
  printf("1 测试写配置文件\n");
  printf("2 测试读配置文件\n");
  printf("0 退出\n");
  printf("===============\n");
}

int TGetCFG() {

  int ret = 0;
  int vlen = 0;
  char name[1024] = {0};
  char value[1024] = {0};

  printf("\n请键入key:");
  scanf("%s", name);

  ret = GetCFGItem(CFGNAME, name, value, &vlen);
  if (ret != 0) {
    printf("func GetCFItem err:%d\n", ret);
    return ret;
  }

  printf("value:%s\n", value);
  return ret;
}

//写配置项
int TWriteCFG() {

  int ret = 0;
  char name[1024] = {0};
  char value[1024] = {0};

  printf("\n请键入key:");
  scanf("%s", name);

  printf("\n请键入value:");
  scanf("%s", value);

  ret = WriteCFGItem(CFGNAME, name, value, strlen(value));
  if (ret != 0) {
    printf("func WriteCFItem err:%d\n", ret);
    return ret;
  }

  printf("你输入的是：%s = %s\n", name, value);
  return ret;
}

int main10(int argc, const char *argv[]) {

  int b = 3;
  int arr[] = {6, 7, 8, 9, 10};
  int *ptr = arr;
  *(ptr++) += 123;
  printf("%d,%d\n", *ptr, *(++ptr));

  int choice;

  for (;;) {
    mymenu();
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      TWriteCFG();
      break;
    case 2:
      TGetCFG();
      break;
    case 0:
      exit(0);
      break;
    default:
      break;
    }
  }

  printf("hello...\n");
  return 0;
}
