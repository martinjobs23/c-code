//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void fun(int* p1, int* p2, int num) {
//	if (num == 1) {
//		if (*p1 < *p2) {
//			*p1 = *p2;
//		}
//		printf("较大值为%d\n", *p1);
//	}
//	else if (num == 2) {
//		if (*p1 < *p2) {
//			*p2 = *p1;
//		}
//		printf("较小值为%d\n", *p2);
//	}
//	else if(num ==3) {
//		printf("两个操作数和为%d。\n",*p1+*p2);
//	}
//	else
//		printf("输入错误\n");
//}
//int main() {
//	int a, b;
//	int num;
//	int* pa = &a;
//	int* pb = &b;
//	printf("请选择所需操作，输入1求较大值，输入2求较小值，输入3求和。\n");
//	scanf("%d", &num);
//	printf("请输入两个操作数：");
//	scanf("%d%d", pa, pb);
//	fun(pa, pb, num);
//
//	return 0;
//}