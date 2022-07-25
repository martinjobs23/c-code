//
//  main.c
//  arrays4
//
//  Created by DFH on 2022/7/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,i,j,k;
    printf("Enter n:\n");
    scanf("%d",&n);
    int a[n];
    printf("input %d numbers:\n",n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (a[j]>a[j+1]) {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    printf("After sorted:\n");
    for (i=0; i<n; i++) {
        printf("%d  ",a[i]);
    }
    printf("\n");
    int a2[n+1];
    int p,q;
    p=q=0;
    printf("which number do you want to put in?Enter the number:\n");
    scanf("%d",&p);
    for (i=0; i<n+1; i++) {
        a2[i]=a[i];
        if(a[i]>p){
            q=i;
            break;
        }
    }
    for (i=n+1;i>=q;i--) {
        a2[i]=a[i-1];
    }
    a2[q]=p;
    printf("After sorted:\n");
    for (i=0; i<n+1; i++) {
        printf("%d  ",a2[i]);
    }
    printf("\n");
    
}

