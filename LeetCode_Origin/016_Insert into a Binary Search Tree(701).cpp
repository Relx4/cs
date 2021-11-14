/*
701.平衡二叉树的插入
You are given the root node of a binary search tree (BST) and a value to insert into the tree.
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion.
You can return any of them.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree

Randolph Lee
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* T=root;
        if(T==nullptr){
            TreeNode* R=new TreeNode;
            R->val=val;
            R->left=nullptr;
            R->right=nullptr;
            T=R;
        }
        else{
            if(val<T->val)T->left=insertIntoBST(T->left, val);
            else T->right=insertIntoBST(T->right, val);
        }
        return T;
    }
};
