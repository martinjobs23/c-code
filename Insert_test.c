//
//  main.c
//  Insert_test
//
//  Created by DFH on 2022/8/18.
//

#include <stdio.h>
void scan(int a[],int n){
    int i = 0;
    for (i = 0; i<n; i++) {
        scanf("%d",&a[i]);
    }
}
void sort(int a[],int num){
    int i = 0;
    int j = 0;
    for (i = 0; i<num-1; i++) {
        int flag = 0;
        for (j = 0; j<num-1-i; j++) {
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}
void insert_num(int a[],int b[],int n,int ins){
    int i =0;
    int flag = 0;
    for (i = 0; i < n; i++) {
        if (ins < a[i]) {
            flag = i;
            break;
        }
    }
    for (i = 0; i<n+1; i++) {
        if (i<flag) {
            b[i] = a[i];
        }else if(i == flag){
            b[i] = ins;
        }else{
            b[i] = a[i-1];
        }
        
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int n;
    int i = 0;
    printf("请输入要排序的数组的元素数：\n");
    scanf("%d",&n);
    int a[n];
    printf("请输入要排序的数组：\n");
    scan(a,n);  //输入这个数组
    sort(a, n); //对这个数组进行排序
    printf("排序后的数组为：\n");
    for (i = 0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    int a2[n+1];
    int ins;
    printf("请输入要插入的数字：\n");
    scanf("%d",&ins);
    insert_num(a,a2,n,ins);
    printf("插入后的数组为：\n");
    for (i = 0; i<n+1; i++) {
        printf("%d ",a2[i]);
    }
    printf("\n");
    return 0;
}
