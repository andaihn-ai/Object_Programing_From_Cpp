#ifndef COMPLEX_H
#define COMPLEX_H
class Complex       /*사용자 정의형 클래스*/
{
  
private: 
    double re;     
    double im;     
    
public:       
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex &rhs);
    ~Complex();
    
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs);

    Complex operator+(const Complex& rhs);
    Complex operator-(const Complex& rhs);
    


    void real(double re);
    void imag(double im);

    double real();
    double imag();
};
#endif