#include <stdio.h>
#include <stdlib.h>
/*提交到leetcode时，请从这里开始粘贴到末尾*/
/*题目：双链表的实现*/
struct MyLinkedList{
    int val;
    struct MyLinkedList* previous;
    struct MyLinkedList* next;
};
typedef struct MyLinkedList MyLinkedList;
typedef struct MyLinkedList* Link;

MyLinkedList* myLinkedListCreate() {
    Link head=(Link)malloc(sizeof(MyLinkedList));
    head->val=0;
    head->previous=NULL;
    head->next=NULL;
    return head;
}//这是一个带有头节点的链表，一定要注意！

int Number(Link obj){
    int count=0;
    Link R=obj->next;
    while(R){
        ++count;
        R=R->next;
    }
    return count;
}//返回的是元素的个数，而不是下标的范围

int myLinkedListGet(MyLinkedList* obj, int index) {
    int count=0;
    if(index<0||index>=Number(obj))return -1;//如果是无效索引，直接返回-1
    /*由上面的判断可知道，此时一定有0<=index<Number(obj)*/
    Link R=obj->next;
    while(R&&index!=count){
        R=R->next;
        ++count;/*保证离开循环体的时候，count一定是和R的下标匹配的*/
    }
    if(R==NULL)return-1;//我觉得这段代码可以删除
    return R->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Link temp=(Link)malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->previous=obj;
    temp->next=obj->next;/*写好新结点*/
    if(obj->next)obj->next->previous=temp;/*修改原0号结点的前驱指针*/
    obj->next=temp;/*修改头结点的后驱指针*/
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Link temp=(Link)malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->previous=NULL;
    temp->next=NULL;
    Link find_last=obj;
    while(find_last->next){
        find_last=find_last->next;
    }
    temp->previous=find_last;
    find_last->next=temp;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index<=0){
        myLinkedListAddAtHead(obj,val);
        return;
    }
    if(index>Number(obj))return;
    if(index==Number(obj)){
        myLinkedListAddAtTail(obj, val);
        return;
    }
    int count=0;
    Link Find=obj->next;
    while(Find&&index!=count){
        Find=Find->next;
        ++count;
    }
    Link temp=(Link)malloc(sizeof(MyLinkedList));
    temp->val=val;
    temp->next=Find;
    temp->previous=Find->previous;
    Find->previous->next=temp;
    Find->previous=temp;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index<0||index>=Number(obj))return;
    int count=0;
    Link R=obj->next;
    while(R&&count!=index){
        R=R->next;
        ++count;
    }
    Link Free=R;
    if(R==NULL)return;
    R->previous->next=R->next;
    if(R->next)R->next->previous=Free->previous;
    free(Free);
}

void myLinkedListFree(MyLinkedList* obj) {
    Link after=obj;
    Link before=obj;
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
