#include <iostream>
int main(){
   //std::string students[]={"Spongebob","Patrick","Squidwarrd","Sandy"};
   char grades[]={'A','B','C','D','F'};
   for(char grade :grades){
      std::cout<<grade<<'\n';
   }
}