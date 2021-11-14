#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > q;
        for(int i=0;i<(int)nums.size();++i){
            q.push(nums[i]);
        }//put the numbers into priority_queue
        int num=0;
        for(int i=0;i<k;++i){
            num=q.top();
            q.pop();
        }
        return num;
    }
};
/*
在这道题中，使用了优先队列的方法。优先队列室一种可以自动排序的队列，也算是
一种很简单的堆。
常用的有两种：
priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int, vector<int>, less<int> > q2;
第一种递减排列，第二种递增排列
*/
