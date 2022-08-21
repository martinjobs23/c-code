//
//  main.c
//  array_copy
//
//  Created by DFH on 2022/8/21.
//

#include <stdio.h>
#include <string.h>
////输入一组数，让奇数在前，偶数在后
////输入
//void scan(int a[],int *p){
//    int i = 0;
//    while(1){
//        scanf("%d",&a[i]);
//        i++;
//        char ch = getchar();
//        if (ch == '\n') {
//            break;
//        }
//    }
//    *p = i;
//}
////判断奇数偶数，并加到两组数列中。
//int move_num(int a[],int num){
//    int arr1[30] = {0};
//    int arr2[30] = {0};
//    int i = 0;
//    int n1,n2;
//    n1 = n2 = 0;
//    for (i = 0; i<num; i++) {
//        if (a[i]%2 == 1) {
//            arr1[n1] = a[i];
//            n1++;
//        }
//        else{
//            arr2[n2] = a[i];
//            n2++;
//        }
//    }
////    for (i = 0; i<num; i++) {
////        printf("%d ",arr1[i]);
////    }for (i = 0; i<num; i++) {
////        printf("%d ",arr2[i]);
////    }
//    //拼接两个数组
//    for (i = 0; i<n1; i++) {
//        a[i] = arr1[i];
//    }
//    for (i = 0; i<num; i++) {
//        a[n1+i] = arr2[i];
//    }
//    return n1;
//}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    //printf("Hello, World!\n");
//    int a[30] = {0};
//    int num = 0;
//    int n1;
//    printf("请输入数字，用空格隔开，回车以结束：");
//    scan(a,&num);
//    n1 = move_num(a, num);
//    printf("共有%d个奇数，%d个偶数。\n",n1,num-n1);
//    for (int i = 0; i<num; i++) {
//        printf("%d ",a[i]);
//    }
//    return 0;
//}

//输入一组字符串，实现字符串左移右移操作
void left_move(char *str,int k){
    char str2[30];
    int l = strlen(str);
    int i = 0;
    strcpy(str2, str);
    for (i = 0; i<l-k; i++) {
        *(str+i) = *(str2+k+i);
    }
    for (i = 0; i < k; i++) {
        *(str+l-k+i) = *(str2+i);
    }
}
void right_move(char *str,int k){
    char str2[30];
    int l = strlen(str);
    int i = 0;
    strcpy(str2, str);
    for (i = 0; i < k; i++) {
        *(str+i) = *(str2+l-k+i);
    }
    for (i = 0; i < l-k; i++) {
        *(str+k+i) = *(str2+i);
    }
}
int main (){
    char str[30] ={0};
    printf("请输入一组字符串，按回车结束\n");
    gets(str);
    char ch;
    int k = 0;
    printf("请输入左移右移操作，l代表左移，r代表右移：");
    scanf("%c",&ch);
    if (ch == 'l' || ch == 'r') {
        printf("请输入移动几个字符：");
        scanf("%d",&k);
        if (ch == 'l') {
            left_move(str,k);
            puts(str);
        }else if (ch == 'r'){
            right_move(str,k);
            puts(str);
        }
    }
    else
        printf("输入错误，未进行操作。\n");
    return 0;
}

