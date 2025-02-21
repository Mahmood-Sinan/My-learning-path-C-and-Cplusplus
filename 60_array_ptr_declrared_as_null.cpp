#include <iostream>
int main(){
   int* pnum=NULL;
   int size;
   std::cout<<"How many numbers: ";
   std::cin>>size;

   pnum=new int[size]; //we declared pnum is supposed to be an integer pointer(not assigned a pointer to location ) before. so now we say that pnum points to (not equal to) an array of integers with size "size integer" that has to be created in heap

   for(int i=0;i<size;i++){
      std::cout<<"Enter #"<<i+1<<" ";
      std::cin>>pnum[i];
   }
   for (int i=0;i<size;i++){
      std::cout<<"Adress of #"<<i+1<<" "<<&pnum[i]<<"  "<<"Value of #"<<i+1<<" "<<pnum[i]<<'\n'; //just pnum holds address of first element.
   }
   return 0;

   delete[] pnum;
}