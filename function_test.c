//
//  main.c
//  function_test
//
//  Created by DFH on 2022/7/26.
//

#include <stdio.h>
#include <math.h>
#include "add.h"

int my_stringlen(char*arr){
    if(*(arr)!='\0'){
        return 1 +my_stringlen(arr+1);
    }else
        return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char arr[] = "abc123";
    int len = my_stringlen(arr);
    
    printf("%d",len);
}
