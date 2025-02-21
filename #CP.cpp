#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canBeValid(string s, string locked) {
   int n=s.length();
   if(n%2==1) return false;
   int token=0;
   for(int i=0;i<n;i++){
      if(s[i]==')'){
            token--;
            if(token<0&&locked[i]=='0'){
               s[i]='(';
               token+=2;
            }
      }
      else{
            token++;
            if(token>0&&locked[i]=='0'){
               s[i]=')';
               token-=2;
            }
      }
   }
   return token==0;
}

int main(){
   string s="))))(())((()))))((()((((((())())((()))((((())()()))(()",locked="101100101111110000000101000101001010110001110000000101";
   for(int i=0;i<s.length();++i){
      if(i/10==0){
         cout<<i<<"  ";
      }
      else{
         cout<<i<<' ';
      }
   }
   cout<<'\n';
   for(char cur:s){
      cout<<cur<<"  ";
   }
   cout<<'\n';
   for(char cur:locked){
      cout<<cur<<"  ";
   }
   cout<<'\n';
   cout<<"The answer is: "<<canBeValid(s,locked)<<'\n';

   return 0;
}