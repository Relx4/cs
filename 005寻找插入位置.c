/*From Leetbook*/
#include <stdio.h>
#include <stdlib.h>
int searchInsert(int* nums, int numsSize, int target){
    int i=0;
    while(i<numsSize&&nums[i]<target){
        ++i;
    }
    return i;
}
