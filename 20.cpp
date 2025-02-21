#include <iostream>
int main(){
   int a;
   do{
     std::cout<<"Enter a postive number : ";
     std::cin>> a; 
   }while(a<0);
   std::cout <<"The number is : "<<a;
   return 0;
}