#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//ͨѶ¼
//1.���1000�����ѵ���Ϣ
//��Ϣ�������������Ա𣬵绰��סַ������
//2.���Ӻ�����Ϣ
//3.ɾ��������Ϣ
//4.���Һ�����Ϣ
//5.�޸ĺ�����Ϣ
//6.��ӡ������Ϣ
//7.����

void menu() {
	printf("*************************************************\n");
	printf("***********          Contacts        ************\n");
	printf("***********    ���й��ܶ�Ӧ���£�    ************\n");
	printf("***********    1.add      2.del      ************\n");
	printf("***********    3.search   4.modify   ************\n");
	printf("***********    5.show     6.sort     ************\n");
	printf("***********    0.exit                ************\n");
	printf("*************************************************\n");
}

int main() {
	int input;
	struct Contact con;	//������������Ϣ��һ������1000���˵����飬��һ��������size
	InitContact(&con);
	do {
		menu();
		printf("�����������Լ�����");
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
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);

	return 0;
}

