#include <iostream>
int main(){
   int a;
   std::cout<<"Enter your mark\n";
   std::cin>>a;
   a>=60 ? std::cout<<"You Pass\n" : std::cout<<"You Fail\n";
   return 0;
}