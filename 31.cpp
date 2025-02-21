#include <iostream>
int a=3;
int fn();
int main(){
   int a =1;
   std::cout<<::a<<'\n';
   fn();
}
int fn(){
   int a=2;
   std::cout<<::a<<'\n';
   return 0;
}