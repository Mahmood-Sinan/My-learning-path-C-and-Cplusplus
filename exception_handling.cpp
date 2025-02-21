#include <iostream>
#include <string>
using namespace std;
class Printer {
   private:
      string name;
      int available_paper;
   public:
      Printer(string name,int available_paper){
         this->name=name;
         this->available_paper=available_paper;
      }
      void Print(string txtDoc){
         int req_paper = (txtDoc.length()+9)/10;
         if(req_paper>available_paper){
            throw "No Paper\n";
         }
         if(txtDoc == ""){
            throw 101; //nothing to print
         }
         cout<<"Printing... "<<txtDoc<<'\n';
         available_paper -= req_paper;
      }
};
int main(){
   Printer myPrinter("HP deskjet",15);
   try{
      myPrinter.Print("Hello... I am Mahmood Sinan. I am an Engineering Design student.");
   }
   catch(const char* txtException){
      cout<<"Exception: "<<txtException;
   }
   catch(int exCode){
      cout<<"Exception: "<<exCode<<'\n';
   }
   catch(...){ //default handler, if the exception still happens and above specific handlers cannot handle.
      cout<<"Exception happened\n";
   }
   

   cout<<"Code ended\n";
   return 0;
}