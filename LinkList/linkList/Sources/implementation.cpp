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
    LinkedList *ahead_L=L;
    while((*L)->next!=NULL) {//traverse and delete
        *L=(*L)->next;
        delete (*ahead_L);
        ahead_L=L;
    }
    delete (*L);
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
    while(L->next!=NULL) {
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
    LinkedList ptrNode=*L,memNode;
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
    vector<Status> ResultSet;//to store executing status result.
    //However, it is only designed for this very implementation.
    ResultSet.push_back(InitList(&head));
    head->data=1;
    //cout<<head->data;
    /* test SUCCEED.
    DestroyList(&head);
    if(head==NULL)   //to test if the link is deleted. 
        cout<<1;
    */
    LNode *new_member=new LNode;
    new_member->data=2;
    ResultSet.push_back(InsertList(head,new_member));
    //new_member->next=head;
    //cout<<IsLoopList(head);
    //cout<<head->data<<(head->next)->data<<endl;   test Insert
    /* test DeleteList
    ElemType receive;
    ResultSet.push_back(DeleteList(head,&receive));
    cout<<"this is receive:"<<receive;
    return 0;
    */
    LNode *p2=new LNode,*p3=new LNode,*p4=new LNode;
    p2->data=3;p3->data=4;p4->data=5;
    InsertList(new_member,p2);
    InsertList(p2,p3);
    InsertList(p3,p4);
    ReverseEvenList(&head);
    cout<<head->data<<endl
    <<head->next->data<<endl
    <<head->next->next->data<<endl
    <<head->next->next->next->data<<endl
    <<head->next->next->next->next->data;
}