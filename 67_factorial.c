#include <stdio.h>
int main(){
   int num=0,ans=1,i=1;
   scanf("%d",&num);
   while((i<=num)&&(num!=0)){
      ans=ans*(i);
      i++;
   }
   printf("%d",ans);
}