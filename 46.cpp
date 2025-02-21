#include <iostream>
void swap(std::string &x,std::string &y);
int main(){
   std::string x="Honey";
   std::string y="Water";
   swap(x,y);
   std::cout<<&x<<'\n'<<&y<<'\n';
   return 0;
}
void swap(std::string &x,std::string &y){
   std::cout<<&x<<'\n'<<&y<<'\n';
   }