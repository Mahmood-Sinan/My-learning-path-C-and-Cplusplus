#include <iostream>
void bakepizza();
void bakepizza(std::string topping1);
void bakepizza(std::string topping1,std::string topping2);
int main(){
   bakepizza("pepporoni","margareto");
}

void bakepizza(){
   std::cout<<"Here's your pizza";
}
void bakepizza(std::string topping1){
   std::cout<<"Here's your " << topping1<<" pizza";
}
void bakepizza(std::string topping1,std::string topping2){
   std::cout<<"Here's your " << topping1<<" and "<< topping2 <<" pizza";
}