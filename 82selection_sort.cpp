/*
selection sort
Time complexity is O(n). 
*/
#include <iostream>
using namespace std;
void selectionsort(int a[],int size){
   for(int i=0;i<size-1;i++){
      int min=i; //min is the index of minimum
      for(int j=i+1;j<size;j++){
         if(a[j]<a[min]) min=j;
      }
      int temp=a[i];
      a[i]=a[min];
      a[min]=temp;
   }
}
int main(){
   int array[]={5,7,9,1,6,4,0,2,8,3};
   selectionsort(array,sizeof(array)/sizeof(array[0]));
   for(int i:array){
      cout<<i<<' ';
   }
}