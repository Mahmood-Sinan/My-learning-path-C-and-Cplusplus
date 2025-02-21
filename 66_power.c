#include <stdio.h>
int main(){
   int base,power,i=0,ans=1;
   scanf("%d%d",&base,&power);
   while(i<power){
      ans=ans*base;
      i++;
   }
   printf("%d",ans);
}