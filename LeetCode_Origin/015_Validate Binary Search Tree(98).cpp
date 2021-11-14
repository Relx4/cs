/*
Question:Given the root of a binary tree, determine if it is a valid binary search tree (BST)
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
Randolph Lee,
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorderTrans(root, v);
        for(int i=0;i<(int)v.size()-1;++i){
            if(v[i+1]<=v[i])return false;
        }/*检验中序遍历的结果是否是递增的*/
        return true;
    }
    void inorderTrans(TreeNode* root, vector<int>& v){
        if(root==nullptr)return;
        inorderTrans(root->left, v);
        v.push_back(root->val);
        inorderTrans(root->right, v);
    }/*中序遍历函数*/
};
