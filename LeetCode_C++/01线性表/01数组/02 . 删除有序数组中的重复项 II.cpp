/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
Randolph Lee 20211115 01:23
*/
#include<iostream>
#include<vector>
using namespace std;
/*以下解决方法是完全自己想出来的*/
/*也属于快慢指针法*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numsLength=nums.size();
        if(numsLength==0)return 0;
        int index=0;
        int count=0;
        for(int i=0;i<numsLength;i++){
            if(nums[i]==nums[index])count++;
            if(nums[i]!=nums[index]){
                if(count>=2){
                    nums[index+1]=nums[index];
                    index+=2;
                    nums[index]=nums[i];
                }
                else nums[++index]=nums[i];
                count=1;
            }
            if(i==numsLength-1&&count>=2){
                if(nums[i]==nums[0])index++;
                else nums[++index]=nums[i];
            }/*调试过程中注意到末尾数字、只有一个数字的序列，这两种特殊情况，单独处理之*/
        }/*for end*/
        return index+1;
    }
};
/*下面是参阅题解后改进的方法*/
