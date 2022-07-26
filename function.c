//
//  main.c
//  function
//
//  Created by DFH on 2022/7/15.
//

#include <stdio.h>
#include <math.h>


int main() {
    char str[100];
    gets(str);
    void fun(char ch[]);
    fun(str);
    return 0;
    
}
void fun(char ch[]){
    int currectloc,maxloc,currectlen,maxlen;
    currectlen=currectloc=0;
    maxlen=maxloc=0;
    int i=0,j=0;
    for (i=0; ch[i]; i++) {
        if ((ch[i]>='a'&&ch[i]<='z')||((ch[i]>='A'&&ch[i]<='Z'))||(ch[i]>='0'&&ch[i]<='9')) {
            if (currectlen==0) {
                currectloc=i;
            }
            currectlen++;
        }
        if (currectlen>maxlen) {
            maxlen=currectlen;
            maxloc=currectloc;
        }
        if (ch[i]==' ') {
            currectlen=0;
        }
    }
    
    for (j=maxloc; j<maxloc+maxlen; j++) {
        printf("%c",ch[j]);
    }
   
}

