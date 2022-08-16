//
//  main.c
//  Sort_test
//
//  Created by DFH on 2022/8/16.
//

#include <stdio.h>

void scan(int a[]){
    int i = 0;
    for (i = 0; i<100; i++) {
        scanf("%d",&a[i]);
        if (a[i] == '\n')
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    //int a[21] = {280,158,222,309,361,413,252,440,308,288,194,129,387,163,334,165,160,161,164,162,468};
    int a[100];
    scan(a);
    int i = 0;
    int j = 0;
    for (i = 0; i<20; i++) {
        for (j = 0; j<20-i; j++) {
            if(a[j]>a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (i = 0; i<21; i++) {
        printf("%d ",a[i]);
    }
    
    return 0;
}
