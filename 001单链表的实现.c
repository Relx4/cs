#include <stdio.h>
#include <stdlib.h>

struct MyLinkedList{
    int val;
    struct MyLinkedList* next;

};
typedef struct MyLinkedList MyLinkedList;
typedef struct MyLinkedList* Link;

MyLinkedList* myLinkedListCreate() {
    Link head=(Link)malloc(sizeof(struct MyLinkedList));
    head->val=-1;
    head->next=NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int count=0;
    if(index<0)return -1;
    Link Find=obj->next;
    if(Find==NULL)return -1;
    while(Find&&count!=index){
        Find=Find->next;
        ++count;
    }
    return Find->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Link temp=(Link)malloc(sizeof(struct MyLinkedList));
    temp->val=val;
    temp->next=obj->next;
    obj->next=temp;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Link temp=(Link)malloc(sizeof(struct MyLinkedList));
    temp->val=val;
    temp->next=NULL;
    Link over=obj;
    while(over->next){
        over=over->next;
    }
    over->next=temp;
}
int Length(MyLinkedList* obj){
    int count=0;
    Link R=obj->next;
    while(R){
        R=R->next;
        ++count;
    }
    return count-1;
}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<=0){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if(index==Length(obj)+1){
        myLinkedListAddAtTail(obj, val);
        return;
    }
    if(index>Length(obj)+1)return;
    int count=0;
    Link find_before=obj->next;
    while (find_before&&count!=index-1) {
        find_before=find_before->next;
        ++count;
    }
    Link temp=(Link)malloc(sizeof(struct MyLinkedList));
    temp->val=val;
    temp->next=find_before->next;
    find_before->next=temp;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0||index>Length(obj))return;
    Link find_before=obj->next;
    int count=0;
    while(find_before&&count!=index-1){
        find_before=find_before->next;
        ++count;
    }
    Link Free=find_before->next;
    find_before->next=Free->next;
    free(Free);
}

void myLinkedListFree(MyLinkedList* obj) {
    Link before=obj;
    Link after=obj;
    while(before){
        before=before->next;
        free(after);
        after=before;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
