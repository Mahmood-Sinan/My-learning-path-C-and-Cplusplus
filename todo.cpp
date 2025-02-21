#include <iostream>
#include <vector>
using namespace std;
class page{
   public:
   string heading;
   vector<string> page_elements;

   page(string heading){
      this->heading=heading;
   }
};

void page_option(int option,page current_page){
   while(option!=3){
      if(option == 1){
         string task;
         cout<<"Enter the task: ";
         getline(std::cin, task);
         current_page.page_elements.push_back(task);
         for(string task : current_page.page_elements){
            cout<<"* "<<task<<'\n';
         }
         cout<<"Enter an option\n1.Add a task\n2. Remove a task\n3.Go back\n";
         cin>>option;
      }
      else {
         int num = 0;
         cout<<"Enter the task number that you want to remove: ";
         cin>> num;
         current_page.page_elements.erase(current_page.page_elements.begin()+num);
         for(string task : current_page.page_elements){
            cout<<"* "<<task<<'\n';
         }
         cout<<"Enter an option\n1.Add a task\n2. Remove a task\n3.Go back\n";
         cin>>option;
      }
   }
}

int main(){
   cout<<"Welcome to TO DO List\n";
   bool is_running = true;
   vector<page> to_do_book;
   string heading;
   int page_no = 0;
   int option = 0;
   cout<< (to_do_book.size()==0?"You have 0 pages\n":"Your pages:\n");
   for(int i=0;i< to_do_book.size();i++ ){
      cout<<"Page: "<<i+1<<'-'<<to_do_book[i].heading<<'\n';
   }
   while(is_running){
      int choice = 0;
      do{
      cout<<"Enter an option\n1. Add a page\n2. Go to a page\n3. Remove a page\n4. Quit\n";
      cin>>choice;
      if(!(choice==1||choice==2||choice==3||choice==4)) cout<<"Enter a valid choice\n";
      }while(!(choice==1||choice==2||choice==3||choice==4));
      switch(choice){
         case 1:
            cout<<"Enter the heading of the page\n";
            getline(std::cin, heading);
            to_do_book.push_back(page(heading));
            break;
         case 2:
            cout<<"Enter the page number that you want to go to: ";
            cin>>page_no;
            for(string task : to_do_book[page_no].page_elements){
               cout<<"* "<<task<<'\n';
            }
            cout<<"Enter an option\n1.Add a task\n2. Remove a task\n3.Go back\n";
            cin>>option;
            page_option(option,to_do_book[page_no]);
            break;
         case 3:
            cout<<"Enter the page number that you want to delete: ";
            cin>>page_no;
            to_do_book.erase(to_do_book.begin()+page_no);
            break;
         default: cout<<"Enter a valid option: ";
      }
   }

}