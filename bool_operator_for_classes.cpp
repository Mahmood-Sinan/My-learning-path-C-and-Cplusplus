#include <iostream>
#include <cmath>
using namespace std;
class student{
    public:
    string name;
    int age;

    student(string name, int age){
        this->name=name;
        this->age=age;
    }

    bool operator<(const student& other) const{
        return age<other.age;
    }
};
int main(){
    
    student student1("sinan",19);
    student student2("ikram",18);
    cout<<student1.name<<' '<<student1.age<<'\n';
    cout<<student2.name<<' '<<student2.age<<'\n';
    cout<<(student1<student2);

}