//
//  other_链表基础.c
//  CTestProject
//
//  Created by JasonLu on 2017/7/6.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char name[64];
    int age;
}Student;

typedef struct _node{
    void* data;
    struct _node* next;
}List_student;

//链表基本操作
List_student* initList() {
    
    List_student* ls = malloc(sizeof(List_student));
    if (ls == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return NULL;
    }
    
    ls->data = NULL;
    ls->next = NULL;
    return ls;
}

Student* createStudent(char* name, int age) {
    Student* s = malloc(sizeof(Student));
    if (s == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return NULL;
    }
    strcpy(s->name, name);
    s->age = age;
    
    return s;
}

void addStudentList(List_student* list, Student* s) {
    if (list == NULL || s == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    
    //创建一个新节点
    List_student* pNode = malloc(sizeof(List_student));
    pNode->next = NULL;
    pNode->data = s;
    
    if (list->next == NULL) {
        list->next = pNode;
    }
    else {
        List_student* tmp_current = list->next;
        while (tmp_current->next != NULL) {
            tmp_current= tmp_current->next;
        }
        tmp_current->next = pNode;
    }
    
}

int delStudentList(List_student* list, char* name, Student** s) {
    int ret =0;
    Student* _tmp_s = NULL;

    if (list == NULL || name == NULL) {
        ret = -1;
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        goto END;
    }
    
    List_student* _tmp_current = list;
    while (_tmp_current) {
        if (_tmp_current->data) {
            Student* ps = (Student*)_tmp_current->data;
            if (strcmp(ps->name, name) == 0) {
                _tmp_s = ps;
                ret = 1;
                goto END;
            }
        }
        _tmp_current = _tmp_current->next;
    }
    
    
END:
    if (ret == -1) {
        
    }
    
    
    return ret;
}

int getStudentList(List_student* list, char* name, Student** s) {
    int ret = 0;
    Student* _tmp_s = NULL;
    if (list == NULL || name == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        ret = -1;
        goto END;
    }

    List_student* _tmp_current = list;
    while (_tmp_current) {
        if (_tmp_current->data) {
            Student* ps = (Student*)_tmp_current->data;
            if (strcmp(ps->name, name) == 0) {
                _tmp_s = ps;
                ret = 1;
                goto END;
            }
        }
        _tmp_current = _tmp_current->next;
    }
    
END:
    if (ret == -1) {
        *s = NULL;
    }
    else if (ret == 1){
        *s = _tmp_s;
    }
    
    return ret;
}

void printStudentInfo(Student* s) {
    printf("学生信息:姓名:%s,年龄:%d\n",s->name,s->age);
}

void printStudentList(List_student* list) {
    if (list == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    if (list->next == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    
    List_student* tmp_current = list->next;
    while (tmp_current) {
        if (tmp_current->data) {
            Student* ps = (Student*)tmp_current->data;
            printStudentInfo(ps);
        }
        tmp_current = tmp_current->next;
    }
}


void freeStudentList(List_student** list){
    if (list == NULL) {
        printf("error:%s,%d,%s\n", __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    
    List_student* tmp_list = NULL;
    tmp_list = *list;
    
    List_student* tmp_current = tmp_list->next;
    while (tmp_current) {
        if (tmp_current->data) {
            Student* ps = (Student*)tmp_current->data;
            printf("释放学生内存:姓名:%s,年龄:%d\n",ps->name,ps->age);
            free(tmp_current->data);
        }
        tmp_current = tmp_current->next;
    }
    
    free(tmp_list);
    *list = NULL;
}


int main(int argc, const char *argv[]) {
    
    List_student* ls = initList();
    
    Student* s1 = createStudent("Tom", 16);
    Student* s2 = createStudent("Mary", 15);
    
    addStudentList(ls, s1);
    addStudentList(ls, s2);

    printStudentList(ls);
    
//    Student* s = NULL;
//    int ret = getStudentList(ls, "Mary2", &s);
//    if (ret == 1) {
//        printf("found student info:\n");
//        printStudentInfo(s);
//    }
//    else{
//        printf("not found student...\n");
//    }
    
    
    freeStudentList(&ls);
    
    
    printf("hello...\n");
    return 0;
}
