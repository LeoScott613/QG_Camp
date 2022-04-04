#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    ofstream randout;
    randout.open("rand");
    if(!randout) {
        cerr<<"exception: no file open"<<endl;
        return -1;
    }

    srand((unsigned int)time(NULL));
    for(int i(0);i<2000001;i++) {
        randout<<rand()<<' ';
    }
    return 0;
}