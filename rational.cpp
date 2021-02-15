#include "rational.h"
Rational::Rational(){
    this->num = 0;
    this->den = 1;
}
Rational::Rational(int num){
    this->num = num;
    this->den = 1;
}
Rational::Rational(int num, int den){
    this->num = num;
    this->den = den;
}
Rational::~Rational(){

}

void Rational::number(int num){
    this->num = num;
}
void Rational::denominator(int den){
    this->den = den;
}

int Rational::number(){
    return this->num;
}
int Rational::denominator(){
    return this->den;
}