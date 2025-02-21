#include <iostream>
void display(int *pArray,int position);
void modify(int *pArray,int position,int x);
int main(){

   std::cout<<"Enter the position of the number: ";
   int position;
   std::cin>>position;
   std::string option;
   int array[]={12,21,35,46,57,63,70,89,94};

   display(array,position);//arrays are passed in to a function as pointers

   std::cout<<"Type a if you want to modify this value: ";
   std::cin>>option;
   std::cout<<'\n';
   if(option=="a"){
      std::cout<<"Type the modified value: ";
      int x;
      std::cin>>x;
      modify(array,position,x);
   }

return 0;
}

void display(int *pArray,int position){
   std::cout<<pArray[position-1]<<'\n';
}

void modify(int *pArray,int position,int x){
   pArray[position]=x;
   int size =sizeof(pArray)/sizeof(pArray[0]);
   std::cout<<size;
   for(int i=0;i<size;i++){

      std::cout<<pArray[i]<<" ";
   }
}