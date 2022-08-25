//
//  Contact.h
//  Contact
//
//  Created by DFH on 2022/8/24.
//

#ifndef Contact_h
#define Contact_h

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

//#define MAX 100
#define DEFINE_SZ 3
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30

enum Options
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    SAVE
};

//信息包含，姓名，性别，电话，住址，年龄
struct PeoInfo {
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
    int age;
};
 
struct Contact {
    struct PeoInfo *data;
    int capacity;   //当前通讯录的容量，默认3个，动态增加以2个为标准
    int size;
};

void InitContact(struct Contact *ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void ShowContact( const struct Contact* ps);
void SortContact(struct Contact* ps);
void DestoryContact(struct Contact* ps);
void SaveContact(struct Contact* ps);
void LoadContact(struct Contact* ps);

#endif /* Contact_h */
