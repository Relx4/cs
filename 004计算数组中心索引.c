/*Leetbook <数组与字符串>*/
#include<stdio.h>
#include<stdlib.h>
int pivotIndex(int* nums, int numsSize){
    int leftSum=0;
    int rightSum=0;
    int i,j;
    int index=0;
    while(index<numsSize){
        leftSum=0;
        rightSum=0;
        for(i=0;i<index;i++)leftSum+=nums[i];
        for(j=numsSize-1;j>index;j--)rightSum+=nums[j];
        if(leftSum==rightSum)return index;
        ++index;
    }
    return -1;
}
