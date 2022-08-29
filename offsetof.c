//
//  main.c
//  offsetof_test
//
//  Created by DFH on 2022/8/29.
//

#include <stdio.h>
#include <stddef.h>

struct S{
    char c1;
    int a;
    char c2;
};
#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    struct S s;
    printf("%d\n",OFFSETOF(struct S, c1));
    printf("%d\n",OFFSETOF(struct S, a));
    printf("%d\n",OFFSETOF(struct S, c2));
    return 0;
}
