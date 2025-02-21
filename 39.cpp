#include<iostream>
int search(int array[],int size,int element);
int main(){
   int numbers[]={1,2,3,4,5,6,7,8,9,10};
   int size = sizeof(numbers)/sizeof(numbers[0]);
   int index;
   int mynum;
   std::cout<<"Enter the element to search for ; "<<'\n';
   std::cin>>mynum;
   index=search(numbers,size,mynum);
   if (index!=-1){
      std::cout<<mynum<<" is at index "<<index;
   }
   else{
      std::cout<<mynum<<" is not in the array";
   }
}
int search(int array[],int size,int element){
   for(int i=0;i<size;i++){
      if (array[i]==element){
         return i;
      }
   }
      return -1;
}