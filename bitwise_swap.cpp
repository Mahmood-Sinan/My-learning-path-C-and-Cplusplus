#include <iostream>
#include <bitset>
using namespace std;
int main(){
   int a = 109, b = 2482;
   cout<<"Before Swapping - a: "<<a<<" b: "<<b<<'\n';
   cout<<"Binary Before processing -\n a: "<<bitset<8>(a)<<"\n b: "<<bitset<8>(b)<<'\n';
   a = a ^ b;
   cout<<"Binary After first stage -\n a: "<<bitset<8>(a)<<"\n b: "<<bitset<8>(b)<<'\n';
   b = a ^ b;
   cout<<"Binary After second stage-\n a: "<<bitset<8>(a)<<"\n b: "<<bitset<8>(b)<<'\n';
   a = a ^ b;
   cout<<"Binary After third stage -\n a: "<<bitset<8>(a)<<"\n b: "<<bitset<8>(b)<<'\n';
   cout<<"After Swapping - a: "<<a<<" b: "<<b<<'\n';

   return 0;
}