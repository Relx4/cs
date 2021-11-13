/*
450.删除平衡二叉树的结点
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
    Search for a node to remove.
    If the node is found, delete the node.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteIt(root, key);
    }
    TreeNode* deleteIt(TreeNode*& root, int key){
        if(root==nullptr)return nullptr;
        if(key>root->val)root->right=deleteIt(root->right, key);
        else if(key<root->val)root->left=deleteIt(root->left, key);
        else{
            if(root->left==nullptr)return root->right;
            if(root->right==nullptr)return root->left;
            TreeNode* Min=findMin(root->right);
            root->val=Min->val;
            root->right=deleteIt(root->right,Min->val);
        }
        return root;
    }
    TreeNode* findMin(TreeNode* root){
        if(root->left==nullptr)return root;
        return findMin(root->left);
    }
};
