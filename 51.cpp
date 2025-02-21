#include <iostream>

int main(){

   int *pNum=NULL;

   pNum=new int;

   *pNum=21;
   std::cout<<pNum<<'\n'<<*pNum;
   
   delete pNum;

   return 0;
}