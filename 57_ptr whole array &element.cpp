#include <iostream>
int main(){

   int a=3,b=5;
   int array[][b]={
      {1,2,3,4,5},
      {15,45,3,54,78},
      {74,58,6,12,39}
   };

   int (*parray)[b]=array; //ptr to whole array
   int *ptrtoelement=&array[1][3];

   std::cout<<"The adress of array is: "<<parray<<'\n'; //address of the whole array(can be obtained if we typed array name at pointer name too)
   std::cout<<"The element 0 1 is: "<<parray[0][1]<<'\n'; //accessing an element with ptr to whole array
   std::cout<<"The address of element 1 3 is: "<<ptrtoelement<<'\n';//address of the element
   std::cout<<"The element 1 3 is:"<<*ptrtoelement<<'\n';//accessing the value of the pointer

   return 0;
}