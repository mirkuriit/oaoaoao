#include "rational.hpp"
#include <iostream>

int main(){
    Rational a = Rational(1, 3);
    Rational b = Rational(1, 3);
    Rational c = -a;
    Rational d = Rational(1, 2);

    std::cout << a+b << "\n";
    std::cout << a-b << "\n";
    std::cout << a*b << "\n";
    std::cout << a/b << "\n";

    std::cout << (a==b) << "\n";
    std::cout << (a!=b) << "\n";
    std::cout << (a>=b) << "\n";
    std::cout << (a<=b) << "\n";

    std::cout << (c>=b) << "\n";
    std::cout << (d<=b) << "\n";


    
}