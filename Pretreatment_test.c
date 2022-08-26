#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

extern int Add(int x, int y);
int main() {
	int arr[10] = {0};
	int i = 0;
	FILE* pf = fopen("log.txt", "w");
	for (i = 0; i < 10; i++) {
		arr[i] = i;
		fprintf(pf, "file:%s line:%d time:%s i = %d\n", __FILE__, __LINE__, __TIME__, i);
	}
	fclose(pf);
	pf = NULL;
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	/*int a = 10;
	int b = 20;
	int sum = Add(a, b);
	printf("%d", sum);*/
	return 0;
}