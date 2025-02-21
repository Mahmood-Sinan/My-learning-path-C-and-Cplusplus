#include <iostream>
#include <ctime>
#include <cstdlib>

char getuserchoice();
char getcomputerchoice();
void showchoice(char choice);
void choosewinner(char user, char computer);

int main(){
   char user;
   char computer;
   std::cout<<"Rock Paper Scissor Game!\n";
   std::cout<<"************************\n";
   user = getuserchoice();
   computer = getcomputerchoice();
   std::cout<<" You chose : ";
   showchoice(user);
   std::cout<<" Computer chose : ";
   showchoice(computer);
   choosewinner(user,computer);
   return 0;
}

char getuserchoice(){
   char user;
   do{
      std::cout<<"Choose :\n'r' for Rock\n'p' for Paper\n's' for Scissors\n";
      std::cin>>user;
   }while( user!='r'&& user!='p'&& user!='s');
   
   return user;
}
char getcomputerchoice(){
   srand(time(0));
   int i =rand()%3+1;
   switch(i){
      case 1:return 'r';
      break;
      case 2:return 'p';
      break;
      case 3:return 's';
      break;
   }
}
void showchoice(char choice){
   switch(choice){
      case 'r':std::cout<<"Rock\n";
         break;
      case 'p':std::cout<<"Paper\n";
         break;
      case 's':std::cout<<"Scissors\n";
         break;
   }
}
void choosewinner(char user,char computer){
   switch(user){
      case 'r':
	      if(computer=='r'){
	         std::cout<<"It's a Tie!\n";
	      }
	      else if(computer=='p'){
	         std::cout<<"You lose!\n";
	      }
	      else {
	         std::cout<<"You Win!\n";
	      }
	      break;
      case 'p':
	      if(computer=='r'){
	         std::cout<<"You Win!\n";
	      }
	      else if(computer=='p'){
	         std::cout<<"It's a Tie!\n";
	      }
	      else {
	         std::cout<<"You lose!\n";
	      }
	      break;
      case 's':
	      if(computer=='r'){
	         std::cout<<"You lose!\n";
	      }
	      else if(computer=='p'){
	         std::cout<<"You Win!\n";
	      }
	      else {
	         std::cout<<"It's a Tie!\n";
	      }
	      break;
   }
}