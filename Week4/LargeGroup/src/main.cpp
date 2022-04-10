#include <iostream>
#include <cstdlib>
#include "../inc/binary_sort_tree.h"
using namespace std;
void triout(NodePtr hook) {
    cout<<hook->value<<' ';
}
int main() {
    BinarySortTreePtr oak=new BinarySortTree;
    string dustBin;
    cout<<"input anything to init a tree (oak!):"<<endl;
    cin>>dustBin;
    Status show=BST_init(oak);
    
    if(show) {
        ElemType rootV;
        cout<<"Success"<<endl;
        cout<<"input root value:"<<endl;
        cin>>rootV;
        oak->root->value=rootV;
    }
    else {
        cerr<<"exception:bad alloc"<<endl;
        system("pause");
        return -1;
    }
    while(true) {//main loop
        string operations=string("1.Search\n2.Insert\n3.preorder\n4.inorder\n5.postorder\ne.exit");
        string command;
        cout<<operations<<endl;
        cin>>command;
        char cmd=*(command.begin());
        system("cls");
        switch(cmd) {
            case '1':
                ElemType seek;
                cout<<"input what you want to search for:"<<endl;
                cin>>seek;
                show=BST_search(oak,seek);
                if(show)
                    cout<<"Exist."<<endl;
                else cout<<"May not exist."<<endl;
                break;
            case '2':
                ElemType newMem;
                cout<<"input what you want to insert into:"<<endl;
                cin>>newMem;
                show=BST_insert(oak,newMem);
                if(show)
                    cout<<"Done."<<endl;
                else cout<<"Error occured."<<endl;
                break;
            case '3':
                BST_preorderR(oak->root,&triout);
                cout<<endl;
                break;
            case '4':
                BST_inorderR(oak->root,&triout);
                cout<<endl;
                break;
            case '5':
                BST_postorderR(oak->root,&triout);
                cout<<endl;
                break;
            case 'e':
                return 0;
            default:
                cerr<<"emmmm"<<endl;
        }
    }
    return 0;
}
