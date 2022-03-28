#include "../head/LQueue.h"
#include <iostream>
#include <cctype>
#define success_info "~~~"
using namespace std;
int main() {
    string type;//used to store what kind of data you input is
    int saiz;//used to store how big the size of your data type.

    cout<<"Input anything to start a queue."<<endl;
    string cmdlet;
    cin>>cmdlet;
    LQueue Q;
    InitLQueue(&Q);
    cout<<"success."<<endl;//initialization

    cmdlet.clear();
    while(cmdlet.empty()) {
        cout<<"Instruction:"<<endl<<"1.Test if empty\n2.Enqueue\n3.Dequeue\n4.ClearLQueue\n5.Get Head of the queue\n6.Clear the queue\n7.Destroy the queue"<<endl;
        cin>>cmdlet;
    }
    //I should have prevented someone input ctrl+z, but I have no time T.T
    int cmd=*(cmdlet.begin())-'0';
    Status show;
    string lineOfData;
    string::iterator i;
    switch (cmd)
    {
    case 1:
    show=IsEmptyLQueue(&Q);
    if(show==TRUE)
        cout<<"It's empty"<<endl;
    else cout<<"No"<<endl;
    break;

    case 2:
    cout<<"enter your data"<<endl<<"support type:char,int,double"<<endl;
    cin>>lineOfData;
    for(i=lineOfData.begin();i!=lineOfData.end();i++) 
        *i=tolower(*i);
    if(lineOfData!="int"&&lineOfData!="double"&&lineOfData!="char") {
        cout<<"Your input is wrong."<<endl;
        break;
    }
    else {
        int container1(-1);
        char container2(-1);
        double container3(-1);
        cout<<"enter your data:"<<endl;
        cout<<success_info;
        if(lineOfData=="int") {
            saiz=sizeof(int);
            cin>>container1;
        }
        else if(lineOfData=="char") {
            saiz=sizeof(char);
            cin>>container2;
        }
        else if(lineOfData=="double") {
            saiz=sizeof(double);
            cin>>container3;
        }
        else {cout<<"Your input is wrong."<<endl;break;}//for security
        //cout<<saiz;   test line        
    }
    break;

    default:
        break;
    }
    
    return 0;
}