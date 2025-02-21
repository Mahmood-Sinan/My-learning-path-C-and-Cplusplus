#include <iostream>
int main() {
   int divident,remainder,divisor; 
   std::cout<<"Enter the divident"<<'\n';
   std::cin>>divident;
   std::cout<<"Enter the divisor"<<'\n';
   std::cin>>divisor;
   remainder = divident%divisor;
   std::cout<<remainder;
   return 0;
}