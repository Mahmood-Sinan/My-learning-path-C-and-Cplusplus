#include <iostream>
using namespace std;
void findsum(int* sum,int n,int i){
   if(i<=n){
      (*sum)+=i;
      findsum(sum,n,i+1);
   }
}
int main(){
   int n=0,sum=0;
   cout<<"Enter an integer:";
   cin>>n;
   findsum(&sum,n,1);
   cout<<"By formula:"<<(n*(n+1))/2<<'\n'<<"By recursion:"<<sum<<'\n';
}