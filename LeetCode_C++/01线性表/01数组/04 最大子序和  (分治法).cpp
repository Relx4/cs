#include<iostream>
#include<vector>
using namespace std;
/*分治法*/
/*效果不如贪心算法，最后超时*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelp(nums, 0, nums.size()-1);
    }
private:
    int maxSubArrayHelp(vector<int>& nums, int left, int right){
        if(left==right){
            return nums[left];
        }
        int mid=left+(right-left)/2;
        int leftMax=maxSubArrayHelp(nums, left, mid);
        int rightMax=maxSubArrayHelp(nums, mid+1, right);
        int middleMax=midMaxHelp(nums, left, right, mid);
        leftMax=max(leftMax, rightMax);
        middleMax=max(leftMax, middleMax);
        return middleMax;
    }
    int midMaxHelp(vector<int> nums, int left, int right, int mid){
        int leftSum=0;
        int leftMax=nums[mid];
        for(int i=mid; i>=left; i--){
            leftSum+=nums[i];
            leftMax=max(leftMax, leftSum);
        }
        int rightSum=0;
        int rightMax=nums[mid+1];
        for(int i=mid+1; i<=right; i++){
            rightSum+=nums[i];
            rightMax=max(rightMax, rightSum);
        }
        return leftMax+rightMax;
    }
};
