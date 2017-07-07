//
//  结构体包含1级2级指针.c
//  CTestProject
//
//  Created by JasonLu on 16/10/2.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _advTeacher{
  char name[64];
  char * tile;
  char ** pStuArray;
  int age;
}Teacher;

void printTeacher(Teacher * tech, int num) {
  if (tech == NULL)
    return;
  
  int i, j;
  for (i = 0; i < num; i++) {
    Teacher t = tech[i];
    
    printf("Teacher info:\n");
    printf("name: %s\n", t.name);
    printf("tile: %s\n", t.tile);
    printf("Student's info: \n");
    for (j = 0; j < num; j++) {
      printf("%s\n", t.pStuArray[j]);
    }
    printf("age: %d\n", t.age);
  }
}

void sortTeacher(Teacher * tech) {
  
}

//分配内存
Teacher * createTeacher(int num) {
  Teacher *ptrTechArr = NULL;
  ptrTechArr = (Teacher *)malloc(sizeof(Teacher) * num);
  
  if (ptrTechArr == NULL) {
    return NULL;
  }
  
  int i, j;
  
  for (i = 0; i < num; i++) {
    char * tmpTile = (char *)malloc(sizeof(char) * 100);
    if (tmpTile == NULL) {
      return NULL;
    }
    ptrTechArr[i].tile = tmpTile;
  }
  
  
  for (i = 0;i < num; i++) {
    char ** ptrStuArr = (char **)malloc(sizeof(char *) * num);
    if (ptrStuArr == NULL)
      return NULL;
    
    for (j = 0; j < num; j++) {
      char *tmpStu = (char *)malloc(120);
      if (tmpStu == NULL)
        return NULL;
      ptrStuArr[j] = tmpStu;
    }
    ptrTechArr[i].pStuArray = ptrStuArr;
  }
  
  return ptrTechArr;
}

void freeMem_teacher1(Teacher * teacherArr , int num) {
  int i, j;
  for (i = 0; i < num; i++) {
    Teacher t = teacherArr[i];
    if (t.tile != NULL) {
      free(t.tile);
    }
    
    for (j = 0; j < num; j++) {
      if (t.pStuArray[j] != NULL) {
        free(t.pStuArray[j]);
      }
    }
    t.pStuArray = NULL;
  }
  printf("free memory is ok...\n");
}

//形参改变实参的值
void freeMem_teacher2(Teacher ** teacherArr , int num) {
  int i, j;
  Teacher *tmpTeacherArr = NULL;
  tmpTeacherArr = *teacherArr;
  for (i = 0; i < num; i++) {
    Teacher t = tmpTeacherArr[i];
    if (t.tile != NULL) {
      free(t.tile);
    }
    
    for (j = 0; j < num; j++) {
      if (t.pStuArray[j] != NULL) {
        free(t.pStuArray[j]);
      }
    }
    t.pStuArray = NULL;
  }
  
  free(tmpTeacherArr);
  *teacherArr = NULL;
  printf("free memory is ok...\n");
}

int main99(int argc, const char *argv[]) {
  
  int i, j;
  int num = 1;
  Teacher *ptrTeacherArr = NULL;
  ptrTeacherArr = createTeacher(num);
  
  for (i = 0; i < num; i++) {
    printf("Please input teacher's name:");
    scanf("%s", ptrTeacherArr[i].name);
    printf("Please input teacher's tile:");
    scanf("%s", ptrTeacherArr[i].tile);
    
    for (j = 0; j < num; j++) {
      printf("j==%d\n",j);
      printf("Please input student's name:");
      scanf("%s", ptrTeacherArr[i].pStuArray[j]);
    }
    printf("Please input teacher's age:");
    scanf("%d", &ptrTeacherArr[i].age);
  }
  
  printTeacher(ptrTeacherArr, num);
  
  //freeMem_teacher1(ptrTeacherArr, num);
  freeMem_teacher2(&ptrTeacherArr, num);
  
  printTeacher(ptrTeacherArr, num);
  
  printf("hello...\n");
  return 0;
}
