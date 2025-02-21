#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

   std::string a;
   std::string query;
   std::getline(std::cin,a);
   int n=a[0]-'0';
   int q=a[2] - '0';
   std::string array[n];
   for(int i=0;i<n;i++){
      std::getline(std::cin,array[i]);
   }
   for(int x=0;x<q;x++){
      std::getline(std::cin,query);
      int k=query[0]-'0';
      int l=query[2]-'0';;
      std::cout<<array[k][2*(l+1)]<<'\n';
   }
return 0;
}
