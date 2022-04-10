#include "../inc/binary_sort_tree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int childNum;//access rights:childdector(),bts_delete();
Status BST_init(BinarySortTreePtr bstp) {//initialization
    try {
    bstp->root=new Node;
    bstp->root->left=bstp->root->right=NULL;
    }
    catch (exception &be) {
        return NO;
    }
    return YES;
}
Status BST_insert(BinarySortTreePtr bstp, ElemType newMem) {//insertion
    if(bstp==NULL || bstp->root==NULL)//prevention
        return NO;

    NodePtr runner=bstp->root;

    while(runner!=NULL) {
        if(newMem<runner->value) {//小值情况
            if(runner->left!=NULL)
                runner=runner->left;
            else {
                runner->left=new Node;
                runner->left->value=newMem;
                runner->left->left=runner->left->right=NULL;
                break;//because the value has been inserted, no need to continue the loop
            }
        }

        else if(newMem>runner->value) {//大值情况
            if(runner->right!=NULL)
                runner=runner->right;
            else {
                runner->right=new Node;
                runner->right->value=newMem;
                runner->right->left=runner->right->right=NULL;
                break;//because the value has been inserted, no need to continue the loop
            }
        }

        else return NO;//this is for situation: newMem==runner->value        
    }
    return YES;
}
Status BST_search(BinarySortTreePtr bstp, ElemType seek) {
    if(bstp==NULL || bstp->root==NULL)
        return NO;
    NodePtr safari=bstp->root;
    while(safari->left!=NULL || safari->right!=NULL) {
        if(seek==safari->value)
            return YES;
        else if(seek>safari->value)
            safari=safari->right;//warning A:it could be NULL
        else if(seek<safari->value)
            safari=safari->left;//warning B:it could be NULL

        if(safari==NULL) return NO;//dealing with warning A&B        
    }
    //after the loop, safari stops in the leaf node and remains no comparison
    if(seek==safari->value)
            return YES;
    else return NO;
}
void ChildDetector(NodePtr safari) {//to detect how many children a node that is about to be deleted have.
    if(safari==NULL)
        return ;
    childNum=(safari->left==NULL)+(safari->right==NULL);//find out how many children it has
}
Status BST_delete(BinarySortTreePtr bstp, ElemType trash) {//before delete should accompanish search
    //leaf node:
    NodePtr cleaner=bstp->root;
    NodePtr dog=cleaner;
    if(cleaner->value==trash && cleaner->left==cleaner->right==NULL) //it's in the root node now
        return NO;//refuse to delete the tree that only possess a root node
    
    BST_preorderR(bstp->root,ChildDetector);//determine which situation to deal with

    if(childNum==0) {
        while(1) {
            if(trash>cleaner->value)
                cleaner=cleaner->right;
            else if(trash<cleaner->value)
                cleaner=cleaner->left;
            
            if(cleaner==NULL)
                return NO;
            else if(trash==cleaner->value) {
                if(dog->left==cleaner)
                    dog->left==NULL;
                else if(dog->right==cleaner)
                    dog->right=NULL;
                
                try{
                    delete cleaner;
                }
                catch (exception e) {
                    cerr<<"deletion error"<<endl;
                    return NO;
                }

                return YES;
            }
            else
                dog=cleaner;
        }
    }
    else if(childNum==1) {}
}
Status BST_preorderR(NodePtr root, void (*visit)(NodePtr)) {
    if(root==NULL)
        return NO;
    
    visit(root);
    BST_preorderR(root->left,visit);
    BST_preorderR(root->right,visit);

    return YES;
}
Status BST_inorderR(NodePtr root, void (*visit)(NodePtr)) {
    if(root==NULL)
        return NO;
    
    BST_preorderR(root->left,visit);
    visit(root);
    BST_preorderR(root->right,visit);

    return YES;
}
Status BST_postorderR(NodePtr root, void (*visit)(NodePtr)) {
    if(root==NULL)
        return NO;
    
    BST_preorderR(root->left,visit);
    BST_preorderR(root->right,visit);
    visit(root);

    return YES;
}