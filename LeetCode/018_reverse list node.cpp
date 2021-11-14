/**/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
     vector<int> reversePrint(ListNode* head) {
         stack<int> stk;
         vector<int> v;
         ListNode* T=head;
         while(T){
             stk.push(T->val);
             T=T->next;
         }
         for(int i=0;!stk.empty();++i){
             v.push_back(stk.top());
             stk.pop();
         }
         return v;
     }
};
