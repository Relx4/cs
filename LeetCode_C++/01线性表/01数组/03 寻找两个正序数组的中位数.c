#include<stdio.h>
#include<stdlib.h>
int Min(int a, int b){
    return a>b?b:a;
}
int findKth(int* a, int m, int* b, int n, int k){
    if(m>n)return findKth(b, n, a, m, k);
    if(m==0)return *(b+k-1);
    if(k==1)return Min(*a, *b);
    /*能弄明白下面这段代码为什么要用+1,-1,或者不用，那么你就真的懂得了这段代码*/
    int ia=Min(k/2, m);
    int ib=k-ia;
    if(*(a+ia-1)<*(b+ib-1))return findKth(a+ia, m-ia, b, n, k-ia);
    else if(*(a+ia-1)>*(b+ib-1))return findKth(a, m, b+ib, n-ib, k-ib);
    return *(a+ia-1);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    const int total = nums1Size+nums2Size;
    if(total%2!=0)return (double)findKth(nums1, nums1Size, nums2, nums2Size, (total+1)/2);
    double ren=0;
    ren=findKth(nums1, nums1Size, nums2, nums2Size, total/2)+findKth(nums1, nums1Size, nums2, nums2Size, total/2+1);
    ren=ren/2.0;
    return ren;
}
