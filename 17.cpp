#include <iostream>
int main (){
   int temp;
   bool sunny=0;
   std::cout<<"Enter the temperature\n";
   std::cin>>temp;
   if(temp<0 || temp>30){
      std::cout<<"The temperature is bad\n";
   }
   else{
      std::cout<<"The temperature is good\n";
   }
   if(!sunny){
      std::cout<<"It is sunny outside\n";
   }
   else {
      std::cout<<"It is cloudy outside\n";
   }
   return 0;
}