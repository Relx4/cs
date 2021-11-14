/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
Randolph Lee 20211115 00:37
*/
#include<iostream>
#include<vector>
using namespace std;
/*个人认为题目中最重要的信息就是“有序数组”，以后如果遇到无序数组，直接STL排序即可*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int numsLength=nums.size();
        if(numsLength==0)return 0;/*鲁棒性*/
        for(int i=1;i<numsLength;i++){/*从i=1开始是因为i=0且index=0时无需比较*/
            if(nums[index]!=nums[i])nums[++index]=nums[i];
            /*将index既作为计数器，又作为下标，是非常巧妙的做法*/
        }
        return index+1;/*index没有计算第一个元素，应该加上*/
    }
};
