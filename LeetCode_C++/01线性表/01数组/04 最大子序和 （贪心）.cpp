#include<iostream>
#include<vector>
using namespace std;
/*贪心算法*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int thisSum=0;
        int maxSum=nums[0];
        int length=nums.size();
        for(int i=0;i<length;i++){
            thisSum+=nums[i];
            maxSum=max(thisSum,maxSum);
            if(thisSum<=0)thisSum=0;
        }
        return maxSum;
    }
};
