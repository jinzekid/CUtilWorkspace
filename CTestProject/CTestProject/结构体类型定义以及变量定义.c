//
//  结构体类型定义以及变量定义.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>

struct _teacher {
  char name[32];
  char * tile;
  char * address;
  int age;
};

struct _student {
  char name[32];
  char tile[32];
  char * address;
  int age;
}s1, s2 = {"Tom", "gongzhu", "ddd", 1};

struct {
  char name[32];
  int age;
} s3, s4 = {"Tom", 1};

typedef struct {
  char *name;
  float price;
  char * companyName;
}Car;

int initCarWith(Car * car ,char * name /*in*/, float price, char * cpn) {
  Car *aCar = car;
  if (aCar == NULL) {
    return -1;
  }
  aCar->name = (char *)malloc(strlen(name)+1);
  strcpy(aCar->name, cpn);
  
  strcpy(aCar->name, name);
  
  aCar->price = price;
  
  aCar->companyName = (char *)malloc(strlen(cpn)+1);
  strcpy(aCar->companyName, cpn);
  
  return 0;
}

void printCarWithPtr(Car *car) {
  printf("car name:%s", car->name);
  printf(" price:%f", car->price);
  printf(" company name:%s\n", car->companyName);
}

void printCarWithStruct(Car car) {
  printf("car name:%s", car.name);
  printf(" price:%f", car.price);
  printf(" company name:%s\n", car.companyName);
}

void printTeacherWith(struct _teacher t) {
  printf("teacher name:%s", t.name);
  printf(" tile:%s", t.tile);
  printf(" address:%s", t.address);
  printf(" age:%d\n", t.age);
}

int main(int argc, const char *argv[]) {
  Car oneCar;
  int ret = initCarWith(&oneCar, "aaa", 100, "bbb");
  if (ret == -1) {
    printf("error: initCarWith func.\n");
  }
  
  printCarWithPtr(&oneCar);
  
  {
    struct _teacher t1 = {"name11", "tile11", "address11", 11};
    printTeacherWith(t1);
  }
  
  printf("hello...\n");
  return 0;
}
