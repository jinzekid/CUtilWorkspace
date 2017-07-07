//
//  结构体类型定义以及变量定义.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef void (*fptrDisplay)(void* data);
//typedef void (*fptrFree)(void* data);
//
////结构体定义
//typedef struct _teacher{
//    char name[32];
//    char gender;
//    int age;
//    char* title;
//    char* address;
//}Teacher;
//
//struct _student {
//    char name[32];
//    char gender;
//    int age;
//    char** classes;//主修课程，使用二级指针,表示指向字符数组(指针)的指针，比如:char* c[] = {"语文","数学","物理"}
//    int classesCnt;
//};
//typedef struct _student Student;
//typedef Student *pStudent;
//
////结构体的初始化
////定义时候直接初始化
//struct _teacher2{
//    char name[32];
//    char gender;
//    int age;
//    char* title;
//}t2 = {"t1",0,32,"数学"};
//
//Teacher t1 = {"t2",0,33,"语文"};
//
//
//typedef struct {
//  char *name;
//  float price;
//  char * companyName;
//}Car;
//
//int initCarWith(Car * car ,char * name /*in*/, float price, char * cpn) {
//  Car *aCar = car;
//  if (aCar == NULL) {
//    return -1;
//  }
//  //名字分配内存
//  aCar->name = (char *)malloc(strlen(name)+1);
//  strcpy(aCar->name, name);
//  aCar->price = price;
//  //公司名字分配内存
//  aCar->companyName = (char *)malloc(strlen(cpn)+1);
//  strcpy(aCar->companyName, cpn);
//  
//  return 0;
//}
//
//void printCarWithPtr(Car *car) {
//  printf("car name:%s", car->name);
//  printf(" price:%f", car->price);
//  printf(" company name:%s\n", car->companyName);
//}
//
//void printCarWithStruct(Car car) {
//  printf("car name:%s", car.name);
//  printf(" price:%f", car.price);
//  printf(" company name:%s\n", car.companyName);
//}
//
//void printTeacherWithStruct(struct _teacher t) {
//  printf("teacher name:%s", t.name);
//  printf(" tile:%s", t.title);
//  printf(" address:%s", t.address);
//  printf(" age:%d\n", t.age);
//}
//
//Student* createStudent(char* name, char gender, int age, char* classes[], int cnt){
//    
//    Student* s = (Student*)malloc(sizeof(Student));
//    if (s == NULL) {
//        return NULL;
//    }
//    
//    char** tmpClasses = (char**)malloc(sizeof(char*) * cnt);
//    for (int i = 0; i< cnt; i++) {
//        char* pClassesName = classes[i];
//        char* pNewClassesName = (char*)malloc(strlen(pClassesName) + 1);
//        memset(pNewClassesName, 0 , strlen(pClassesName) + 1);
//        strcpy(pNewClassesName, pClassesName);
//        tmpClasses[i] = pNewClassesName;
//    }
//    
//    
//    char* pNewName = malloc(strlen(name)+1) ;
//    memset(pNewName, 0, strlen(name)+1);
//    strcpy(s->name, name);
//    s->classes = tmpClasses;
//    s->age = age;
//    s->gender = gender;
//    s->classesCnt = cnt;
//    
//    return s;
//}
//
////打印学生信息
//void printStudent(pStudent s) {
//    if(s==NULL) {
//        printf("Student Info not exit!\n");
//        return;
//    }
//    
//    printf("====学生信息====\n");
//    printf("姓名:%s\n",s->name);
//    printf("年龄:%d\n",s->age);
//    printf("性别:%d\n",s->gender);
//    printf("所选课程:\n");
//    char** classes = s->classes;
//    for (int i = 0; i < s->classesCnt; i++) {
//        printf("%s ", *(classes+i));
//    }
//    printf("\n");
//
//    printf("===============\n");
//}
//
//// 二级指针，同时修改实参的值
//void freeStudent(pStudent* s) {
//    if (s == NULL)
//        return;
//    
//    Student* _tmp_s = NULL;
//    _tmp_s = *s;
//    int _cnt = _tmp_s->classesCnt;
//    
//    for (int i = 0; i< _cnt; i++) {
//        printf("free clase name:%s\n",_tmp_s->classes[i]);
//        free(_tmp_s->classes[i]);
//    }
//    
//    printf("free clase:%lu\n",sizeof(_tmp_s->classes));
//    free(_tmp_s->classes);
//    
//    free(_tmp_s);
//    *s = NULL;
//}
//
//int main_结构体定义以及变量定义(int argc, const char *argv[]) {
//
//    fptrDisplay DISPLAY_Student = (fptrDisplay)printStudent;
//    fptrFree    FREE_Student = (fptrFree)freeStudent;
//    
//    
//    char* classes[] = {"语文","数学","英文"};
//    int num = sizeof(classes)/sizeof(char*);
//    printf("num==%d\n",num);
//    
//    pStudent s1 = createStudent("S1", 1, 18, classes, num);
//    DISPLAY_Student(s1);
//    FREE_Student(&s1);
//    DISPLAY_Student(s1);
//
//    
//    
//    
//    Car oneCar;
//    int ret = initCarWith(&oneCar, "aaa", 100, "bbb");
//    if (ret == -1) {
//        printf("error: initCarWith func.\n");
//    }
//    
//    printCarWithPtr(&oneCar);
//    
//    
//    printf("hello...\n");
//    return 0;
//}
