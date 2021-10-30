#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    int i=0;
    int j=0;
    char* temp=(char*)malloc(sizeof(char)*200);
    int test=1;
    int num=0;
    int minline=(int)strlen(strs[0]);
    for(int i=0;i<strsSize;i++){
        if((int)strlen(strs[i])<minline)minline=strlen(strs[i]);
    }
    while(j<minline){
        test=1;
        i=0;
        while(i<strsSize-1){
            if(strs[i][j]!=strs[i+1][j])test=0;
            ++i;
        }
        if(test==1){
            temp[num]=strs[0][j];
            ++num;
        }
        else break;//如果test==0,说明已经有不相同的部分了，那么程序停止
        ++j;
    }
    temp[num]='\0';
    return temp;
}
/*from Leetbook   Randolph Lee*/
