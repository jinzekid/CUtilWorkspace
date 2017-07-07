#include <stdio.h>
#include <stdlib.h>

/*获取字符串长度*/
int bufLength(char* inBuf, int* len) {
  int ret = 0;
  int _len = 0;
  if (inBuf == NULL) {
    ret = -1;
    *len = _len;
    return ret;
  }

  while((*inBuf++ != '\0')) {
    _len++;
  }

  *len = _len;
  return ret;
}

/*移除字符串前后空格-主调函数分配内存*/
int trimSpace_zd(char* inBuf, char* outBuf){
  int ret = 0;
  if (inBuf == NULL || outBuf == NULL) {
    ret = -1;
    return ret;
  }

  char* tmp = inBuf;
  int len;
  int i = 0;
  int j = 0;
  int cnt = 0;
  
  bufLength(inBuf, &len);
  tmp += (len-1);
  //计算后面空格数
  while(*tmp-- == ' ') {
    j++;
  }
 
  tmp = inBuf;
  //计算前面空格书
  while(*tmp++ == ' ') {
    i++;
  }
  
  tmp = inBuf;
  tmp += i;
  while (cnt++ < (len - i - j)) {
    *outBuf++ = *tmp++;
  }

  *outBuf = '\0';
  return ret;
}

/*移除字符串前后空格-被调函数分配内存*/
int trimSpace_bd(char* inBuf, char** outBuf){
  int ret = 0;
  if (inBuf == NULL) {
    ret = -1;
    return ret;
  }  

  char* tmpBuf = inBuf;
  int cnt_frontSpace = 0;
  int cnt_backSpace = 0;
  int cnt = 0;
  int len;
  bufLength(inBuf, &len);

  while(*tmpBuf++ == ' ') {
    cnt_frontSpace++;
  }
  
  tmpBuf = inBuf;
  tmpBuf += len-1;
  while(*tmpBuf-- == ' ') {
    cnt_backSpace++;
  }
  
  printf("len=%d,i=%d,j=%d,ret length=%d\n",len,cnt_frontSpace,cnt_backSpace,len-cnt_frontSpace-cnt_backSpace+1);
  char* retBuf = (char *)malloc(sizeof(char) * (len-cnt_frontSpace-cnt_backSpace+1));
  char* tmpRetBuf = retBuf;
  tmpBuf = inBuf;
  tmpBuf += cnt_frontSpace;
  while(cnt++ < (len - cnt_frontSpace - cnt_backSpace)) {
    *retBuf++ = *tmpBuf++;
  }

  *retBuf = '\0';

  *outBuf = tmpRetBuf;
  return ret;
}

//===========================================//
int main_去前后空格函数(){
  int ret = 0;
  //主调函数分配内存
  char buf[] = "  ccc abcdedd   ";
  char retBuf[100];// = (char *)malloc(100);
  printf("before sizeof(retBuf=%lu)\n",sizeof(retBuf));
  ret = trimSpace_zd(buf, retBuf);
  int len;
  if (ret == 0) {
    bufLength(retBuf, &len);
    printf("retBuf==%s,length(retBuf)==%d\n", retBuf, len);
    printf("sizeof(retBuf2=%lu)\n",sizeof(retBuf));
  }

  printf("======================\n");
  
  //被调函数分配内存
  char buf2[] = " cds fdfd  cddfdkg       ";
  char* retBuf2 = NULL;
  printf("before sizeof(retBuf2=%lu)\n",sizeof(retBuf2));
  ret = trimSpace_bd(buf2, &retBuf2);
  if (ret == 0) {
    bufLength(retBuf2, &len);
    printf("retBuf2==%s,length(retBuf2)==%d\n", retBuf2, len);
    printf("sizeof(retBuf2=%lu)\n",sizeof(retBuf2));
  }
  
  printf("Hello world!\n");
  return ret;
}
