//Knuth-Morris-Pratt Algorithm

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildlps(string pattern){
   
   int m=pattern.length();
   vector<int>lps(m,0); //longest prefix suffix table
   int j=0;
   int i=1;
   while(i<m){
      if(pattern[i]==pattern[j]){
         j++;
         lps[i]=j;
         i++;
      }
      else{
         if(j!=0) j=lps[j-1];
         else lps[i]=0;
         i++;
      }
   }
   return lps;

}

int main(){

   // string str="nizamuddin",substr="ddi";
   string str,substr;
   cout<<"Enter the string: ";
   cin>>str;
   cout<<"Enter the substring to search for: ";
   cin>>substr;
   vector<int>lps=buildlps(substr);
   vector<int> answerindexes;
   cout<<"lps table for "<<substr<<" is: ";
   for(int cur:lps){
      cout<<cur<<' ';
   }
   cout<<'\n';
   int i=0,j=0;
   while(i<str.length()){
      if(str[i]!=substr[j]){ //mismatch then shift j back if we can, shift i forward if we can't
         if(j!=0){
            j=lps[j-1];
         }
         else{
            i++;
         }
      }
      else{ //if match then look forward for next letter match
         i++;
         j++;
      }
      if(j==substr.length()){ // if a sub string is completely found, look further for another match
         answerindexes.push_back(i-j);
         j=lps[j-1];
      }
   }
   cout<<"The answer indexes are: ";
   for(int answers:answerindexes){
      cout<<answers<<' ';
   }
   cout<<'\n';

   return 0;
}