# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.

### Rational
  - 수를 찍어내는 클래스를 만들어 사용해봅니다.
#### 함수중복
  - 같은 이름의 함수 
  - 단, 함수 인자가 달라야함 (type or 갯수)
  - one-interface multi-method

### complex.h
#### 사용자 정의형 클래스 생성
```c
class Rational      
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
#### int형 타입의 맴버 변수 정의
  - 분자(number), 분모(denominator)
```c
int num;
int den;
```
#### 생성자 정의 (constructor)
  - 같은 이름의 다른 인자를 갖은 함수를 선언한다.
  - 맴버 함수를 초기화 한다.
  - Rational::Rational() 의 형태이다.
  - 객체가 생성될 때 자동적으로 호출된다.
  - 반환타입은 없다.
  - 함수 중복이 가능하다.
#### 기본생성자(convert constructor)
  - 인자 0개
```c
Rational();
```
#### 변환생성자(default constructor)
  - 인자 1개
```c
Rational(int num);
```
#### 일반생성자(ordinary constructor)
  - 인자 2개
```c
Rational(int num, int den);
```
#### 소멸자 정의 (destructor)
  - 객체가 소멸할때 자동적으로 호출된다.
  - 맴버 함수를 cleanup 한다.
  - Rational::~Rational() 의 형태이다.
  - 반환타입은 없다. 
  - 함수 중복이 불가능 하다
```c
~Rational();
```
#### 완성된 rational.h
```c
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
```
### rational.cpp
#### 생성자 구현
  -  넘어오는 인자에 해당하는 함수들을 구현
```c
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

```

#### 소멸자 구현
```c
Rational::~Rational(){

}
```
#### setting 함수 구현
```c
void Rational::number(int num){
    this->num = num;
}
void Rational::denominator(int den){
    this->den = den;
}
```
#### get 함수 구현
```c
int Rational::number(){
    return this->num;
}
int Rational::denominator(){
    return this->den;
}

```
#### 완성된 rational.cpp
```c
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
```
### main.cpp
#### 생성자 호출
```c
Rational r1;        /*(0/1)*/
Rational r2(3);     /*(3/1)*/
Rational r3(3,4);    /*(3/4)*/

```
#### r1에 r3대입
  - 함수의 인자로 r3값을 넘김
```c
r1.number(r3.number());
r1.denominator(r3.denominator());
```
#### 유리수 비교
- r1 과 r3가 같은지 비교한다.
```c
 if(r1.number() == r3.number() && r1.denominator() == r3.denominator()){
     std::cout << "r1 and r3 are equal" << std::endl;
 }else{
     std::cout << "r1 and r3 are not equal" << std::endl;
 }
```
#### 완성된 main.cpp
```c
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
   
   if(r1.number() == r3.number() && r1.denominator() == r3.denominator()){
       std::cout << "r1 and r3 are equal" << std::endl;
   }else{
       std::cout << "r1 and r3 are not equal" << std::endl;
   }
}
```
