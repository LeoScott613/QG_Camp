#include <iostream>
#include <cstring>
using namespace std;
int main() {
	void countsort(int*,int);
	int *a=new int[10];
	for(int i(0);i<10;i++) 
		cin>>a[i];
	countsort(a,10);
	for(int i(0);i<10;i++)
		cout<<a[i]<<' ';
	return 0;
}
void countsort(int *a,int size) {
	int min=a[0],max=a[0];
	int range,i,j(0);
	for(i=0;i<size;i++) {
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	range=max-min+1;
	int *counter=new int[range];//if a[i]==5, then counter[a[i]-min]++;
	memset(counter,0,sizeof(counter));
	for(i=0;i<size;i++) {
		counter[a[i]-min]++;
	}
	for(i=0;i<range;i++) //start replacing the original array
		while(counter[i]--) {
			a[j++]=i+min;
		}
	delete counter;
	counter=NULL;
}
