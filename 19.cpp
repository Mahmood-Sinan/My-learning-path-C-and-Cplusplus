#include <iostream>
#include <string>
int main (){
   std::string name;
   std::cout<<"Enter your name :";
   std::getline(std::cin,name);
   name.append(" Sir");
   name.insert(0,"Mr ");
   if(name.length()>12 || name.empty()){
      std::cout<<"Your name cannot be over 12 characters or less than 1 characters";
   }
   else{
      std::cout<<"Welcome "<< name;
   }
   return 0;
}