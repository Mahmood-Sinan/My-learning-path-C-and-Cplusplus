#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
   int a;
   cout<<"Please enter the number of lines in the pyramid"<<endl;
   cin>>a;
   for(int b=1;b<=a;b++)
   {
      for (int c=a-b;c>=0;c--)
      {
         cout<<" ";
      }
      for (int d=1;d<=2*b-1;d++)
      {
         cout<<"*";
      }
      cout<<'\n';
   }
   return 0;
   }