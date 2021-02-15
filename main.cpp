#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;        /*(0/1)*/
    Rational r2(3);     /*(3/1)*/
    Rational r3(3,4);    /*(3/4)*/

    r1.number(r3.number());
    r1.denominator(r3.denominator());

    std::cout << "r1 : " << r1.number() << "/" << r1.denominator() << std::endl; 
    std::cout << "r2 : " << r2.number() << "/" << r2.denominator() << std::endl; 
    std::cout << "r3 : " << r3.number() << "/" << r3.denominator() << std::endl; 
    
}