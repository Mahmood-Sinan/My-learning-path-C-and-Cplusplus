#include <iostream>

int main(){
   double gpa=2.5;
   std::string name="Sinan";
   char grade='F';
   bool hungry =0;
   char grades[]={'A','B','C','D','F'};
   std::string students[]={"Spongebob","Patrick","Squidward","Sandy"};
   std::cout<<sizeof(students)/sizeof(students[0])<<" elements\n";
}