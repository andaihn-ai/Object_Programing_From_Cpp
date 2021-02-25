# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## complex3
### complex
  - 실수와 허수로 이루어진 수
  - 통해 실수를 찍어내는 클래스를 만들어 사용해봅니다.

### complex.h
### cout에 직접 구현한 coplex형 객체를 바로 출력
  - std::cout << c1;의 형태
  - std::cout.operator<<(c1) 맴버함수로 정의 못함
  - ::operator<<(std::cout,c1) 반드시 전역함수로 정의함
  - cout 은 ostream(라이브러리 함수)객체이므로 전역함수를 통해 접근한다.

#### 출력하는 전역함수 정의
 - 첫 번째 인자로 ostream클래스 타입의 cout이 값이 바뀌기 위해 reference로 들어온다.
 - 
```c
class Complex;

std::ostream& operator<<(std::ostream& out, /* const */Complex& rhs);
```
```c
Complex operator+(Complex& lhs, Complex& rhs);
Complex operator-(Complex& lhs, Complex& rhs);
    

```
#### 완성된 complex.h
```c
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex;

std::ostream& operator<<(std::ostream& out, Complex& rhs);

Complex operator+(Complex& lhs, Complex& rhs);
Complex operator-(Complex& lhs, Complex& rhs);
    

class Complex     
{
  
private: 
    double re;     
    double im;     
    
public:       
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex &rhs);
    ~Complex();
    
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs) const;

    void real(double re);
    void imag(double im);

    double real() const;
    double imag() const;
};
#endif
```
### complex.cpp
#### 출력하는 전역함수 구현
  - out이라는 레퍼런스로 cout을 aliasing
  - 왼쪽쉬프트 연산으로 리턴값은 out(cout)이 된다.
  - 인자로 받은 cout을 리턴해주기 위해 &로 반환한다.
```c
std::ostream& operator<<(std::ostream& out, /* const */Complex& rhs)
{
    out << "(" << rhs.real() << "," << rhs.imag() << "i)";
    return out;
}
```
#### 완성된 complex.cpp
```c
#include <iostream>
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.real() << "," << rhs.imag() << "i)";
    return out;
}

Complex ::operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}
Complex ::operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
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
bool Complex::operator==(const Complex& rhs)const{
    return this->re == rhs.re && this->im == rhs.im;
}

void Complex::real(double re)
{
    this->re = re;
}
void Complex::imag(double im)
{
    this->im = im;
}
double Complex::real() const
{
    return this->re;
}
double Complex::imag() const
{
    return this->im;
}

```
### main.cpp
#### 생성자 호출
  - c4 : 같은 클래스 타입의 객체를 가지고 객체를 생성
```c
Complex c1;
Complex c2 = 3.0;
Complex c3(3.0, 4.0);
```

#### 복사 생성자 호출
```c
Comcplex c4 = c3;
```

#### daisy-chain
  - c5 = c4 = c3
  - Complex& Complex::operator=(const Complex& rhs)
#### 복소수 비교
  - c1 과 c3가 같은지 비교한다.
```c
if(c1.real() == c3.real() && c1.imag() == c3.imag()){
    std::cout << "c1 and c3 are equal" << std::endl;
}else{
    std::cout << "c1 and c3 are not equal" << std::endl;
}
```
#### 완성된 main.cpp
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
    
    std::cout << c1;  
    if(c1 == c3){
        std::cout << "c3 and c5 are equal" << std::endl;
    }else{
        std::cout << "c3 and c5 are not equal" << std::endl;
    }

    const Complex c5(3.0,4.0);
    c5.real(5.0);
    return 0 ;     


}
```
