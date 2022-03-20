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