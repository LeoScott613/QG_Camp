#include "../head/LQueue.h" 
#include <iostream>
using namespace std;
void InitLQueue(LQueue *Q){//Q's real para is a variable.
	Q->front=new Node;//init a linklist
	Q->front->next=NULL;//the requirement of a linklist
	Q->rear=Q->front;
	Q->length=0;//0 is before you enter any number
}
void DestoryLQueue(LQueue *Q){
	if(Q==NULL)//to prevent illegal access
		return ;
	Node *safari=Q->front,*Asafari=safari;
	while(safari->next!=NULL) {
		safari=safari->next;
		delete Asafari;
		Asafari=safari;
	}
	delete safari;//delete linklist. This is line's existence is because the loop left the last Node to delete.
	Q->front=Q->rear=NULL;
	Q->length=0;
}
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL||Q->length==0)
		return TRUE;
	else return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front==NULL||Q==NULL) return FALSE;
	e=Q->front->data;//????
	if(e!=NULL)//data is a void*, so the prevention of e from being null is must.
		return TRUE;
	else return FALSE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	
}
Status EnLQueue(LQueue *Q, void *data){
	if(data==NULL||Q==NULL)//check validity
		return FALSE;
	Node *Newmem;
	try {
		Newmem=new Node;
	}
	catch (const bad_alloc &ba) {
		return FALSE;
	}
	Newmem->data=data;//update data
	Q->rear->next=Newmem;//enter the queue
	Newmem->next=NULL;//follow the "tradition" of the queue
	Q->length++;//update the length
	return TRUE;
}
Status DeLQueue(LQueue *Q){
	if(Q->front->next==NULL||Q->front==NULL||Q==NULL)
		return FALSE;
	Node *out=Q->front->next;
	Q->front->next=out->next;//kick off "out"
	try {
		delete out;
	}
	catch (exception e) {
		return FALSE;
	}
	return TRUE;
}
void ClearLQueue(LQueue *Q){
	if(Q==NULL||Q->front==NULL||Q->front->next==NULL)//to prevent illegal access
		return ;
	Node *safari=Q->front->next,*Asafari=safari;
	while(safari->next!=NULL) {
		safari=safari->next;
		delete Asafari;
		Asafari=safari;
	}
	delete safari;
	//Q->front=Q->rear=new Node;//rebuild...I gave up this, for the type of current function is void that it couldn't transmit the status.
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->length=0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	cout<<' ';
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/


