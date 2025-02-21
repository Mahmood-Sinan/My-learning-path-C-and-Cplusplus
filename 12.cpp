#include <iostream>
#include <cmath>
int main (){
   char op;
   double x,y,z;
   std::cout<<"***************CALCULATOR***************\n";
   std::cout<<"Enter the operator (+ - * /)\n";
   std::cin>>op;
   std::cout<<"Enter Num1\n";
   std::cin>>x;
   std::cout<<"Enter Num2\n";
   std::cin>>y;
   switch(op){
      case '+' :
      z=x+y;
      std::cout<<"Result : "<<z<<'\n';
      break;
      case '-' :
      z=x-y;
      std::cout<<"Result : "<<z<<'\n';
      break;
      case '*' :
      z=x*y;
      std::cout<<"Result : "<<z<<'\n';
      break;
      case '/' :
      z=x/y;
      if(y!=0){
         std::cout<<"Result : "<<z<<'\n';
      }
      else{
         std::cout<<"Division by zero is undefined\n";
      }
      break;
      default:
      std::cout<<"Please Enter a valid operator\n";
   }
   std::cout<<"****************************************\n";
   return 0;
}