#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��дһ���������һ���ַ����Ŀ�����Ҫ�����ַ�ָ��ʵ�֡��������������������ַ���������ʾԭ�ַ��������øú���֮�������������ַ�����
//void my_strcpy(char* str1, char* str2, int num) {
//	int i = 0;
//	for ( i = 0; i < num; i++) {
//		*(str2 + i) = *(str1 + i);
//	}
//	*(str2 + i) = '\0';
//
//}
//
//int main() {
//	char str[100];
//	char str2[100];
//	gets(str);
//	int sz = strlen(str);
//	my_strcpy(str, str2,sz);
//	puts(str2);
//	return 0;
//}
// 
//��дһ��������һ���ַ����ĳ��ȣ�Ҫ�����ַ�ָ��ʵ�֡����������������ַ��������øú�������䳤�ȡ�
int my_strlen(char* str, int* p) {
	while (*str != '\0') {
		(*p)++;
		str++;
	}
	return *p+1;
}
int main() {
	char str[100];
	int num = 0;
	int* pn = &num;
	gets(str);
	my_strlen(str, pn);
	printf("���ַ�������%d���ַ���\n",*pn);
	return 0;
}
