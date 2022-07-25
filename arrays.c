//
//  main.c
//  arrays
//
//  Created by DFH on 2022/7/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    float a[5][3];
    float avg[5];
    float mean[3];
    int i,j;
    for (i=0; i<5; i++) {
        printf("请输入第%d位同学的三门科目的成绩。\n",i+1);
        avg[i]=0;
        for (j=0; j<3; j++) {
            scanf("%f",&a[i][j]);
            avg[i]=a[i][j]+avg[i];
        }
        avg[i]=avg[i]/j;
    }
    for (j=0; j<3; j++) {
        mean[j]=0;
        for (i=0; i<5; i++) {
            mean[j]+=a[i][j];
        }
        mean[j]=mean[j]/i;
    }
    printf("成绩1  成绩2  成绩3\n");
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            printf("%2f  ",a[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<5; i++) {
        printf("第%d位同学的平均成绩为%2f\n",i+1,avg[i]);
    }
    for (j=0; j<3; j++) {
        printf("第%d门科目的平均成绩为%2f\n",j+1,mean[j]);
    }
    
}
