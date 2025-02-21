#include <iostream>
int main(){
   std::string questions[]={
      "1.1+1= \n",
      "2.1/0= \n",
      "3.5*4= \n",
      "4.99-100= \n",
      "5.-1-1= \n"
   };
   std::string options[][4]={
      {"A.0 ","B.8 ","C.2 ","D.-1 "},
      {"A.+infinity ","B.-infinity ","C.0 ","D.undefined "},
      {"A.20 ","B.15 ","C.100 ","D.21 "},
      {"A.1 ","B.-1 ","C.0 ","D.undefined "},
      {"A.-2 ","B.5 ","C.-1 ","D.7 "}};
      char key[]={'C','D','A','B','A'};
      int score=0;
      char guess;
   for(int i=0;i<sizeof(questions)/sizeof(questions[0]);i++){
      std::cout<<questions[i];
      for(int j=0;j<sizeof(options[0])/sizeof(options[0][0]);j++){
         std::cout<<options[i][j]<<'\n';
      }
      std::cin>>guess;
      guess=toupper(guess);
      if(guess==key[i]){
         std::cout<<"CORRECT!\n";
         score++;
      }
      else{
         std::cout<<"WRONG\nThe Answer is: "<<key[i]<<'\n';
      }
   }
   std::cout<<"Correct guesses: "<<score<<"\n# of questions:"<<sizeof(questions)/sizeof(questions[0])<<"\nScore: "<<score/(double)(sizeof(questions)/sizeof(questions[0]))*100;

}