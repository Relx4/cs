#include <stdio.h>
#include<stdlib.h>

typedef struct MinStack{
    int val;
    struct MinStack* next;
} MinStack;

typedef MinStack* Stack;

MinStack* minStackCreate() {
    Stack head=(Stack)malloc(sizeof(MinStack));
    head->next=NULL;
    return head;
}

void minStackPush(MinStack* obj, int val) {
    Stack temp=(Stack)malloc(sizeof(MinStack));
    temp->val=val;
    temp->next=NULL;
    Stack last=obj;
    while(last->next){
        last=last->next;
    }
    last->next=temp;
}

void minStackPop(MinStack* obj) {
    Stack pop_before=obj;
    while(pop_before->next->next){
        pop_before=pop_before->next;
    }
    Stack Free=pop_before->next;
    pop_before->next=NULL;
    free(Free);
}

int minStackTop(MinStack* obj) {
    Stack top=obj;
    while(top->next){
        top=top->next;
    }
    return top->val;
}

int minStackGetMin(MinStack* obj) {
    Stack Min=obj->next;
    int min=Min->val;
    while(Min){
        if(min>Min->val)min=Min->val;
        Min=Min->next;
    }
    return min;
}

void minStackFree(MinStack* obj) {
    Stack before=obj;
    Stack after=obj;
    while(before){
        before=before->next;
        free(after);
        after=before;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
