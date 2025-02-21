#include<iostream>
int main(){
   int *ptr=nullptr;
   int x=123;
   ptr=&x; //assigning  address to a pointer
   if(ptr==NULL){
      std::cout<<"Fail\n";
   }
   else{
      std::cout<<"success\n";
   }
   std::cout<<ptr<<'\n'; //returning the address
   std::cout<<*ptr<<'\n'; //returning the value
   int y=18;
   int *num=&y; //declaring a pointer and assigning an address right away
   return 0;
}