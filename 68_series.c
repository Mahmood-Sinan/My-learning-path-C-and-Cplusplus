#include <stdio.h>
int main(){
   int x,n,j=0,power,i,num,k;
   float coeff1,term,base;
   unsigned long long factorial;
   float sum=0;
   printf("Sum of the n terms of the series x-x^3/3!+x^5/5!...\nEnter the value of x:\n");
   scanf("%d",&x);
   printf("Enter the value of n:\n");
   scanf("%d",&n);
   while(j<n){
      base=-1,power=j,i=0,coeff1=1;
   while(i<power){
      coeff1=coeff1*base;
      i++;
   }
   base=x,power=(2*j)+1,i=0,term=1;
   while(i<power){
      term=term*base;
      i++;
   }
   num=(2*j)+1,factorial=1,k=1;
   while((k<=num)&&(num!=0)){
      factorial=factorial*(float)(k);
      k++;
   }
      sum=sum+(coeff1*term)/factorial;
      j++;
   }
   printf("The sum of the series is %f",sum);
}