/*Randolph Lee  20211114 14:31*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strv;
        int numsLength=nums.size();
        for(int i=0;i<numsLength;++i){
            strv.push_back(to_string(nums[i]));
        }
        /*
        *把两个未知位数的数字拼接，可能会有很多麻烦，一个最好的办法，就是转化成string，然后
        *string A + string B，就得到了“拼接”的结果。
        *这道题想让总拼接效果最小，说白了就是排序，排序的原则是：
        *如果 A + B > B + A，说明A比B大，为了最小化，应该把B放到前面
        */
        int strvLength=strv.size();
        /*排序模块开始，可以选用效率更高的排序，这里使用最简单的冒泡排序*/
        for(int i=0;i<strvLength-1;i++){
            for(int j=0;j<strvLength-1-i;j++){
                if(strv[j]+strv[j+1]>strv[j+1]+strv[j]){
                    std::swap(strv[j],strv[j+1]);
                }
            }
        }
        /*排序模块结束*/
        string res;
        for(string s : strv){
            res+=s;
        }
        return res;
    }
};
/*病理学考试加油……该去吃第二顿饭了……*/
