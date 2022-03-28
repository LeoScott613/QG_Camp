#include "../head/LinkStack.h" 
#include <iostream>
using namespace std;
//initialization
Status initLStack(LinkStack *s) {
    try {
        StackNode *head=new StackNode;
        head->next=NULL;
        s->top=head;
        s->count=0;
    }
    catch (const bad_alloc &ba) {
        cout<<"bad_alloc"<<endl;
        return ERROR;
    }
}
Status isEmptyLStack(LinkStack *s) {
	if(s==NULL||s->top==NULL||s->top->next==NULL)//two posibilities
        return SUCCESS;
    else return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e) {
	if(s==NULL||s->top==NULL||s->top->next==NULL) {
        return ERROR;
    }
    *e=s->top->data;//the top node the top data
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
	if(s==NULL||s->top==NULL) {
        return ERROR;
    }
    else if(s->top->next==NULL) return SUCCESS;
    
    LinkStackPtr Safari=s->top,aSafari=Safari;
    while(Safari->next!=NULL) {
        Safari=Safari->next;
        try {
            delete aSafari;
        }
        catch (exception &e) {
            cout<<"bad_deletion;"<<endl;
            return ERROR;
        }
        aSafari=Safari;
    }
    /* Shouldn't have this, because should leave a node there
    try {
        delete Safari;
    }
    catch (exception &e) {
        cout<<"bad_deletion;"<<endl;
        return ERROR;
    }
    */
    s->top=Safari;//if not so, the s->top is unsolved
    s->count=0;
    return SUCCESS;
}
Status destroyLStack(LinkStack *s){
    if(s==NULL||s->top==NULL) {
        return ERROR;
    }
    else if(s->top->next==NULL) return SUCCESS;
    
    LinkStackPtr Safari=s->top,aSafari=Safari;
    while(Safari->next!=NULL) {
        Safari=Safari->next;
        try {
            delete aSafari;
        }
        catch (exception &e) {
            cout<<"bad_deletion;"<<endl;
            return ERROR;
        }
        aSafari=Safari;
    }
    // Should have this, because I am destroy them.
    try {
        delete Safari;
    }
    catch (exception &e) {
        cout<<"bad_deletion;"<<endl;
        return ERROR;
    }
    return SUCCESS;	
}
Status LStackLength(LinkStack *s,int *length){
	
}
Status pushLStack(LinkStack *s,ElemType data){
    if(s==NULL||s->top==NULL)
        return ERROR;
    try {
        StackNode *NewMem=new StackNode;
        NewMem->data=data;
        NewMem->next=s->top;//link both
        s->top=NewMem;
        s->count++;
    }
    catch (const bad_alloc &ba) {
        cout<<"bad_alloc"<<endl;
        return ERROR;
    }
}
Status popLStack(LinkStack *s,ElemType *data){
    if(s==NULL||s->top==NULL||s->top->next==NULL)
        return ERROR;
    *data=s->top->data;//save the data
    LinkStackPtr trash=s->top;
    s->top=s->top->next;//move to next one
    try {
        delete trash;
    }
    catch (exception &e) {
        cout<<"bad_deletion;"<<endl;
        return ERROR;
    }
    s->count--;
    return SUCCESS;
}
