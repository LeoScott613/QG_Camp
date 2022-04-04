#include "../Headers/sort.h"
#include <windows.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int layer1[LAYER1];
int layer2[LAYER2];
int layer3[LAYER3];
int main() {
    fstream randset;
    randset.open("rand");
    if(!randset) {//test whether the file have been open
        cerr<<"exception: no file open"<<endl;
        return -1;
    }

    for(int i(0);i<10000;i++) {//read the file and generate all the number out 
        randset>>layer1[i];
        layer2[i]=layer3[i]=layer1[i];
    }
    for(int i(LAYER1);i<LAYER2;i++) {
        randset>>layer2[i];
        layer3[i]=layer2[i];
    }
    for(int i(LAYER2);i<LAYER3;i++) {
        randset>>layer3[i];
    }

    clock_t start;
    clock_t end;
    int indicator(0);//temporary
    cout<<"input 1 for insert sort test, 2 for quick sort, 3 for radixsort"<<endl;
    cin>>indicator;
    //operations
    if(indicator==1) {//insert sort
        start=clock();
        insertSort(layer1,LAYER1);
        end=clock();
        cout<<"insert sort layer 1: "<<diff<<" ms"<<endl;

        start=clock();
        insertSort(layer2,LAYER2);
        end=clock();
        cout<<"insert sort layer 2: "<<diff<<" ms"<<endl;

        
        start=clock();
        insertSort(layer3,LAYER3);
        end=clock();
        cout<<"insert sort layer 3: "<<diff<<" ms"<<endl;
        
    }
    else if(indicator==2) {//Quick sort
        start=clock();
        QuickSort_Recursion(layer1,0,LAYER1);
        end=clock();
        cout<<"quick sort layer 1: "<<diff<<" ms"<<endl;

        //for(int i(0);i<LAYER1/2;i++) cout<<layer1[i]<<' ';

        start=clock();
        QuickSort_Recursion(layer2,0,LAYER2);
        end=clock();
        cout<<"quick sort layer 2: "<<diff<<" ms"<<endl;

        start=clock();
        QuickSort_Recursion(layer3,0,LAYER3);
        end=clock();
        cout<<"quick sort layer 3: "<<diff<<" ms"<<endl;
    }
    else if(indicator==3) {//Radix Count Sort
        start=clock();
        RadixCountSort(layer1,LAYER1);
        end=clock();
        cout<<"radix count sort layer 1: "<<diff<<" ms"<<endl;

        start=clock();
        RadixCountSort(layer2,LAYER2);
        end=clock();
        cout<<"radix count sort layer 2: "<<diff<<" ms"<<endl;

        start=clock();
        RadixCountSort(layer3,LAYER3);
        end=clock();
        cout<<"radix count sort layer 3: "<<diff<<" ms"<<endl;
    }
    //**********

}