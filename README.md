# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## complex4
  - 전역함수가 private 함수를 접근할 수 없다.
  - Complex 객체가 freind 를 통해 private 쪽의 맴버 변수에 접근한다.
  - 전역함수들을 Complex클래스의 친구로 만들어 준다. 

#### friend객체 정의
  - Compelx 클래스 안에 정의해준다.
```c
friend std::ostream& operator<<(std::ostream& out, /* const */Complex& rhs);
friend Complex operator+(const Complex& lhs, const Complex& rhs);
friend Complex operator-(const Complex& lhs, const Complex& rhs);
    
```

### 완성된 complex.h
```c
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
```
#### 전역함수를 omplex 클래스의 friend로 만들어준다
```c
std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << "," << rhs.im << "i)";
    return out;
}

Complex ::operator+(const Complex& lhs, const Complex& rhs)
{
   return Complex(lhs.re+ rhs.re, lhs.im + rhs.im);
}
Complex ::operator-(const Complex& lhs, const Complex& rhs)
{
   return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

```
### 완성된 complex.cpp
```c
#include <iostream>
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << "," << rhs.im << "i)";
    return out;
}

Complex ::operator+(const Complex& lhs, const Complex& rhs)
{
   return Complex(lhs.re+ rhs.re, lhs.im + rhs.im);
}
Complex ::operator-(const Complex& lhs, const Complex& rhs)
{
   return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;
}
Complex::~Complex()
{

}
Complex& Complex::operator=(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;
    return *this;
}
bool Complex::operator==(const Complex& rhs)const
{
    return this->re == rhs.re && this->im == rhs.im;
}

double Complex::real() const
{
    return this->re;
}
double Complex::imag() const
{
    return this->im;
}

void Complex::real(double re)
{
    this->re = re;
}
void Complex::imag(double im)
{
    this->im = im;
}

```

### main.cpp
```c
#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;                
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);      
    Complex c4 = c3;


    c2 = 4.0;

    c2 = c1 + c3;
    c2 = c1 - c3;          

    std::cout << "c1 : "<< c1 << std::endl;
    std::cout << "c2 : "<< c2 << std::endl;
    std::cout << "c3 : "<< c3 << std::endl;
    std::cout << "c4 : "<< c4 << std::endl;
    
   //std::cout << c1;  

    if(c1 == c3){
        std::cout << "c3 and c5 are equal" << std::endl;
    }else{
        std::cout << "c3 and c5 are not equal" << std::endl;
    }

    const Complex c5(3.0,4.0);
    double re = c5.real();
    return 0 ;     


}
```
### 컴파일 및 빌드
```c
g++ -c mian.cpp
g++ -c complex.cpp
g++ -o test complex.o main.o
```
### 실행 결과
```c
c1 : (0,0i)
c2 : (-3,-4i)
c3 : (3,4i)
c4 : (3,4i)
c3 and c5 are not equal
```
