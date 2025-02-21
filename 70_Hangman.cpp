#include <iostream>
#include <string>
using namespace std;
void check(int size,string guess,char a,char* array,int &cur,int &x);
void disp(int size,char* array,int cur,int tries);
int over(int size,char* array,int cur,int tries);
int main(){

   string guess;
   int size,stat,tries,cur=0,x=0;
   char a;
   cout<<"WELCOME\nEnter the word\n";
   std::getline(std::cin,guess);
   size=guess.length();
   for(int i=0;i<size;i++){
      guess[i]=toupper(guess[i]);
   }
   cout<<"Enter the number of tries\n";
   cin>>tries;
   for(int i=0;i<31;i++){
   	cout<<" \n";
   }
   
   char* array= new char[size];
   for(int i=0;i<size;i++){
      if (guess[i]==' '){
         array[i]=' ';
         i++;
      }
      array[i]='_';
   }
   cout<<"\n";
   
do{
   disp(size,array,cur,tries);
   cin>>a;
   a=toupper(a);
   check (size,guess,a,array,cur,x);
   stat=over(size,array,cur,tries);
}while(stat!=1);
if(cur==tries){
   cout<<"You have lost. The Word was "<<guess;
}
else{
   cout<<"CONGRATULATIONS! You have won.";
}
   delete[] array;

   return 0;
}
void check(int size,string guess,char a,char* array,int &cur,int &x){
   x=0;
      for(int i=0;i<size;i++){
      if(a==guess[i]){
         array[i]=a;
         x++;
      }
      }
      if(x==0){
         cur++;
      }
}
void disp(int size,char* array,int cur,int tries){
   for(int i=0;i<size;i++){
      cout<<array[i]<<' ';
   }
   cout<<" You have "<<tries - cur<<" more tries\n";
}
int over(int size,char* array,int cur,int tries){
   if(cur==tries){
      return 1;
   }
   for(int i=0;i<size;i++){
      if(array[i]=='_'){
         return 0;
      }
   }
   return 1;
}