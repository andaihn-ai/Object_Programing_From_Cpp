# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## complex2
### complex
  - 실수와 허수로 이루어진 수
  - 통해 실수를 찍어내는 클래스를 만들어 사용해봅니다.

### complex.h
#### 사용자 정의형 클래스 생성
```c
class Complex      
{
  
};
```

#### private 영역에 double형 타입의 맴버 변수 정의
  - 실수부, 허수부
```c
double re;
double im;
```

#### 일반생성자 정의(ordinary constructor)
  - 기본인자(default argument)
  - one-interface multi-method
  - 인자값이 제공 안됐을 때 대신 제공되는 값
```c
Complex(double re = 0.0, double im = 0.0);
```

#### 복사생성자 (copy constructor)
  - 같은 클래스의 객체로 객체를 만들때 호출된다.
  - reference를 사용하여 복사생성자를 만든다.
  - 클래스 타입의 인자를 넘길때 오버헤드를 줄인다.
```c
Complex(const Complex &rhs);
```

#### 소멸자 정의 (destructor)

```c
~Complex();
```

#### public 영역에 연산자 맴버 함수 정의
  
```c
Complex& operator=(const Complex& rhs);
bool operator==(const Complex& rhs);

Complex operator+(const Complex& rhs);
Complex operator-(const Complex& rhs);
```
#### public 영역에 setting 맴버 함수 정의
```c
void real(double re);
void imag(double im);

```
#### public 영역에 get 맴버 함수 정의
```c
double real();
double imag();
```

#### 완성된 complex.h
```c
#ifndef COMPLEX_H
#define COMPLEX_H
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
    bool operator==(const Complex& rhs);

    Complex operator+(const Complex& rhs);
    Complex operator-(const Complex& rhs);
    
    void real(double re);
    void imag(double im);

    double real();
    double imag();
};
#endif
```
### complex.cpp
#### 생성자 구현
```c

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}
```
#### 복사생성자 구현
```c
Complex::Complex(const Complex& rhs){
    this->re = rhs.re;
    this->im = rhs.im;
}
```
#### 소멸자 구현
```c
Complex::~Complex()
{

}
```
#### 치환연산 함수 구현
  - const Complex T타입의 객체를 인자로 받아온다.
  - return * this 로 맴버함수를 호출한 자기 자신 객체를 가르킨다.
  - 반환타입은 daisy-chaining을 위해 Complex& T타입의 객체로 한다.
```c
Complex& Complex::operator=(const Complex& rhs){
    this->re = rhs.re;
    this->im = rhs.im;
    return *this;
}
```
#### 비교연산자 함수 구현
  - const Complex 타입의 객체를 인자로 받아온다.
  - return this->re == rhs.re && this->im == rhs.im를 통해 bool 형식의 리턴값을 받는다.
```c
bool Complex::operator==(const Complex& rhs){
    return this->re == rhs.re && this->im == rhs.im;
}
```
#### 더하기 연산자 함수 구현
  - 
```c
Complex Complex::operator+(const Complex& rhs){
    Complex result(this->re + rhs.re, this->im + rhs.im);
    return result;
}
```
#### 빼기 연산자 함수 구현
  - 
```c
Complex Complex::operator-(const Complex& rhs){
    Complex result(this->re - rhs.re, this->im - rhs.im);
    return result;
}

```

#### 완성된 complex.cpp
```c
#include "complex.h"

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs){
    this->re = rhs.re;
    this->im = rhs.im;
}
Complex::~Complex()
{

}
Complex& Complex::operator=(const Complex& rhs){
    this->re = rhs.re;
    this->im = rhs.im;
    return *this;
}
bool Complex::operator==(const Complex& rhs){
    return this->re == rhs.re && this->im == rhs.im;
}
Complex Complex::operator+(const Complex& rhs){
    Complex result(this->re + rhs.re, this->im + rhs.im);
    return result;
}
Complex Complex::operator-(const Complex& rhs){
    Complex result(this->re - rhs.re, this->im - rhs.im);
    return result;
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

    Complex c5;
    c5  = c3;

    c1 = 3.0;           /*c1.operator=(3.0) or ::operator=(c1,3.0)*/

    c4 = c2 + c3;       

    c5 = c2 -c3;                                
    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;
    std::cout << "c5 : (" << c5.real() << ", " << c5.imag() << "i)" << std::endl;
    
 
    if(c3.real() == c5.real() && c3.imag() == c5.imag()){
        std::cout << "c3 and c5 are equal" << std::endl;
    }else{
        std::cout << "c3 and c5 are not equal" << std::endl;
    }

    return 0 ;       /*소멸자 */


}
```
