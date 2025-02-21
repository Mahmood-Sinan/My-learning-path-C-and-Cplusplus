#include <iostream>
using namespace std;
int isprime(int n){
   int i=2;
   for(i=2;i<n;i++){
      if(n%i==0){
         break;
      }
   }
   return 1?(i==n):0;
}
int main(){
   cout<<"Enter an integer: ";
   int n=0,i=0;
   cin>>n;
   for(i=0;i<=n/2;i++){
      if(isprime(i)==1){
         if(isprime(n-i)==1){
            cout<<"Yes\n"<<i<<" and "<<n-i<<'\n';
            break;
         }
      }
   }
   if(i==n/2+1){
      cout<<"No\n";
   }
   return 0;
}