#include <iostream>
#include <iomanip>
void showbalance(double balance);
double deposit();
double withdraw(double balance);
int main(){
   double balance=0;
   int choice=0;
   do{
   std::cout<<"*******\nEnter your choice : \n*******\n1.Show Balance\n2.Deposit Money\n3.Withdraw Money\n4.Exit\n";
   std::cin>>choice;
   switch(choice){
   case 1:
      showbalance(balance);
      break;
   case 2:
      balance+=deposit();
      showbalance(balance);
      break;
   case 3:
      balance-=withdraw(balance);
      showbalance(balance);
      break;
   case 4:
      std::cout<<"Thanks for visiting!\n";
      break;
   default :
      std::cout<<"Invalid response\n";
   }
   }while(choice!=4);
   return 0;
}
void showbalance(double balance){
   std::cout<<"Your balance is : "<<std::setprecision(2)<<std::fixed<<balance<<'\n';
}
double deposit(){
   double amount=0;
   std::cout<<"Enter amount to be deposited : ";
   std::cin>>amount;
   if(amount>0){
      return amount;
   }
   else{
      std::cout<<"Invalid amount\n";
      return 0;
   }
}
double withdraw(double balance){
   double amount=0;
   std::cout<<"Enter amount to be withdrawn : ";
   std::cin>>amount;
   if(amount>balance){
      std::cout<<"Insufficient funds\n";
      return 0;
   }
   else if(amount<0){
      std::cout<<"Invalid amount";
      return 0;
   }
   else{
      return amount;
   }  
}