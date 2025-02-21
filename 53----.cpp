#include <iostream>
int main(){

   int n,q;
   std::cin>>n>>q;
      int **array=new int*[n];

   for(int i=0;i<n;i++){
      int columns;
      std::cin>>columns;
      array[i]=new int[columns];
      for(int j=0;j<columns;j++){
         std::cin>>array[i][j];
      }
   }
   for(int i=0;i<q;i++){
      int a,b;
      std::cin>>a>>b;
      std::cout<<array[a][b]<<'\n';
   }
   for(int i=0;i<n;i++){
      delete[] array[i];
   }
   delete[] array;

return 0;
}
