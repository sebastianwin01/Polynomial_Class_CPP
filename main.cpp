//
// Created by sebastian on 10/28/26.
//

#include <iostream>
#include "polynomial.h"

int main() {
    polynomial p{2, 3, 4};
    polynomial q = p.derivative();

    std::cout << "P(2) = " << p.evaluate(2) << "\n";
    std::cout << "P'(2) = " << q.evaluate(2) << "\n";
    std::cout << "original coefficients: ";
    for (int i = 0; i <p.size();i++) {
        std::cout<< p.coefficients()[i]<< " ";
    }
    std::cout <<" Derivative: ";
    for (int i = 0; i < p.size()-1;i++) {
        std::cout<<p.derivative().coefficients()[i]<<" ";
    }
    return 0;
}