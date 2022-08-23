#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//通讯录
//1.存放1000个好友的信息
//信息包含，姓名，性别，电话，住址，年龄
//2.增加好友信息
//3.删除好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息
//7.排序

void menu() {
	printf("*************************************************\n");
	printf("***********          Contacts        ************\n");
	printf("***********    已有功能对应如下：    ************\n");
	printf("***********    1.add      2.del      ************\n");
	printf("***********    3.search   4.modify   ************\n");
	printf("***********    5.show     6.sort     ************\n");
	printf("***********    0.exit                ************\n");
	printf("*************************************************\n");
}

int main() {
	int input;
	struct Contact con;	//包含两部分信息，一部分是1000个人的数组，另一个部分是size
	InitContact(&con);
	do {
		menu();
		printf("请输入数字以继续：");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			//int size = sizeof();
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录。\n");
			break;
		default:
			printf("输入错误。\n");
			break;
		}
	} while (input);

	return 0;
}

