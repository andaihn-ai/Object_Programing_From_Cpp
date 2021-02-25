#include "rational.h"


Rational::Rational(int num, int den){
    this->num = num;
    this->den = den;
}
Rational::Rational(const Rational& rhs){
    this->num = rhs.num;
    this->den = rhs.den;
}
Rational::~Rational(){

}
Rational& Rational::operator=(const Rational& rhs){
    this->num = rhs.num;
    this->den = rhs.den;

    return *this;
}
bool Rational::operator==(const Rational& rhs){
    return this->num == rhs.num && this->den == rhs.den;
}
void Rational::setNum(int num){
    this->num = num;
}
void Rational::setDen(int den){
    this->den = den;
}

int Rational::getNum(){
    return this->num;
}
int Rational::getDen(){
    return this->den;
}

