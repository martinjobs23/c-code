
#pragma once
#include<stdio.h>
#include<string.h>

#define MAX 100
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
	SORT
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
	struct PeoInfo data[MAX];
	int size;
};

void InitContact(struct Contact *ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void ShowContact( const struct Contact* ps);
void SortContact(struct Contact* ps);