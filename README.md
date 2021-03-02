# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## rational2
### Rational
  - 유리수를 찍어내는 클래스를 만들어 사용해 봅니다. 

### rational.h
#### 사용자 정의형 클래스 생성
```c
class Rational      
{
  
};
```

#### private 영역에 double형 타입의 맴버 변수 정의
  - 분자, 분모 
```c
int num;
int den;
```

#### 일반생성자(ordinary constructor)
  - 기본인자(default argument)
  - one-interface multi-method
  - 인자값이 제공 안됐을 때 대신 제공되는 값
```c
Rational(int num = 0, int den = 1);
```

#### 복사생성자(copy constructor)
  - 같은 클래스의 객체로 객체를 만들때 호출된다.
  - reference를 사용하여 복사생성자를 만든다.
  - 클래스 타입의 인자를 넘길때 오버헤드를 줄인다.
```c
Rational(const Rational& rhs);
```

#### 소멸자 정의 (destructor)

```c
~Rational();
```

#### public 영역에 연산자 맴버 함수 정의
  
```c
Rational& operator=(const Rational& rhs);
bool operator==(const Rational& rhs);
```
#### public 영역에 setting 맴버 함수 정의
```c
    void setNum(int num);
    void setDen(int den);

```
#### public 영역에 get 맴버 함수 정의
```c
    int getNum();
    int getDen();

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
    Rational(int num = 0, int den = 1);
    Rational(const Rational& rhs);
    ~Rational();

    Rational& operator=(const Rational& rhs);

    bool operator==(const Rational& rhs);

    void setNum(int num);
    void setDen(int den);

    int getNum();
    int getDen();

};

#endif
```
### rational.cpp
#### 생성자 구현
```c

Rational::Rational(int num, int den){
    this->num = num;
    this->den = den;
}
```
#### 복사생성자 구현
```c
Rational::Rational(const Rational& rhs){
    this->num = rhs.num;
    this->den = rhs.den;
}
```

#### 소멸자 구현
```c
Rational::~Rational(){

}
```
#### 치환연산 함수 구현
  - const Rational T타입의 객체를 인자로 받아온다.
  - return * this 로 맴버함수를 호출한 자기 자신 객체를 가르킨다.
  - 반환타입은 daisy-chaining을 위해 Rational& T타입의 객체로 한다.
```c
Rational& Rational::operator=(const Rational& rhs){
    this->num = rhs.num;
    this->den = rhs.den;

    return *this;
}
```
#### 비교연산자 함수 구현
  - const Rational 타입의 객체를 인자로 받아온다.
  - return this->num == rhs.num && this->den == rhs.den를 통해 bool 형식의 리턴값을 받는다.
```c
bool Rational::operator==(const Rational& rhs){
    return this->num == rhs.num && this->den == rhs.den;
}
```
#### 완성된 rational.cpp
```c
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


```
### main.cpp
#### 생성자 호출
  - c4 : 같은 클래스 타입의 객체를 가지고 객체를 생성
```c
Rational r1;        /*(0/1)*/
Rational r2(3);     /*(3/1)*/
Rational r3(3,4);    /*(3/4)*/
Rational r4(r3);

```

#### 복사 생성자 호출
```c
r1 = r3;
```

#### 유리수 비교
  - r1 과 r3가 같은지 비교한다.
```c
   if (r1 == r3){
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
    Rational r4(r3);

    r1 = r3;                    /*
                                r1.setNum(r3.getNum());
                                r1.setDen(r3.getDen());
                                */
    std::cout << "r1 : " << r1.getNum() << "/" << r1.getDen() << std::endl;
    std::cout << "r2 : " << r2.getNum() << "/" << r2.getDen() << std::endl;
    std::cout << "r3 : " << r3.getNum() << "/" << r3.getDen() << std::endl;
    std::cout << "r4 : " << r4.getNum() << "/" << r4.getDen() << std::endl;

    if (r1 == r3){
        std::cout << "r1 and r3 are equal" << std::endl;
    }else{
        std::cout << "r1 and r3 are not equal" << std::endl;
    }
    
    return 0 ;
}
```
#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c rational.cpp
g++ -o test rational.o main.o
./queue
```
#### 샐행결과
```c
r1 : 3/4
r2 : 3/1
r3 : 3/4
r1 and r3 and equal
