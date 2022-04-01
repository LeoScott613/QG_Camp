/*
This is writen after due day
Created on 2022/3/30
@Author:LeoScott
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include "stak.h"
using namespace std;
int calc(int a,char b,int c) {//simple calculator
    int retun(0);
    if(b=='+')
        retun=a+c;
    else if(b=='-')
        retun=a-c;
    else if(b=='*')
        retun=a*c;
    else if(b=='/')
        retun=a/c;
    return retun;
}
int compare(char a) {
    enum return_status {
        err,linar,multi
    };
    if(a=='+'||a=='-')
        return linar;
    else if(a=='*'||a=='/')
        return multi;
    else if(a=='#')
        return err;
    else return err;
}
int main() {
    stackNode *numStack=Init();
    stackNode *signStack=Init();
    string cmdline;
    while(cmdline.empty())//prevent from input nothing
        cin>>cmdline;
    Elemtype eachNumber(0);
    for(string::iterator i(cmdline.begin());i!=cmdline.end();i++) {
        if(isdigit(*i))
            eachNumber=eachNumber*10+*i-'0';
        else if(!isdigit(*i)) {
            push(&numStack,eachNumber);
            eachNumber=0;
        }
    }
    /*
    step1: transfer the mid-fix expression to subfix expression
    step2: push the number into the number stack, and push the sign into the sign stack, with the rules showing on the ppt
    step3: follow the rules to calculate the cmdline and get the result
    */
}