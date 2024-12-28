#include <iostream>
#include "complex.hpp"

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;

    Complex sum = c1 + c2;
    std::cout << "c1 + c2: " << sum << std::endl;

    Complex diff = c1 - c2;
    std::cout << "c1 - c2: " << diff << std::endl;

    Complex product = c1 * c2;
    std::cout << "c1 * c2: " << product << std::endl;

    Complex quotient = c1 / c2;
    std::cout << "c1 / c2: " << quotient << std::endl;


    double n = 2.0;
    Complex addReal = c1 + n;
    std::cout << "c1 + 2.0: " << addReal << std::endl;

    Complex subReal = c1 - n;
    std::cout << "c1 - 2.0: " << subReal << std::endl;

    Complex mulReal = c1 * n;
    std::cout << "c1 * 2.0: " << mulReal << std::endl;

    Complex c3;
    std::cout << "input into format {a+b}: \n";
    std::cin >> c3;

    std::cout << c3 << std::endl;

    return 0;
}
