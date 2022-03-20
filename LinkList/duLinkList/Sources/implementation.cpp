#include "..\Headers\duLinkedList.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
Status InitList_DuL(DuLinkedList *L) {
    try {
        (*L)=new DuLNode;
        (*L)->prior=NULL;
        (*L)->next=NULL;
    }
    catch (const bad_alloc &b) {
        return ERROR;
    }
    return SUCCESS;
}
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList ahead=*L,back=*L;
    while(back->next!=NULL) {
        back=back->next;
        delete ahead;
        ahead=back;
    }
    delete back;
    *L=NULL;//if not so, *L is unsolved.
}
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p==NULL || p->next==NULL) 
        return ERROR;
    DuLinkedList nextp=p->next;
    DuLinkedList gap_p=nextp->next;
    p->next=gap_p;
    if(gap_p!=NULL)
        gap_p->prior=p;
    try {//for robustness
        delete nextp;
    }
    catch(exception e) {
        return ERROR;
    }
    return SUCCESS;
}
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    //not allow to insert before the head node
    if(p->prior==NULL || p==NULL || q==NULL)
        return ERROR;
    DuLinkedList previous=p->prior;//old previous node

    previous->next=q;
    q->prior=previous;

    p->prior=q;
    q->next=p;

    return SUCCESS;
}
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(p==NULL || q==NULL)
        return ERROR;
    DuLinkedList save=p->next;
    p->next=q;
    q->prior=p;

    q->next=save;
    if(save!=NULL)//if p is the end of the link, save might be NULL
        save->prior=q;
    return SUCCESS;
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    while(L!=NULL) {
        (*visit)(L->data);
        L=L->next;
    }
}
int main() {
    void Display(ElemType e);
    void (*dis)(ElemType e)=&Display;

    cout<<"Insert������ʾ"<<endl;
    DuLinkedList forInsert,ptr;
    InitList_DuL(&forInsert);
    forInsert->data=0;
    ptr=forInsert;
    for(int i(1);i<=10;i++) {
        DuLinkedList newNode=new DuLNode;
        newNode->data=i;
        InsertAfterList_DuL(ptr,newNode);
        DuLinkedList gapNode=new DuLNode;
        gapNode->data=-i;
        InsertBeforeList_DuL(ptr,gapNode);
        ptr=ptr->next;
    }
    TraverseList_DuL(forInsert,dis);
    cout<<endl;
    cout<<"��InsertAfter����ӽڵ��,����������ʹ��InsertBefore����ӵ�"<<"\n\n";

    DuLinkedList head;
    cout<<"������������"<<endl;
    Status s=InitList_DuL(&head);
    if(s==SUCCESS) {
        cout<<"�ɹ�."<<endl;
        head->data=0;
    }
    else {
        cout<<"error, I got you"<<endl;
        return -1;
    }
    int data=1;
    DuLinkedList current=head;
    cout<<"��������ڵ�����,�벻Ҫ����2^31+1. ����0��������"<<endl;
    bool once=true;
    while(data) {
        cin>>data;
        if(once) {
            current->data=data;
            once=false;
        }
        else if(data!=0) {
            DuLinkedList NewNode=new DuLNode;
            NewNode->data=data;
            InsertAfterList_DuL(current,NewNode);
            current=current->next;
        }
    }
    
    cout<<"���������:"<<endl;
    TraverseList_DuL(head,dis);
    cout<<endl;
    DestroyList_DuL(&head);
    cout<<"����������"<<endl;
    system("pause");
    return 0;
}
void Display(ElemType e) {
    cout<<e<<' ';
}