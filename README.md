# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
### complex
  - 실수오 허수로 이루어진 수
  - 통해 실수를 찍어내는 클래스를 만들어 사용해봅니다.
#### 함수중복
  - 같은 이름의 함수 
  - 단, 함수 인자가 달라야함 (type or 갯수)
  - one-interface multi-method

### complex.h
#### 사용자 정의형 클래스 생성
```c
class Complex      
{
  
};
```
#### 내부구현이 들어갈 private 영역
  - 맴버 변수 
```c
private: 
```
#### 인터페이스 구현이 들어갈 public 영역
  - 맴버 함수
  - public쪽의 맴버 함수를 통해서 private쪽의 맴버 변수에 접근
```c
public: 
```
#### double형 타입의 맴버 변수 정의
  - 실수부, 허수부
```c
double re;
double im;
```
#### 생성자 정의 (constructor)
  - 같은 이름의 다른 인자를 갖은 함수를 선언한다.
  - 맴버 함수를 초기화 한다.
  - Complex::complex() 의 형태이다.
  - 객체가 생성될 때 자동적으로 호출된다.
  - 반환타입은 없다.
  - 함수 중복이 가능하다.
#### 기본생성자(convert constructor)
  - 인자 0개
```c
Complex();
```
#### 변환생성자(default constructor)
  - 인자 1개
```c
Complex(double re);
```
#### 일반생성자(ordinary constructor)
  - 인자 2개
```c
Complex(double re, double im);
```
#### 소멸자 정의 (destructor)
  - 객체가 소멸할때 자동적으로 호출된다.
  - 맴버 함수를 cleanup 한다.
  - Complex::~Complex() 의 형태이다.
  - 반환타입은 없다. 
  - 함수 중복이 불가능 하다
```c
~Complex();
```
#### 완성된 complex.h
```c
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
```
### complex.cpp
#### 생성자 구현
  -  넘어오는 인자에 해당하는 함수들을 구현
```c
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
```

#### 소멸자 구현
```c
Complex::~Complex()
{

}
```
#### setting 함수 구현
```c
void Complex::real(double re)
{
    this->re = re;
}
void Complex::imag(double im)
{
    this->im = im;
}

```
#### get 함수 구현
```c
double Complex::real()
{
    return this->re;
}
double Complex::imag()
{
    return this->im;
}

```
#### 완성된 complex.cpp
```c
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

```
### main.cpp
#### 생성자 호출
```c
Complex c1;
Complex c2 = 3.0;
Complex c3(3.0, 4.0);
```
#### 복소수 더하기
  - 함수의 인자로 c1 + c2 를 넘김
```c
Complex c4;
c4.real(c1.real()+c2.real());
c4.imag(c1.imag()+c2.imag());
std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;
```
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
    Complex c1;                 /*(0.0, 0.0) */
    /*Complex c2(3.0);*/        /*(3.0, 0.0) */
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);       /*(3.0, 4.0) */

    c1.real(3.0);
    c1.imag(4.0);

    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    
    Complex c4;
    c4.real(c1.real()+c2.real());
    c4.imag(c1.imag()+c2.imag());
    std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;


    if(c1.real() == c3.real() && c1.imag() == c3.imag()){
        std::cout << "c1 and c3 are equal" << std::endl;
    }else{
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    return 0 ;       /*소멸자 */


}
```
#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c complex.cpp
g++ -o test complex.o main.o
./queue
```
#### 샐행결과
```c
c1 : (3, 4i)
c2 : (3, 0i)
c3 : (3, 4i)
c4 : (6, 4i)
c1 and c3 are equal
