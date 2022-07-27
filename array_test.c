//
//  main.c
//  array_test
//
//  Created by DFH on 2022/7/26.
//

#include <stdio.h>


void buzzle_sort(int arr[],int sz){
    int i = 0,j = 0;
    for (i=0; i<sz-1; i++) {
        int flag = 1;   //假设本次排序已经是有序的了
        for (j=0; j<sz-1-i; j++) {
            if (arr[j]<arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 0;   //本次排序非有序排列，需要调换内容
            }
        }
        if (flag ==1) { //已经排好顺序，不需要调整
            break;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    buzzle_sort(arr,sz);
    for (i=0; i<sz; i++) {
        printf("%d  ",arr[i]);
        
    }
    
}
