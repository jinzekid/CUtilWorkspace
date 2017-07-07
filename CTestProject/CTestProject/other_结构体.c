//
//  other_结构体.c
//  CTestProject
//
//  Created by JasonLu on 2017/6/26.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//结构体的声明和定义
typedef struct {
    char name[60];
    int age;
}student;

typedef struct {
    char name[60];
    int age;
}teacherOnly;

typedef struct {
    char name[60];
    char** students;
    int age;
}teacherWithStudents;


void printTeacherOnly(teacherOnly* ptrTeacher) {
    teacherOnly* tmp_ptrTeacher = ptrTeacher;
    printf("teacher name:%s, age=%d\n", tmp_ptrTeacher->name, tmp_ptrTeacher->age);
}

void printTeacherWithStudents(teacherWithStudents* ptrTeacher, int num) {
    teacherWithStudents* tmp_ptrTeacher = ptrTeacher;
    for (int i= 0; i< num; i++) {
        printf("teacher name:%s, age=%d\n", tmp_ptrTeacher[i].name, tmp_ptrTeacher[i].age);
    }
}


//start 主调函数分配内存
void createTeachersOnly(teacherOnly* ptrTeacher) {
    ptrTeacher->age = 30;
    strcpy(ptrTeacher->name, "Tom");
}

void createStudents(student* ptrStudent) {
    
}
//end 主调函数分配内存

//start 被调函数分配内存
void createTeacherWithStudents(teacherWithStudents** ptrT, int num) {
    teacherWithStudents* tmp_ptr = (teacherWithStudents*)malloc(sizeof(teacherWithStudents) * num);
    
    for (int i =0; i< num; i++) {
        printf("输入老师姓名:");
        scanf("%s",tmp_ptr[i].name);
        printf("输入老师年龄:");
        scanf("%d",&tmp_ptr[i].age);

    }
    *ptrT = tmp_ptr;
}

//end 被调函数分配内存

int main_struct() {
    
//    主调函数分配内存
    teacherOnly t1;
    createTeachersOnly(&t1);
    printTeacherOnly(&t1);
    
    teacherWithStudents* ptrTS;
    createTeacherWithStudents(&ptrTS, 3);
    printTeacherWithStudents(ptrTS, 3);
    
    
    return EXIT_SUCCESS;
}
