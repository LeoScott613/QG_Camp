#pragma once
typedef int Elemtype;
typedef struct stackNode {
    Elemtype data;
    struct stackNode *next;
}stackNode;
stackNode *Init();
void push(stackNode **pushNode,Elemtype Newer);
void pop(stackNode *popNode);
Elemtype top(stackNode *topout);