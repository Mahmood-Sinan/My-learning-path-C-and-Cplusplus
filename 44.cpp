#include <iostream>
int main(){

   std::string questions[]={  "1.What year was C++ created?",
                              "2.Who invented C++?",
                              "3.What is the predeccessor of C++?",
                              "4.Is the Earth flat?"};
   std::string options[][4]=  {{"A.1969","B.1975","C.1985","D.1989"},
                              {"A.The creator","B.Njan","C.Ikkarilla","D.None of the above"},
                              {"A.Java","B.C#","C.Python","D.C"},
                              {"A.Yes","B.No","C.Maybe","D.Sometimes"}};
char answerkey[]={'C', 'A', 'D', 'B'};
int size=sizeof(questions)/sizeof(questions[0]);
char guess;
int score=0;
for(int i=0;i<size;i++){
   std::cout<<"*****************\n";
   std::cout<<questions[i]<<'\n';
   std::cout<<"*****************\n";
   for(int j=0;j<sizeof(options[i])/sizeof(options[i][0]);j++){
      std::cout<<options[i][j]<<'\n';
   }
   std::cin>>guess;
   guess=toupper(guess);
   if (guess==answerkey[i]){
      std::cout<<"CORRECT!\n";
      score++;
   }
   else{
      std::cout<<"WRONG!\nAnswer: "<<answerkey[i]<<'\n';
   }
};
std::cout<<"*****************\nRESULT\n*****************\nCORRECT GUESSES: "<<score<<"\n# OF QUESTIONS: "<<size<<"\nPERCENTAGE: "<<score/(double)size*100<<"%";
return 0;
}