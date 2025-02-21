#include <iostream>
int main(){
   int a,b,c;
   std::cout<<"Enter a :";
   std::cin>>c;
   std::cout<<"Enter b :";
   std::cin>>b;
   a=c;
   while(a!=b){
      switch(c){
      case 1 :
      std::cout<<"one";
      a++;
      std::cout<<"two";
      a++;
      std::cout<<"three";
      a++;
      std::cout<<"four";
      a++;
      std::cout<<"five";
      a++;
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 2 :
      std::cout<<"two";
      a++;
      std::cout<<"three";
      a++;
      std::cout<<"four";
      a++;
      std::cout<<"five";
      a++;
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 3 :
      std::cout<<"three";
      a++;
      std::cout<<"four";
      a++;
      std::cout<<"five";
      a++;
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 4 :
      std::cout<<"four";
      a++;
      std::cout<<"five";
      a++;
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 5 :
      std::cout<<"five";
      a++;
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 6 :
      std::cout<<"six";
      a++;
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 7 :
      std::cout<<"seven";
      a++;
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int a=0;a<=b;a++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
      case 8 :
      std::cout<<"eight";
      a++;
      std::cout<<"nine";
      a++;
      for(int i=0;i<b-a;i++){
         if(a%b==0){
            std::cout<<"even";
         }
         else if(a%b==1){
            std::cout<<"odd";
         }
      }
      break;
      case 9 :
      std::cout<<"nine";
      a++;
      for(int i=0;a<=b;i++){
         if(a%b==0){
            std::cout<<"even";
         }
         else{
            std::cout<<"odd";
         }
      }
      break;
   }
   }
   return 0;
}