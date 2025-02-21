#include<iostream>
using namespace std;
int main() {
   int a,b;
cout<<"Please enter the length of the rectangle"<<endl;
cin>>a;
cout<<"Please enter the breadth of the rectangle"<<endl;
cin>>b;
for(int d=0;d<b;d++)
{
   for(int c=0;c<a;c++)
   {
    cout<<"*";
   }
   cout<<endl;
}
return 0;
} 