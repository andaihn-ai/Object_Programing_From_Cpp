#include "complex.h"

Complex::Complex()
{
    /* default constructor*/
    this->re = 0.0;
    this->im = 0.0;
}
Complex::Complex(double re)
{
    /* convert constructor*/
    this->re = re;
    this->im = 0.0;
}
Complex::Complex(double re, double im)
{
    /* ordinary constructor*/
    this->re = re;
    this->im = im;
}
Complex::~Complex()
{

}
void Complex::real(double re)
{
    this->re = re;
}
void Complex::imag(double im)
{
    this->im = im;
}
double Complex::real()
{
    return this->re;
}
double Complex::imag()
{
    return this->im;
}
