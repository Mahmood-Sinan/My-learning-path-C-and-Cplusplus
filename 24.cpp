#include <iostream>
#include <ctime>
#include <string>
int main(){
   std::string a,R,P,S;
   std::cout<<"Rock,Paper,Scissors\nYou choose : ";
   std::cin>>a;
   
   std::string r;
   srand(time(NULL));
   int c=rand()%3;
   std::cout<<"Computer chooses : ";
   switch(c){
      case 0:r="rock\n";
         std::cout<<"Rock\n";
         break;
      case 1:r="paper\n";
         std::cout<<"Paper\n";
         break;
      case 2:r="scissors\n";
         std::cout<<"Scissors\n";
         break;

   }
   if((a=="Rock"|| a=="rock" ) &&c==0){
      std::cout<<"Draw\n";
   }
   else if((a=="Rock"|| a=="rock")&&c==1){
      std::cout<<"You lose\n";
   }
   else if((a=="Rock"|| a=="rock")&&c==2){
      std::cout<<"You win\n";
   }
   else  if((a=="Paper"||a=="paper")&&c==0){
      std::cout<<"You win\n";
   }
   else if((a=="Paper"||a=="paper")&&c==1){
      std::cout<<"Draw\n";
   }
   else if((a=="Paper"||a=="paper")&&c==2){
      std::cout<<"You lose\n";
   }
   else if((a=="Scissors"||a=="scissors")&&c==0){
      std::cout<<"You lose\n";
   }
   else if((a=="Scissors"||a=="scissors")&&c==0){
      std::cout<<"You win\n";
   }
   else if((a=="Scissors"||a=="scissors")&&c==2){
      std::cout<<"Draw\n";
   }
   else {
   std::cout<<"Please enter a valid response";
   }

   return 0;
}