#include <iostream>
#include <algorithm>
using namespace std;
int interpolation_search(int a[],int size,int target){
    int low=0;
    int high=size-1;
    while(target>=a[low]&&target<=a[high]&&low<=high){
        int probe = low + (high-low)*(target-a[low])/(a[high]-a[low]);
        if(target>a[probe]){
            low=probe+1;
        }
        else if(target<a[probe]){
            high=probe-1;
        }
        else{
            return probe;
        }
    }
    return -1;
}
int main(){
    int a[]={-5,21,7,98,0,14,-78,-65,-100,46,65,1,2,-86,9,-1,-41};
    // int *a=new int[10000000];
    // for(int i=0;i<10000000;i++){
    //     a[i]=i;
    // }
    // int size=10000000;
    int size=sizeof(a)/sizeof(a[0]);
    sort(a,a+size);
    cout<<"The array is :";
    for(int i=0;i<size;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    int target=9;
    int result=interpolation_search(a,size,target);
    if(result==-1){
        cout<<"Target not found\n";
    }
    else{
        cout<<"Target "<<target<<" found at: "<<result<<'\n';
    }
    // delete[] a;
}