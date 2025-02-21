#include <iostream>
using namespace std;
int rec(int n){
   if(n==1){
      return n;
   }
   cout<<rec(n-1)<<'\n';
   return(n);
}
int main(){
   int n=0,sum=0;
   cout<<"Enter an integer:";
   cin>>n;
   cout<<rec(n)<<'\n';
}