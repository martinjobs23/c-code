#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main() {
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	char ch[100] = {0};
//	fgets(ch,100,pf);
//	printf("%s", ch);
//	fgets(ch, 100, pf);
//	puts(ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main() {
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	char ch[100] = { "hello,\n"};
//	fputs(ch, pf);
//	fputs("world", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S {
//	int n;
//	float score;
//	char arr[20];
//};

//int main() {
//	struct S s = {100,3.14f,"hello,world"};
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL) {
//				printf("%s", strerror(errno));
//				return 0;
//			}
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main() {
//	struct S s = {0};
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL) {
//				printf("%s", strerror(errno));
//				return 0;
//			}
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &s.arr);
//	printf("%d %f %s", s.n, s.score, s.arr);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main() {
//	struct S s = {100,3.14f,"hello,world"};
//	char buf[200] = { 0 };
//	sprintf(buf, "%d,%f,%s", s.n, s.score, s.arr);
//	printf("%s" ,buf);
//	return 0;
//}
struct S
{
	char name[20];
	int age;
	double score;
};
int main() {
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL) {
		printf("%s", strerror(errno));
		return 0;
	}
	//struct S s = {"zhangsan",20,99.78};
	//fwrite(&s, sizeof(struct S), 1, pf);
	struct S s = { 0 };
	fread(&s, sizeof(struct S), 1, pf);
	printf("%s %d %lf", s.name, s.age, s.score);

	fclose(pf);
	pf = NULL;
	return 0;
}
