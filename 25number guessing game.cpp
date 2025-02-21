#include <iostream>
#include <ctime>
int main(){
   int st,en;
   std::cout<<"Welcome to number guessing game\n";
   std::cout<<"Enter a starting number : ";
   std::cin>>st;
   std::cout<<"Enter an ending number : ";
   std::cin>>en;
   srand(time(NULL));
   int a,b;
   a=(rand()%(en-st+1))+st;
   do{
      std::cout<<"Enter the number which you think computer has selected ranging from "<<st<<"-"<<en<<"\nYou choose : ";
      std::cin>>b;
   }while(b<st||b>en);
   if (a==b){
      std::cout<<"Wow You Guessed It Right!\n";
   }
   else{
      std::cout<<"You got it wrong\nI chose : "<<a<<"\n";
   }
   std::cout<<"*********************************";

return 0;
}