#include <iostream>
using namespace std;
int partition(int a[],int start,int end){
    int pivot=a[end];
    int i=start-1;
    for(int j=start;j<=end-1;j++){
        if(a[j]<pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    int temp=a[i];
    a[i]=a[end];
    a[end]=temp;
    return i;
}
void quicksort(int a[],int start,int end){
    if(end<=start) return; //base case to stop recursion
    int pivot=partition(a,start,end);
    quicksort(a,start,pivot-1);
    quicksort(a,pivot+1,end);
}
int main(){
    int a[]={-5,21,7,14,98,0,14,-78,-65,-100};
    quicksort(a,0,sizeof(a)/sizeof(a[0])-1);
    for (int num:a){
        cout<<num<<' ';
    }
}