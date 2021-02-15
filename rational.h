#ifndef RATIONAL_H
#define RATIONAL_H
class Rational
{
private:
    int num;
    int den;
public:
    Rational();
    Rational(int num);
    Rational(int num, int den);
    ~Rational();

    void number(int num);
    void denominator(int den);

    int number();
    int denominator();
};

#endif