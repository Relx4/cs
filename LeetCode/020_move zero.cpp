/*LeetCode 第283题 移动零*/
/*Randolph Lee  20211114*/
#include<iostream>
#include<vector>
using namespace std;
/*
下面是我的答案:
执行效率、空间利用率都非常低，
我会在末尾附上标准答案
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size()){
            for(;i<nums.size()&&nums[i]!=0;++i);
            for(j=i+1;j<nums.size();++j){
                if(nums[j]!=0){
                Swap(nums[i], nums[j]);
                break;
                }
            }/*find the nearst non-zero val to exchange*/
            ++i;
        }
    }
    void Swap(int& a, int& b){
        a=a+b;
        b=a-b;
        a=a-b;
    }
};
/*以下是Leetbooc中的标准答案*/
class Soolution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount=0;
        for(int i=0;i<nums.size()-zeroCount;++i){
            if(nums[i]==0){
                for(int j=i;j<nums.size()-1-zeroCount;++j){
                    Swap(nums[j],nums[j+1]);
                }
                ++zeroCount;
                --i;/*与后面元素依次交换位置之后，并不能保证没有换0下来，因此i--，再次检查这个位置*/
            }
        }
    }
    void Swap(int& a, int& b){
        int temp=a;
        a=b;
        b=temp;
    }
};
/*标准的冒泡排序效率仍然非常低，这里使用双指针方法：*/
class Sooolution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        int numsLength=nums.size();/*避免反复计算浪费时间*/
        while(right<numsLength){
            if(nums[right]){
                std::swap(nums[left],nums[right]);/*没必要自己写swap函数*/
                ++left;/*处理了一个，已处理序列延长，left指针向右移动，继续处理*/
            }
            ++right;/*进行完0和非0的判断，右移，继续判断*/
        }
    }
};
