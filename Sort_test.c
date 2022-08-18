//
//  main.c
//  Sort_test
//
//  Created by DFH on 2022/8/16.
//
#include <stdio.h>
void scan(int a[],int *pc){
    int i = 0;
    int tmp;
    for (i = 0; i<100; i++) {
        scanf("%d",&tmp);
        a[i] = tmp;
        (*pc)++;
        char c = getchar();
        if (c == '\n'){
            break;
        }
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
int sum(int a[],int num){
    int i = 0;
    int s = 0;
    for (i = 0; i<num; i++) {
        s = s +a[i];
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    int a[100];
    int count = 0;
    int *pc = &count;
    scan(a,pc);
    printf("共有%d个数字。排序后为：\n",count);
    int i = 0;
    sort(a,count);
    int s = sum(a,count);
    double avg = (double)s/count;
    for (i = 0; i<count; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("数列的和为%d，数列的平均数为%.2lf，最小值为%d，最大值为%d。\n",s,avg,a[0],a[count-1]);

    return 0;
}
//int main(){
//    int num;
//    int i=0;
//    int arr[10];
//   while(1){
//        scanf("%d",&num);
//        char c=getchar();
//        arr[i++]=num;
//        if(c=='\n'){
//            break;
//        }
//   }
//   /*for(int i=0;i<10;i++){
//    printf("%d\n",arr[i]);
//   }*/
//  return 0;
//}

