#include <iostream>
#include <vector>
using namespace std;
int main(){
   int n,q,row,column;
   cin>>n>>q;
   vector<vector<int>>full(n,vector<int>(0));
   for(int i=0;i<n;i++){
      int size;
      cin>>size;
      full[i].resize(size);
      for(int j=0;j<size;j++){
         int element;
         cin>>element;
         full[i][j]=element;
      }
   }
   for(int i=0;i<q;i++){
      cin>>row>>column;
      std::cout<<full[row][column];
   }
   return 0;
}