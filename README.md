# Object_Programing_From_Cpp
## 다형성

## shape.h
  - x_, y_를 자식 클래스에서 사용할 수 있도록 protected 맴버로 지정합니다.
```c
#ifndef SHAPE_H
#define SHAPE_H

class Shape{                        // Abstract Base Class(ABC)
//private :                                         -
protected :            

    int x_;
    int y_;
```
  - 추상클래스 이기때문에 default 생성자는 생성 되지않습니다.
```c
public :                               
    // default 생성자               

    Shape(int x, int y);
    
    virtual ~Shape()            // cpp에 구현할 소멸자를 헤더파일의 클레스에서 바로 구현할 수 있다
    {

    }  

    void move(int x, int y);
    // double area() const;
    
    virtual double area() const = 0 ;      // pure virtual function
};
#endif
```

##shape.cpp
```c
#include "shape.h"


Shape::Shape(int x, int y)
: x_(x), y_(y)
{

}
void Shape::move(int x, int y)
{
    this->x_ += x;
    this->y_ += y;
}

```

## rectangle.h
```c
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape {                        // Abstract Base Class(ABC)
private :
    int width_;
    int height_;

public : 
    Rectangle(int x, int y, int width, int height);
    virtual ~Rectangle(){ }

    virtual double area() const;

};
#endif
```
## ractangle.cpp
```c
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
: Shape(x,y), width_(width), height_(height)
{

}

double Rectangle::area() const
{
    return this->width_ * this->height_;
}
```

## circle.h
```c
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape {                        // Abstract Base Class(ABC)
private :
    int radius_;

public : 
    Circle(int x, int y, int radius);
    virtual ~Circle() {}

    virtual double area() const;

};
#endif 
```
## circle.cpp
```c
#include "circle.h"

Circle::Circle(int x, int y, int radius)
: Shape(x,y), radius_(radius)
{
    
}

double Circle::area() const
{

    return 3.141592 * radius_ * radius_;
}
```
## main.cpp
### 전처리문
```c
#include<iostream>
#include <typeinfo>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
```
### printArea 함수
  - RTTI : RunTime Type Identifitication 실행시간에 포인터가 가리키는 자식클래스의 객체가 무엇인지 알아낸다.
```c


void printArea(const Shape * ps)
{

    if (typeid(*ps) == typeid(Rectangle))      
    { 
        std::cout << "Rectangle";
    }
    else if (typeid(*ps) == typeid(Circle))
    { 
        std::cout << "Circle";
    }
    else{;}

    std::cout <<" area : "<< ps->area() <<std::endl;
}
```
### main 문
  - 추상클래스는 객체를 만들지 못합니다.
```c
int main()
{
    // polymorphism : 다형성 - 실행시간에 다양한 객체를 가리킨다.
    Shape * shape[5];
    shape[0] = new Rectangle(50,50,100,50);
    shape[1] = new Rectangle(50,100,30,10);
    shape[2] = new Circle(50,50, 3);
    shape[3] = new Rectangle(50,200,50,10);
    shape[4] = new Circle(100,100, 10);

    for (int i = 0 ; i<5; ++i){
        printArea(shape[i]);
    }
    return 0;
}
```
## 컴파일 및 빌드
```c
g++ -c main.cpp shape.cpp rectangle.cpp circle.cpp
g++ -o test shape.o main.o rectangle.o circle.o  
./test.exe
```
## 실행 및 결과
```c
Rectangle area : 5000
Rectangle area : 300
Circle area : 28.2743
Rectangle area : 500
Circle area : 314.159
```
