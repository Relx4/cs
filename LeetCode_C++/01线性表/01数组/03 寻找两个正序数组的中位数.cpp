/*暴力求解的方法因为超时而失败（因为限制了时间复杂度）*/
/*本题中的方法，完全来自刷题指导。说实话，这道题真的很难，尽管知道了大的方向，*/
/*要想把控好每一个细节，还是很难的*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m=nums1.size();
        const int n=nums2.size();
        int total=m+n;
        if(total%2!=0)return findKth(nums1.begin(),m,nums2.begin(),n,total/2+1);/*如果有7个数，中位数肯定是第4大的*/
        return (findKth(nums1.begin(),m,nums2.begin(),n,total/2)+findKth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
        /*如果有8个数，中位数一定是*/
    }
private:
    int findKth(std::vector<int>::const_iterator a, int m, std::vector<int>::const_iterator b, int n, int k){
        if(m>n)return findKth(b, n, a, m, k);
        if(m==0)return *(b+k-1);
        if(k==1)return min(*a, *b);   
        /*special issus done*/
        int ia=min(k/2,m);
        int ib=k-ia;
        if(*(a+ia-1)<*(b+ib-1)){
            return findKth(a+ia,m-ia,b,n,k-ia);
        }
        else if(*(a+ia-1)>*(b+ib-1)){
            return findKth(a,m,b+ib,n-ib,k-ib);
        }
        return *(a+ia-1);
    }
};