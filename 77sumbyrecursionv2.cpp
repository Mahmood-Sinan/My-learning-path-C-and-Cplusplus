#include <iostream>
using namespace std;
int findsum(int n){
   if(n==1){
      return n;
   }
   return n+=findsum(n-1);
}
int main(){
   int n=0,sum=0;
   cout<<"Enter an integer:";
   cin>>n;
   sum=findsum(n);
   cout<<"By formula:"<<(n*(n+1))/2<<'\n'<<"By recursion:"<<sum<<'\n';
}