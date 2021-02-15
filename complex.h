#ifndef COMPLEX_H
#define COMPLEX_H
class Complex       /*사용자 정의형 클래스*/
{
  
private:        /*맴버변수*/
    /*복소수는 실수부와 허수부로 구성된다.*/
    double re;      /*real part : 실수부  */
    double im;      /*imagenary part : 허수부 */
    
public:         /*맴버함수*/
    /*생성자*/
    Complex();
    Complex(double re);
    Complex(double re, double im);
    
    /*소멸자*/
    ~Complex();
    
    /*setting*/
    void real(double re);
    void imag(double im);

    /*get*/
    double real();
    double imag();
};
#endif