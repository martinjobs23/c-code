//
//  main.c
//  test
//
//  Created by DFH on 2022/7/21.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void hello(){
    printf("********************************\n");
    printf("*********欢迎来到猜数字游戏********\n");
    printf("*********请输入数字以开始*********\n");
    printf("******  1.play  0.exit    ******\n");
    printf("********************************\n");
}
void game(){
    int random;
    int guess=0;
    random = rand()%101;    //0-100之间的数字
    
    //printf("%d\n",random);
    while (1) {
        printf("请输入你要猜测的数字：");
        scanf("%d",&guess);
        if (random>guess) {
            printf("猜测的数字小了。\n请重新猜测。\n");
        }else if (random<guess)
            printf("猜测的数字大了。\n请重新猜测。\n");
        else{
            printf("恭喜你猜中了！");
        break;
        }
    }
    
}
int main(int argc, const char * argv[]) {
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        hello();
        scanf("%d",&input);
        switch (input) {
            case 1:printf("游戏开始。\n");
                game();
                break;
            case 0:printf("游戏结束。\n");
                break;
            default:printf("输入错误，请重新输入数字。\n");
                break;
        }
    }while(input);
    
}
