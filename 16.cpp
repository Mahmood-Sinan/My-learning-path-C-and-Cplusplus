#include <iostream>
int main(){
   int a;
   std::cout<<"Enter an interger\n";
   std::cin>>a;
   a%2 ? std::cout<<"odd\n" : std::cout<<"even\n";
   return 0;
}