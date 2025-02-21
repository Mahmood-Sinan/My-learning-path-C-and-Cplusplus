#include <iostream>
int main(){
   double temp;
   char unit;
   std::cout<<"***********Temperature conversion programme***********\n";
   std::cout<<"F = Farenheit\n";
   std::cout<<"C= celsius\n";
   std::cout<<"What unit would you like to convert to: ";
   std::cin>>unit;
   if (unit== 'F' || unit== 'f'){
      std::cout<<"Enter the temperature in Celsius : ";
      std::cin>>temp;
      std::cout<<"The temperature in Farenheit is :"<<temp*9/5+32<<"\n";
   }
   else if (unit== 'C' || unit== 'c'){
      std::cout<<"Enter the temperature in Farenheit : ";
      std::cin>>temp;
      std::cout<<"The temperature in Celsius is :"<<(temp-32)*5/9<<"\n";
   }
   else {
      std::cout<<"Please enter a valid response (C c F f)\n";
   }
   std::cout<<"******************************************************\n";
return 0;
}