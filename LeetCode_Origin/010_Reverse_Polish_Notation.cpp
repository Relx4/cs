#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;
//使用atoi()函数，可以将字符串转化为整数
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<(int)tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")stk.push(atoi(tokens[i]));

        }
    }
};
