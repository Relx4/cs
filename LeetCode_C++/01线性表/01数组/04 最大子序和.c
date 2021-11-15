#include<stdio.h>
#include<stdlib.h>
int maxSubArray(int* nums, int numsSize){
    if(numsSize==0)return 0;
    if(numsSize==1){
        if(*nums>=0)return *nums;
        else return 0;
    }
    int leftMax=maxSubArray(nums, numsSize/2+1);
    int rightMax=maxSubArray(nums+numsSize/2+1, numsSize/2-1);

}
