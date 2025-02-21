#include <iostream>
#include <ctime>
#include <cstdlib>

char getuserchoice();
char getcomputerchoice();
void showchoice(char choice);
int choosewinner(char user, char computer);

int main(){
   char user;
   char computer;
   int result;
   int userscore=0;
   int computerscore=0;
   int rounds=0;
   std::cout<<"Rock Paper Scissor Game!\n";
   std::cout<<"************************\n";
   do{
   user = getuserchoice();
   computer = getcomputerchoice();
   if(user!='e'){
   std::cout<<" You chose : ";
   showchoice(user);
   std::cout<<" Computer chose : ";
   showchoice(computer);
   rounds++;
   result = choosewinner(user,computer);
   if(result==1){
      userscore++;}
   else if(result==-1){
      computerscore++;}
   std::cout<<"Your score :"<<userscore<<"   Computer score :"<<computerscore<<"   Rounds :"<<rounds<<'\n';
   }
   }while(user!='e');
   std::cout<<"Thank you for visitng!\n";
   return 0;
}

char getuserchoice(){
   char user;
   do{
      std::cout<<"Choose :\n'r' for Rock\n'p' for Paper\n's' for Scissors\n'e' for exit\n";
      std::cin>>user;
   }while( user!='r'&& user!='p'&& user!='s'&& user!='e');
   
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
      default:return 0;
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
int choosewinner(char user,char computer){
   switch(user){
      case 'r':
	      if(computer=='r'){
	         std::cout<<"It's a Tie!\n";
	         return 0;
	      }
	      else if(computer=='p'){
	         std::cout<<"You lose!\n";
	         return -1;
	      }
	      else {
	         std::cout<<"You Win!\n";
	         return 1;
	      }
	      break;
      case 'p':
	      if(computer=='r'){
	         std::cout<<"You Win!\n";
	         return 1;
	      }
	      else if(computer=='p'){
	         std::cout<<"It's a Tie!\n";
	         return 0;
	      }
	      else {
	         std::cout<<"You lose!\n";
	         return -1;
	      }
	      break;
      case 's':
	      if(computer=='r'){
	         std::cout<<"You lose!\n";
	         return -1;
	      }
	      else if(computer=='p'){
	         std::cout<<"You Win!\n";
	         return 1;
	      }
	      else {
	         std::cout<<"It's a Tie!\n";
	         return 0;
	      }
	      break;
         default:return 0;
   }
}