// #include <stdio.h>
// void print(int *a){
//    for(int i=0;i<5;i++){
//       for(int j=0;j<3;j++){
//          printf("%d ",*((a+i*3)+j));
//       }
//       printf("\n");
//    }
// }
// int main(){
//    int a[5][3]={
//       {10,20,30},
//       {40,50,60},
//       {70,80,90},
//       {100,110,120},
//       {130,140,150}
//    };
//    print((int*)a);
// }

// #include <stdio.h>
// void print(char *a[]){
//    for(int i=0;i<3;i++){
//       printf("%s\n",a[i]);
//    }
// }
// int main(){
//    char* a[3]={"Delhi","Ahmedabad","Madras"};//a is a 1d array of 3 pointers which points to address of D, A, M respectively so here we treat it as normal array
//    print(a);
// }

#include <stdio.h>
void print(char **a){
   for(int i=0;i<3;i++){
      printf("%s %s\n",*(a+i),a[i]);
   }
}
int main(){
   char* a[3]={"Delhi","Ahmedabad","Madras"};//a is a 1d array of 3 pointers which points to the address of D, A, M respectively.so passing into fn, but a is also the pointer to first element, ie it points to the pointer which has address of D. so it is a double pointer to a character. so dereferencing a just once gets us the pointer to address of a. so if we add a number to that pointer , it will only gets us to the address of next character,ie 'e'. so we should add a number before dereferencing to get the next element.then only it will jump by the pointer width(8byte).
   print(a);
}