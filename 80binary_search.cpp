#include <iostream>
#include <algorithm>
using namespace std;
int binary_search(int a[],int size,int target){
    int left=0;
    int right=size-1;
    while(left<=right){
        int middle=left+(right-left)/2;
        if(a[middle]<target){
            left=middle+1;
        }
        else if(a[middle]>target){
            right=middle-1;
        }
        else{
            return middle;
        }
    }
    return -1;
}
int main(){
    // int a[]={-5,21,7,98,0,14,-78,-65,-100,46,65,1,2,-86,9,-1,-41};
    int *a=new int[10000000];
    for(int i=0;i<10000000;i++){
        a[i]=i;
    }
    int size=10000000;
    // int size=sizeof(a)/sizeof(a[0]);
    // sort(a,a+size);
    // cout<<"The array is :";
    // for(int i=0;i<size;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<'\n';
    int target=159687;
    int result=binary_search(a,size,target);
    if(result==-1){
        cout<<"Target not found\n";
    }
    else{
        cout<<"Target "<<target<<" found at: "<<result<<'\n';
    }
    delete[] a;
}