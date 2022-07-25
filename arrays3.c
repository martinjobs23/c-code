//
//  main.c
//  arrays3
//
//  Created by DFH on 2022/7/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,i,j,k;
    printf("Enter n:");
    scanf("%d",&n);
    if (n<0||n>10) {
        printf("Error.\n");
    }
    int a[n][n];
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("转置后：\n");
    for (i=0; i<n; i++) {
        for (j=0; j<i; j++) {
            k=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=k;
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
