#include <iostream>
#include <vector>
#include <string>
using namespace std;

class complex{
    private:
    public:
        double real,img;
        complex(double real, double img){
            this -> real = real;
            this -> img = img;
        }

        complex operator+(const complex other){
            return complex(real + other.real, img + other.img);
        }
        complex operator-(const complex& other){
            return complex(real - other.real, img - other.img);
        }
        complex operator*(const complex& other){
            return complex(real * other.real - img * other.img, real * other.img + img *  other.real);
        }
};

int main(){
    complex num1(1,2), num2(3,4);
    complex add = num1 + num2, subtract = num1 - num2, multiply = num1 * num2;
    cout<<"Sum: "<<add.real<<" + "<<add.img<<"i"<<'\n';
    cout<<"Difference: "<<subtract.real<<" + "<<subtract.img<<"i"<<'\n';
    cout<<"Product: "<<multiply.real<<" + "<<multiply.img<<"i"<<'\n';
    return 0;
}