#include "../head/LinkStack.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main() {
    LinkStack stack;

    string temp;
    cout<<"Input anything to init a stack"<<endl;
    cin>>temp;
    initLStack(&stack);

    cout<<"-----"<<endl;
    while(true) {//main loop
        string cmdlet;
        while(cmdlet.empty()) {
            cout<<"Instruction:"<<endl<<"1.Test if empty\t2.push\t3.pop\t4.Clear stack\n5.Get top\t6.get length\t7.Destroy the stack\t8.Exit"<<endl;
            cin>>cmdlet;
        }
        int cmd=*(cmdlet.begin())-'0';//get instruction

        Status show;
        //elemtype is int
        switch (cmd)
        {
        case 1://is empty?
        system("cls");
        show=isEmptyLStack(&stack);
        if(show==SUCCESS)
            cout<<"---It's empty---"<<endl;
        else cout<<"No"<<endl;
        break;

        case 2://push 
        system("cls");
        ElemType ready;
        cout<<"Input the data:"<<endl;
        cin>>ready;
        show=pushLStack(&stack,ready);//get status 
        if(show)
            cout<<"push succeed."<<endl;
        else cout<<"failed..."<<endl;
        break;

        case 3://pop out
        system("cls");
        ElemType get;
        show=popLStack(&stack,&get);
        if(show) {
            cout<<"You have poped "<<get<<endl;
        }
        else cout<<"fail"<<endl;
        break;

        case 4://clear stack
        system("cls");
        show=clearLStack(&stack);
        if(show)
            cout<<"success"<<endl;
        else cout<<"fail"<<endl;
        break;

        case 5://get top
        ElemType topElem;
        show=getTopLStack(&stack,&topElem);
        if(show) {
            system("cls");
            cout<<"the top is: "<<topElem<<endl;
        }
        else {
            system("cls");
            cout<<"fail"<<endl;
        }
        break;

        case 6://get the length
        break;

        case 7://destroy
        show=destroyLStack(&stack);
        if(show) {
            cout<<"ok, now say goodbye!"<<endl;
            system("pause");
            return 0;
        }
        else cout<<"fail"<<endl;
        break;//if destroy successfully, it is useless

        case 8:
        return 0;

        default:
            system("cls");
            cout<<"your input is wrong"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}