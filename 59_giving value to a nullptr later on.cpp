#include <iostream>
int main(){

   int* ptr=NULL;
   int array[][2]{
      {1,2},
      {5,6},
      {7,8}
   };
   ptr=&array[2][1];
   std::cout<<*ptr;

   return 0;
}