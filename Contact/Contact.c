#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include<stdlib.h>

static int search_by_name(const struct Contact* ps,char name[MAX_NAME]) {
	int i = 0;
	int ret = -1;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(name, ps->data[i].name) == 0) {
			ret = i;
			break;
		}
	}
	return ret;
}
static int cmp_by_age(const void* e1, const void* e2) {
	return ((struct	Contact*)e1)->data->age - ((struct	Contact*)e2)->data->age;
}
static int cmp_by_name(const void* e1, const void* e2) {
	return strcmp(((struct	Contact*)e1)->data->name , ((struct	Contact*)e2)->data->name);
}

void InitContact(struct Contact* ps) {
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;
}
void AddContact(struct Contact* ps) {
	if (ps->size == MAX-1) {
		printf("通讯录已满，无法继续增加。\n");
	}
	else {
		printf("请输入姓名:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入住址:");
		scanf("%s", ps->data[ps->size].addr);
		//ps中的size++
		ps->size++;
		printf("增加成功。\n");
	}
}
void DelContact(struct Contact* ps) {
	printf("请输入要删除的人的姓名：");
	char name[MAX_NAME];
	scanf("%s", name);
	int ret = search_by_name(ps,name);
	if (ret == -1) {
		printf("未找到需要删除的人。\n");
	}
	else {
		int j = 0;
		for ( j = ret; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功。\n");
	}
}
void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要查找人的姓名：");
	scanf("%s", name);
	int ret = search_by_name(ps, name);
	if (ret == -1) {
		printf("未找到需要查找的人。\n");
	}
	else {
		printf("%-20s\t%-4s\t%-10s\t%-15s\t%-30s\n","姓名","年龄","性别","电话","地址");
		printf("%-20s\t%-4d\t%-10s\t%-15s\t%-30s\n", ps->data[ret].name, ps->data[ret].age, ps->data[ret].sex, ps->data[ret].tele, ps->data[ret].addr);
	}
}
void ModifyContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要查找人的姓名：");
	scanf("%s", name);
	int ret = search_by_name(ps, name);
	if (ret == -1) {
		printf("未找到需要修改的人。\n");
	}
	else {
		printf("请输入姓名:");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别:");
		scanf("%s", ps->data[ret].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[ret].tele);
		printf("请输入住址:");
		scanf("%s", ps->data[ret].addr);
		printf("修改成功。\n");
	}
}
void ShowContact(const struct Contact* ps) {
	if (ps->size == 0) {
		printf("通讯录为空。\n");
	}
	else {
		int i = 0;
		printf("%-20s\t%-4s\t%-10s\t%-15s\t%-30s\n","姓名","年龄","性别","电话","地址");
		for ( i = 0; i < ps->size; i++)
		{
		//printf("姓名		性别	电话		住址		年龄");
			printf("%-20s\t%-4d\t%-10s\t%-15s\t%-30s\n", ps->data[i].name, ps->data[i].age,ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
		}
	}
}
void SortContact(struct Contact* ps) {
	printf("请输入按照何种方式排序，选择1用姓名排序，选择2用年龄排序：");
	int input;
	scanf("%d",&input );
	if (input == 1) {
		qsort(ps,ps->size,sizeof(ps->data[0]),cmp_by_name);
		printf("按照姓名排序成功。\n");
		ShowContact(ps);
	}
	else if (input == 2) {
		qsort(ps,ps->size,sizeof(ps->data[0]), cmp_by_age);
		printf("按照年龄排序成功。\n");
		ShowContact(ps);
	}
	else {
		printf("输入错误，排序失败。\n");
		ShowContact(ps);
	}

}
