//
// Created by sebastian on 10/28/26.
//

#ifndef C_PROJECTS_POLYNOMIAL_H
#define C_PROJECTS_POLYNOMIAL_H

#include <cstddef>
#include <initializer_list>
class polynomial {
public:
    //regual constructor
    polynomial(std::initializer_list<double> values);
    //destructor
    ~polynomial();
    // Copy constructor
    polynomial(const polynomial& other);
    //assignment constructor
    polynomial&operator=(const polynomial & other) ;
    //move constructor
    polynomial( polynomial && other) noexcept;
    //move assigment overloding
    polynomial& operator =(polynomial && other ) noexcept;
    //derivate funtion
    polynomial derivative();
    // funtion to evaluate polynomial
    double evaluate(double x) const;
    // to get the coeficients and print it easily, next to size funtion in a for loop.
    const double* coefficients () const;
    std::size_t size() const;



private:
    size_t  len_;
    double * coef_;

};


#endif //C_PROJECTS_POLYNOMIAL_H