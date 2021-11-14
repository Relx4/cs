#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    void makeit(vector<int>& v, TreeNode* root){
        if(root){
            v.push_back(root->val);
            makeit(v,root->left);
            makeit(v,root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> v;
        makeit(v,root);
        return v;
    }
};
/*
Q：为什么要把主体函数和排序函数拆开？
A：如果不这样的话，每一次递归，都会重新定义一个新的vector类，最后返回的只是最开始的那个vector，
里面只有第一个root结点，这并不是想要的;
Q：为什么makeit()函数要传入vector的引用而不是vector？
A：要对主体函数的vector进行更改（push_back)，自然是要传引用进去。
*/
