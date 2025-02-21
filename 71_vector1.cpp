#include <iostream>
#include <vector>
int main(){
   std::vector <int> num;
   for(int i=0;i<100;i++){
      num.push_back(i+1);
   }
   num.pop_back();
   for(int i=0;i<100;i++){
      std::cout<<num[i]<<'\n';
   }
}