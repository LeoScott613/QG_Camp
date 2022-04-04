#include "../Headers/sort.h"
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
void insertSort(int *a,int n) {
    int i,j,temp;
    for(i=1;i<n;i++) {
        for(j=i;j>0;j--) {
            if(a[j]>=a[j-1]){
                break;
            }
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
void MergeArray(int *a,int begin,int mid,int end,int *temp) {
    if (begin >= end)
        return;
    int i=begin;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=end) {
        if(a[i]<a[j]) {
            temp[k++]=a[i++];
        } else {
            temp[k++]=a[j++];
        }
    }
    if (i == mid + 1) {
        while(j <= end)
            temp[k++] = a[j++];
    }
    if (j == end + 1) {
        while (i <= mid)
            temp[k++] = a[i++];
    }
    for (j = 0, i = begin ; j < k; i++, j++) {
        a[i] = temp[j];
    }
}
void MergeSort(int *a,int begin,int end,int *temp) {
    if(begin>=end)
        return;
    int mid=(begin+end)/2;
    MergeSort(a,begin,mid,temp);
    MergeSort(a,mid+1,end,temp);
    MergeArray(a,begin,mid,end,temp);
}
void QuickSort_Recursion(int *a, int begin, int end) {
   if(begin>end)
        return;
    int i=begin,j=end,temp;
    int basic=a[begin];
    while(i!=j) {
        while(a[j]>=basic&&j>i)
            j--;
        while(a[i]<=basic&&j>i)
            i++;
        if(j>i) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[begin]=a[i];
    a[i]=basic;
    QuickSort_Recursion(a,begin,i-1);
    QuickSort_Recursion(a,i+1,end); 
}
void QuickSort(int *a,int size) {
    
}
int Partition(int *a, int begin, int end) {
    int tmp = a[begin];
    while (begin<end) {
        while (begin < end && a[end] >= tmp) {
            end--;
        }
        if (begin >= end) {
            break;
        }
        else {
            a[begin] = a[end];
        }
        while (begin<end && a[begin] <= tmp) {
            begin++;
        }
        if (begin >= end) {
            break;
        }
        else {
            a[end] = a[begin];
        }
    }
    a[begin] = tmp;
    return begin;
}
void CountSort(int *a, int size , int max) {
    int min = a[0];
	int range,i,j;
	int *b;
	for (i = 0; i < size; i++){
		if (a[i] < min)
			min = a[i];
	}
	range = max - min + 1;
	b = new int[range];
	for (i = 0; i < size; i++){
		b[a[i] - min] += 1;
	}
	j = 0;
	for (i = 0; i < range; i++){
		while (b[i]--){
			a[j++] = i + min;
		}
	}
	delete b;
	b = NULL;
}
int position(int num,int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}
void RadixCountSort(int *a,int size) {
    int *b[10];    
    for (int i = 0; i < 10; i++) {
        b[i]=new int[size+1];
        b[i][0] = 0;    
    }
    for (int pos = 1; pos <= 31; pos++) {
        for (int i = 0; i < size; i++) {
            int num = position(a[i], pos);
            int index = ++b[num][0];
            b[num][index] = a[i];
        }
        for (int i = 0, j =0; i < 10; i++) {
            for (int k = 1; k <= b[i][0]; k++)
                a[j++] = b[i][k];
            b[i][0] = 0;
        }
    }
}
void ColorSort(int *a,int size) {
    int i , j = 0, k = 0, t ;
    for(i = 0; i < size; i++) {
        t = a[i];
        a[i] = 2;
        if(t < 2)
            a[k++] = 1;
        if(t == 0)
            a[j++] = 0;
    }
}
