#include <iostream>
using namespace std;
int main(){
   int* p=NULL; //* used while declaring tells computer that whatever after * is a pointer.
   p=new int;
   *p=5;

   // The above whole this is equivalent to 
   // int *p=new int;
   // *p=5;
   // or
   // int *p=new int(5);
   cout<<"Address of new int ie, p is "<<p<<endl;
   cout<<"The value that p(p is an address) points to is "<<*p;

}