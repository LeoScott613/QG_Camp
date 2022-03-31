#include <iostream>
#include "stak.h"
using namespace std;
stackNode *Init() {
    stackNode *p=new stackNode;
    p->next=NULL;
    return p;
}
void push(stackNode **pushNode,Elemtype Newer) {
    stackNode *NewNode=new stackNode;
    NewNode->data=Newer;
    NewNode->next=*pushNode;
    *pushNode=NewNode;
}
void pop(stackNode *popNode) {
    if(popNode->next==NULL||popNode==NULL)
        return ;
    delete popNode;
}
Elemtype top(stackNode *topout) {
    if(topout->next==NULL||topout==NULL)
        return -114514;
    return topout->data;
}