#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//编写一函数，完成一个字符串的拷贝，要求用字符指针实现。在主函数中输入任意字符串，并显示原字符串，调用该函数之后输出拷贝后的字符串。
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
//编写一函数，求一个字符串的长度，要求用字符指针实现。在主函数中输入字符串，调用该函数输出其长度。
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
	printf("该字符串共有%d个字符。\n",*pn);
	return 0;
}
