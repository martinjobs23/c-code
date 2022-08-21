//
//  main.c
//  Pointer_Strcpy
//
//  Created by DFH on 2022/8/19.
//

#include <stdio.h>
#include <string.h>

//编写程序，将字符串中的第m个字符开始的全部自负复制成另一个字符串。在主程序中输入m并输出字符串，在子程序中完成复制
void my_strcpy(char*s1,char*s2,int m){
    strcpy(s2,(s1+m-1));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    char s1[20] = {0},s2[20] = {0};
    int m;
    printf("请输入想要被复制的字符串，回车结束：\n");
    gets(s1);
    printf("请输入想要从第几位字符开始复制字符串：\n");
    scanf("%d",&m);
    my_strcpy(s1,s2,m);
    puts(s2);
    return 0;
}
