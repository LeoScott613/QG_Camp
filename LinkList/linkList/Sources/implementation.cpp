#include "..\Headers\linkedList.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
Status InitList(LinkedList *L) {
    try {
        *L=new LNode;
        (*L)->next=NULL;
    }
    catch(const bad_alloc &e) {//if new failed, throw an bad_alloc object
        return ERROR;
    }
    return SUCCESS;
}
void DestroyList(LinkedList *L) {
    LinkedList ahead=*L,nextOne=*L;
    while(nextOne->next!=NULL) {//traverse and delete
        nextOne=nextOne->next;
        delete ahead;
        ahead=nextOne;
    }
    delete nextOne;
    *L=NULL;//if not so, *L is unsolved.
}
Status InsertList(LNode *p, LNode *q) {
    if(p==q) return ERROR;//it's doing nothing, meaningless, so it returns an error
    else if(p==NULL || q==NULL) return ERROR;
    LinkedList save=p->next;
    p->next=q;
    q->next=save;
    return SUCCESS;
}
Status DeleteList(LNode *p,ElemType *e) {
    if(p->next==NULL || p==NULL) {
        return ERROR;
    }
    LinkedList nextOne=p->next;
    *e=nextOne->data;
    p->next=nextOne->next;
    try {
        delete nextOne;
    }
    catch (exception &e) {
        return ERROR;
    }
    return SUCCESS;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    while(L!=NULL) {
        (*visit)(L->data);
        L=L->next;
    }
}
Status SearchList(LinkedList L, ElemType e) {
    if(L==NULL) return ERROR;//prediction
    while(L->data!=e && L->next!=NULL)
        L=L->next;
    //when jump out from the loop, its data is e or its next is null
    if(L->data==e) return SUCCESS;
    else return ERROR;
}
Status ReverseList(LinkedList *L) {
    if(*L==NULL || L==NULL) return ERROR;//prediction
    LinkedList ptrNode=*L,memNode,End=*L;
    while(End->next!=NULL)
        End=End->next;
    if(ptrNode->next==NULL) 
        return ERROR;
    LinkedList nextNode=ptrNode->next;
    while(nextNode!=NULL) {
        memNode=ptrNode;
        ptrNode=nextNode;
        nextNode=ptrNode->next;
        ptrNode->next=memNode;
    }
    (*L)->next=NULL;
    *L=End;
    return SUCCESS;
}
Status IsLoopList(LinkedList L) {
    if(L==NULL) return ERROR;//prediction
    LinkedList slow=L;
    if(L->next!=NULL)
        L=L->next;
    else return ERROR;
    for(int velocity(2);L->next!=NULL;L=L->next) {
        if(L==slow) 
            return SUCCESS;
        if(velocity==0) {
            slow=slow->next;
            velocity=2;
        }
        else velocity--;
    }
    return ERROR;
}
LNode* FindMidNode(LinkedList *L) {
    if(*L==NULL || L==NULL) return NULL;//prediction
    LinkedList fast=*L,slow=*L;
    for(int velocity(1);fast->next!=NULL;fast=fast->next) {
        if(velocity<=0) {
            slow=slow->next;
            velocity=1;
        }
        else velocity--;
    }
    return slow;
}
LNode* ReverseEvenList(LinkedList *L) {
    if(*L==NULL || L==NULL) return NULL;//prediction
    //break and rebuild
    LinkedList odd=*L,even,ptr=*L;
    if(odd->next==NULL) {
        return *L;
    }
    LinkedList evenList,even_ptr;
    InitList(&evenList);
    even_ptr=evenList;
    bool onlyOnce=true;
    while(ptr->next!=NULL) {
        LinkedList even_data=new LNode;
        DeleteList(ptr,&(even_data->data));
        if(onlyOnce) {
            even_ptr->data=even_data->data;
            onlyOnce=!onlyOnce;
        }
        else {
            InsertList(even_ptr,even_data);
            even_ptr=even_ptr->next;
        }
        if(ptr->next==NULL)
            break;
        else
            ptr=ptr->next;
    }
    even_ptr=evenList;
    //cout<<"evenlist:"<<evenList->data<<evenList->next->data<<endl;
    while(odd!=NULL) {
        LinkedList ToCat=odd,beCated=even_ptr;
        odd=odd->next;
        if(even_ptr->next!=NULL){
            even_ptr=even_ptr->next;
            InsertList(beCated,ToCat);
        }
        else{
            InsertList(beCated,ToCat);
            even_ptr=even_ptr->next;
        }
    }
    *L=evenList;
    return evenList;
}
int main() {
    LinkedList head;
    cout<<"创建新链表中"<<endl;
    Status s=InitList(&head);
    if(s==SUCCESS) {
        cout<<"Succeed."<<endl;
        head->data=0;
    }
    else {
        cout<<"error, I got you"<<endl;
        return -1;
    }
    int data=1;
    LinkedList current=head;
    cout<<"依次输入节点数据,请不要超过2^31+1. 输入0结束输入"<<endl;
    bool once=true;
    while(data) {
        cin>>data;
        if(once) {
            current->data=data;
            once=false;
        }
        else if(data!=0) {
            LinkedList NewNode=new LNode;
            InsertList(current,NewNode);
            current=current->next;
            current->data=data;
        }
    }
    void Display(ElemType e);
    void (*dis)(ElemType e)=&Display;
    cout<<"你的链表是:"<<endl;
    TraverseList(head,dis);
    cout<<endl;
    cout<<"该链表中点是:"<<FindMidNode(&head)->data<<endl;
    //loop linkedlist
    LinkedList loop,NewNode,loop_ptr;
    InitList(&loop);
    loop_ptr=loop;
    for(int i=0;i<5;i++) {//creates five new nodes
        NewNode=new LNode;
        NewNode->data=i+100;//distinguish from
        InsertList(loop,NewNode);
    }
    InsertList(loop,NewNode);//make it a loop
    if(IsLoopList(loop)) {
        cout<<"隐藏的循环链表测试通过"<<endl;
    }
    else cout<<"没有通过"<<endl;
    cout<<"倒转后的链表:"<<endl;
    ReverseList(&head);
    TraverseList(head,dis);
    ReverseList(&head);//reverse back
    cout<<endl;
    cout<<"奇偶倒转后的链表"<<endl;
    ReverseEvenList(&head);
    TraverseList(head,dis);
    ReverseEvenList(&head);//reverse back
    cout<<endl;
    cout<<"输入想搜索的数字"<<endl;
    ElemType Search(-114);
    cin>>Search;
    if(SearchList(head,Search)) {
        cout<<"有"<<endl;
    }
    else cout<<"没有吧"<<endl;
    DestroyList(&head);
    cout<<"链表已销毁"<<endl;
    cout<<"删除节点,插入节点的实现已经体现在奇偶倒转函数中了,所以主动测试就省略了^.^"<<endl;
    system("pause");
    return 0;
}
void Display(ElemType e) {
    cout<<e<<' ';
}