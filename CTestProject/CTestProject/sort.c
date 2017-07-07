#include <stdio.h>
#include <stdlib.h>

void print(int a[], int length){
  for (int i =0;i < length;i++){
    printf("a[%d]:%d\n",i,a[i]);
  }
}

int main_sort(int argc, const char *argv[]){
  
  int a[]={5,3,2,1,4};
  printf("a count=%lu\n", sizeof(a)/sizeof(int));

  int length = sizeof(a)/sizeof(int);
  for (int i = 0; i < length; i++){
    for (int j = i+1;j < length; j++){
      if (a[i] > a[j]) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
      }
    }
  }

  print(a, length);


  printf("Hello wor`ld!\n");
  return 0;
}
