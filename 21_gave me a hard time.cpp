#include <iostream>
using namespace std;
int main(){
   int a,b,c;
   cin>>a;
   cin>>b;
   c=a;
   switch(a){
   case 1 :
      cout<<"one\n";
      if(c==b){
         break;
      }
      c=c+1;
      cout<<"two\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"three\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"four\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"five\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 2 :
      cout<<"two\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"three\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"four\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"five\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 3 :
      cout<<"three\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"four\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"five\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 4 :
      cout<<"four\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"five\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 5 :
      cout<<"five\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 6 :
      cout<<"six\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 7 :
      cout<<"seven\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 8 :
      cout<<"eight\n";
      if (c==b){
         break;
      }
      c=c+1;
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   case 9 :
      cout<<"nine\n";
      if (c==b){
         break;
      }
      c=c+1;
      break;
   }
   if(b>9){
      for(int j=10;j<=b;j+=1){
         if(j%2==0){
            cout<<"even\n";
         }
         else{
            cout<<"odd\n";
         }
      }
   }
return 0;
}