#include <iostream>
#include <vector>
using namespace std;
void print(vector<char>v,int size){
    for(int i=0;i<size;i++){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    string s="){";
        vector<char>v;
        if(s.size()%2==1){
            cout<<"Vector has odd size\n";
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                v.push_back(s[i]);
                print(v,v.size());
            }
            else if(s[i]==')'&&v.back()=='('){
                v.pop_back();
                print(v,v.size());
            }
            else if(s[i]==']'&&v.back()=='['){
                v.pop_back();
                print(v,v.size());
            }
            else if(s[i]=='}'&&v.back()=='{'){
                v.pop_back();
                print(v,v.size());
            }
        }
        cout<<(v.size()==0)?1:0;
        return 0;
    }