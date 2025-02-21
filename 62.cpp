#include <iostream>
#include <vector>
int main(){
   std::vector<int>n(5);
   n.assign(4,1);
   n.insert(n.end(),2);
   for(int i=0;i<n.size();i++){
      std::cout<<n[i]<<"";
   }
   
return 0;

}