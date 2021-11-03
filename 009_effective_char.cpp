#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='}'||s[i]==']'||s[i]==')'){//if it is RIGHT character
                if(stk.empty())return false;
                if(s[i]=='}'&&stk.top()=='{')stk.pop();
                else if(s[i]==']'&&stk.top()=='[')stk.pop();
                else if(s[i]==')'&&stk.top()=='(')stk.pop();
                else return false;
            }
            else {                          //if it is LEFT character
                if(s[i]=='{'){
                    if(stk.empty()||stk.top()=='{'||stk.top()=='['||stk.top()=='(')stk.push(s[i]);
                    else return false;
                }
                if(s[i]=='['){
                    if(stk.empty()||stk.top()=='['||stk.top()=='{'||stk.top()=='(')stk.push(s[i]);
                    else return false;
                }
                if(s[i]=='('){
                    if(stk.empty()||stk.top()=='{'||stk.top()=='['||stk.top()=='(')stk.push(s[i]);
                    else return false;
                }
            }
        }

        if(stk.empty())return true;
        return false;
    }
};
