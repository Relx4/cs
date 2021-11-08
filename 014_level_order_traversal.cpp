/*
*   这道题目有一些难度，主要是对于vector的基本使用方法了解不清楚;
*   另外还有一个需要注意的是，这道题要求返回二维数组，而不是返回一维数组，
*   也就是说，单纯打印是不行的，还要会分层。。。
*   所以就是用了双层循环，第一层while大循环控制整个树是否读完，
*   第二个for循环控制“把这层的结点遍历结束之后就结束”，我们使用的策略是，
*   在第一次进入while循环之前，求queue的长度，这个长度就是这一层要用来操作的
*   结点，那么控制循环queue.size()次数就好了。。。
*   等for循环结束，也就是这一层结点操作完，再进入while循环来操作新的一层结点，
*   就再求一次queue.size()，用于控制新的for循环，以此类推。。。
*/
#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> v;
        std::queue<TreeNode*> q;
        if(root==nullptr)return v;
        q.push(root);
        while(!q.empty()){
            int queueLen=q.size();
            v.push_back(vector<int>());//在后面加一个空的一维数组
            for(int i=0;i<queueLen;++i){
                TreeNode* T=q.front();
                q.pop();
                v.back().push_back(T->val);//v.back()是访问最后的元素（这里是最后的一维数组）
                if(T->left)q.push(T->left);
                if(T->right)q.push(T->right);
            }
        }
        return v;
    }
};
