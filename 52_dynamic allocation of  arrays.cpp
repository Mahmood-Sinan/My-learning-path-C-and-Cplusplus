#include <iostream>
int main(){

   char* pGrades=NULL;
   int size;

   std::cout<<"How many grades ?:\n";
   std::cin>>size;

   pGrades= new char[size];

   for(int i=0;i<size;i++){
      std::cout<<"Enter Grade #"<<i+1<<": ";
      std::cin>>pGrades[i];
   }
   for(int i=0;i<size;i++){
      std::cout<<pGrades[i]<<" ";
   }

   delete[] pGrades;

   return 0;
}