#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* List;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    List R1=l1;
    List R2=l2;
    List head=(List)malloc(sizeof(struct ListNode));
    List R=head;
    if(R1&&!R2)return l1;
    if(R2&&!R1)return l2;
    if(!R1&&!R2)return NULL;
    while(R1&&R2){
        List temp=(List)malloc(sizeof(struct ListNode));
        if(R1->val<=R2->val){
            temp->val=R1->val;
            temp->next=NULL;
            R->next=temp;
            R=temp;
            R1=R1->next;
        }
        else{
            temp->val=R2->val;
            temp->next=NULL;
            R->next=temp;
            R=temp;
            R2=R2->next;
        }
    }/*while end*/
    if(R1==NULL&&R2){
        R->next=R2;
    }
    else if(R2==NULL&&R1){
        R->next=R1;
    }
    return head->next;
}
