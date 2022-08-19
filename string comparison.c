//
//  main.c
//  string comparison
//
//  Created by DFH on 2022/8/18.
//

#include <stdio.h>
#include <string.h>
//编写程序，用指针实现读入字符串s，字符串s1，字符串s2，如果s1是字符串s的子串，则用s2代替s中的s1，并打印结果字符串
void fun1(char *s,char*s1,char*s2){
    //判断是否符合条件
    char*first = strstr(s, s1);
    if (first == NULL) {
        printf("s1不是s的子串，未进行任何操作。\n");
        puts(s);
        
    }else{
        char temp[40];
        int len1 = strlen(s1);
        int i = first - s;
        //printf("%d %d\n",k,l);
        int j = 0;
        for (j = 0;j < i ;j++) {
            *(temp+j) = *(s+j);
        }
        *(temp+i) = '\0';
        strcat(temp, s2);
        strcat(temp, (first+len1));
//        for (j = 0; j<k; j++) {
//            *(temp+l+j) = *(s-k+j);
//        }
//        *(temp+i+j) = '\0';
        strcpy(s, temp);
        puts(s);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    char ch;
    char s[20],s1[20],s2[20];
    printf("请输入字符串s：\n");
    gets(s);
    printf("请输入字符串s1：\n");
    gets(s1);
    printf("请输入字符串s2：\n");
    gets(s2);
    fun1(s,s1,s2);
    return 0;
}
