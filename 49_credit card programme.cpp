#include <iostream>
int getdigit(const int num);
int oddsum(const std::string num,const int size);
int evensum(const std::string num,const int size);
int main(){
   std::string num;
   int result=0;
   std::cout<<"Enter a credit card number: ";
   std::cin>>num;
   int size=num.size();
   result=evensum(num,size)+oddsum(num,size);
   if(result%10==0){
      std::cout<<"Valid";
   }
   else {
     std::cout<<"invalid"; 
   }
return 0;
}

int getdigit(const int num){
   return (num%10)+(num/10%10);
}

int oddsum(const std::string num,const int size){
   int osum=0;
   for(int i=size-1;i>=0;i-=2){
      osum+=num[i] - 48;
   }
   return osum;
}

int evensum(const std::string num,const int size){
   int esum=0;
   for(int i=size-2;i>=0;i-=2){
      esum+=getdigit((num[i]-'0')*2);
   }
   return esum;
}