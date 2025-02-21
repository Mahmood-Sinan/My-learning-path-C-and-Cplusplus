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

        complex operator+(const complex& other){
            return complex(real + other.real, img + other.img);
        }
        complex operator-(const complex& other){
            return complex(real - other.real, img - other.img);
        }
        complex operator*(const complex& other){
            return complex(real * other.real - img * other.img, real * other.img + img *  other.real);
        }
        complex operator/(const complex& other){
            if(other.real == 0 && other.img == 0){
                return complex(0,0);
            }
            else{
                complex conjugate(other.real, -other.img);
                complex result = *this * conjugate;
                result.real = result.real/(conjugate.real * conjugate.real + conjugate.img * conjugate.img);
                result.img = result.img/(conjugate.real * conjugate.real + conjugate.img * conjugate.img);
                return result;
            }
        }
        bool operator==(const complex& other){
            return real == other.real && img == other.img;
        }
        void display() const{
            cout<<real<<" + "<<img<<"i"<<'\n';
        }
};

int main(){
    complex num1(1,2), num2(3,4);
    complex add = num1 + num2, subtract = num1 - num2, multiply = num1 * num2, quotient = num1 / num2;
    cout<<"Sum: ";
    add.display();
    cout<<"Difference: ";
    subtract.display();
    cout<<"Product: ";
    multiply.display();
    cout<<"Quotient: ";
    if(num2 == complex(0,0)){
        cout<<"Denominator cannot be zero\n";
    }
    else{
        quotient.display();
    }
    return 0;
}