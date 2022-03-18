#include "linkedList.h"
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
    catch(exception &e) {
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
    try {
        LinkedList save=p->next;
        p->next=q;
        q->next=save;
    }
    catch(exception &e) {
        return ERROR;
    }
    return SUCCESS;
}
int main() {
    LinkedList head;
    vector<Status> ResultSet;//to store executing status result.
    //However, it is only designed for this very implementation.
    ResultSet.push_back(InitList(&head));
    head->data=19260817;
    cout<<head->data;
    /* test SUCCEED.
    DestroyList(&head);
    if(head==NULL)   //to test if the link is deleted. 
        cout<<1;
    */
    LNode *new_member=new LNode;
    new_member->data=114514;
    ResultSet.push_back(InsertList(head,new_member));
    //cout<<head->data<<(head->next)->data<<endl;   test bundle

    return 0;
}