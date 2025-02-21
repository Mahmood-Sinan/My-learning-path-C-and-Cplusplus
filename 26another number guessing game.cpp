#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
   srand(time(NULL));
   int num,guess,tries,st,en;
   std::cout<<"******NUMBER GUESSING GAME******\n";
   std::cout<<"Enter the starting number : ";
   std::cin>>st;
   std::cout<<"Enter the ending number : ";
   std::cin>>en;
   num=(rand()%(en-st+1))+st;
   do{
      std::cout<<"Enter a guess between "<<st<<"-"<<en<<"\n";
      std::cin>>guess;
      tries+=1;
      if(guess>num){
         std::cout<<"Too high\n";
      }
      else if(guess<num){
         std::cout<<"Too low\n";
      }
   }while(num!=guess);
   std::cout<<"CORRECT! Number of tries : "<<tries;
return 0;
}