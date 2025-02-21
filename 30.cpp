#include <iostream>
std::string fullname(std::string name1,std::string name2);
int main(){
   std::string name1,name2;
   std::cout<<"Enter your first name : ";
   std::cin>>name1;
   std::cout<<"Enter your last name : ";
   std::cin>>name2;
   std::cout<<"Hello "<<fullname(name1,name2);
   return 0;
}
std::string fullname(std::string name1,std::string name2){
   return name1 + " " + name2;
}