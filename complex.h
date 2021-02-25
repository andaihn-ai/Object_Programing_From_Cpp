#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

//class Complex;

class Complex     
{

friend std::ostream& operator<<(std::ostream& out, /* const */Complex& rhs);

friend Complex operator+(const Complex& lhs, const Complex& rhs);
friend Complex operator-(const Complex& lhs, const Complex& rhs);
    
private: 
    double re;     
    double im;     
    
public:       
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex &rhs);
    ~Complex();
    
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs) const;

    double real() const;
    double imag() const;

    void real(double re);
    void imag(double im);

};
#endif