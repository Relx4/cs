#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3)return result;
        sort(nums.begin(), nums.end());/*sort STL*/
        const int target = 0;
        auto last = nums.end();/*迭代器*/
        /*接下来，请注意，一定要“跳过相同的值”，从而提高算法效率，也避免结果重复导致出错*/
        for(auto i = nums.begin(); i<last-2; ++i){
            if(i>nums.begin() && *i==*(i-1))continue;/*若i移动后和没移动是一样的值，那就继续移动*/
            auto j=i+1;
            auto k=last-1; /*已经确保了至少有三个元素，所以初始值肯定是有意义的*/
            while(j<k){
                if(*i + *j + *k < target){
                    j++;
                    while(*j==*(j-1) && j<k)j++;/*跳过重复的j,j<k是避免后面全都一样，j不断增大至无意义*/
                }/*如果小，就右移j；如果大，就左移动k*/
                else if(*i + *j + *k > target){
                    k--;
                    while(*k==*(k+1) && k>j)k--;
                }
                else {
                    result.push_back({*i, *j, *k});
                    /*然后移动j和k*/
                    j++;
                    k--;
                    while(*j==*(j-1)&&j<k)j++;/*跳过相同的数*/
                    while(*k==*(k+1)&&k>j)k--;/*同样是跳过相同的数*/
                }

            }/*while circle end*/

        }/*for circle end*/
        return result;
    }
};
