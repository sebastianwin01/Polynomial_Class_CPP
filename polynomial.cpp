//
// Created by sebastian on 10/28/26.
//
#include "polynomial.h"

polynomial::polynomial(std::initializer_list<double> values)
    :len_(values.size()), coef_(new double[len_])
{
    std::size_t i = 0;

    for (double value : values) {
        coef_[i] = value;
        i++;
    }
}
// Destructor
polynomial::~polynomial () {
    delete [] coef_;
}

// Copy constructor
polynomial::polynomial(const polynomial& other)
    : len_(other.len_), coef_(new double[len_])
{
    for (std::size_t i = 0; i < len_; i++) {
        coef_[i] = other.coef_[i];
    }
}
//assignment operator= overloading
polynomial& polynomial::operator=(const polynomial &other) {

    // if it is not the same object then:
    if (this != &other) {
        //create dynamic list newCoef variable so we can store other.coef_ data safely
        double* newCoef = new double [other.len_];

        //iterate over the two dynamic lists
        for (int i = 0 ;i < other.len_;i++) {
            newCoef[i] = other.coef_[i];
        }

        // as we store the information in a new variable we can clean the buffer
        delete [] coef_;

        len_ = other.len_;
        coef_ = newCoef;
    }

    return *this;
}
polynomial:: polynomial(polynomial && other) noexcept
    :len_(other.len_), coef_(other.coef_)
{
    other.len_ = 0;
    other.coef_ = nullptr;
}
// this move assignment operator definition completes the rule of 5
polynomial& polynomial::operator=(polynomial &&other) noexcept
{
    if (this != &other) {
        delete[] coef_;
        len_ = other.len_;
        coef_ = other.coef_;

        other.len_ = 0;
        other.coef_ = nullptr;
    }
    return *this;
}


polynomial polynomial::derivative() {

    // If polynomial is constant or empty
    if (len_ <= 1) {
        return polynomial{0};
    }

    // Create a polynomial to store the resul
    polynomial result{0};

    // allocate memory for derivative coefficients
    double* newCoef = new double[len_ - 1];

    // calculate derivative coefficients
    for (std::size_t i = 1; i < len_; i++) {
        newCoef[i - 1] = coef_[i] * i;
    }

    // release the initial array of result
    delete[] result.coef_;

    // Assign new coefficients to result
    result.coef_ = newCoef;
    result.len_ = len_ - 1;

    return result;
}
// evaluate implementation
double polynomial::evaluate(double x) const {
    double result = 0;
    double power = 1;

    for (std::size_t i = 0; i < len_; i++) {
        result += coef_[i] * power;
        power *= x;
    }

    return result;
}

const double* polynomial::coefficients () const {
    return coef_;
}

std::size_t polynomial::size() const {
    return len_;
}





