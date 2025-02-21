#include <iostream>
using namespace std;
template<typename x,typename y>
void sys(){
    x name;
    y age;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"You are: "<<name<<'\n';
    cout<<"You are "<<age<<" years old\n";
}

template<typename T>
void Print(T value){
    cout<<"The value that passed is: "<<value<<'\n';
}

template<typename datatype,int T>//T should be specified and it is a non type template parameter. 
/* typename vs non-type template parameters
typename is used when you're declaring types as template parameters. For example, typename T is used when you want to specify a type (like int, string, float, etc.) in your template.
non-type template parameters are typically values (like integers or pointers) and are used for things like array sizes, or constants. For these, you don't use typename; instead, you directly specify the type (like int, char, double, etc.). */
class Array{
    private:
        datatype a[T];
    public:
        Array(){
            cout<<"Enter the "<<T<<" elements for the array\n";
            for(int i=0;i<T;i++){
                cin>>a[i];
            }
            cout<<"The array is: ";
            for(const auto& cur: a){
                cout<<cur<<' ';
            }
            cout<<'\n';
        }
};
int main() {
    
    sys<string,int>();
    Print("Okay");
    Array<string,5> names;
    return 0;
}