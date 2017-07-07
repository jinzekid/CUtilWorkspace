#include <stdio.h>
#include <stdlib.h>

char* str_pj(char* x, char* y){
  char buf[80];
  char *ret = buf;

  while((*ret++=*x++));
  ret--;
  while((*ret++=*y++));
  ret = buf;

  return ret;
}

int main指针数组(int argc, const char *argv[]){

  char* x = "abc";
  char* y = "def";

  char* ret = str_pj(x, y);
  printf("ret string=%s\n", ret);

  printf("Hello world!\n");
  return 0;
}


int main指针数组2()
{
  char buf1[100];
  char buf2[200];
  strcpy(buf1, "111");
  printf("%s", strcat(buf1, "222"));
  getchar();
  return 0;
}
