//
//  main.c
//  arrays2
//
//  Created by DFH on 2022/7/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j,k1,k2;
    int array[3][4];
    printf("请输入四个数字，重复三次。\n");
    for(i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            scanf("%d",&array[i][j]);
        }
    }
    k1=k2=0;
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            if (array[k1][k2]<array[i][j]) {
                k1=i;
                k2=j;
            }
        }
    }
    printf("您输入的数组为：\n");
    for(i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%d  ",array[i][j]);
        }
        printf("\n");
    }
    printf("最大值为%d，最大值的位置为array[%d][%d]。\n",array[k1][k2],k1,k2);
}
