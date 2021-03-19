#include<iostream>
#include <typeinfo>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

void printArea(const Shape * ps)
{

                // 연산자
    if (typeid(*ps) == typeid(Rectangle))       //RTTI : RunTime Type Identifitication 실행시간에 포인터가 가리키는 자식클래스의 객체가 무엇인지 알아낸다.
    { 
        std::cout << "Rectangle";
        //Rectangle *pRec = (Rectangle * )ps;
        Rectangle * pRec = dynamic_cast<const Rectangle * >(ps)
        //
    }
    else if (typeid(*ps) == typeid(Circle))
    { 
        std::cout << "Circle";
        //Circle * pCir = (Circle)ps;
        Circle * pCir = dynamic_cast<const Circle * >(ps);
        //
    }
    else{;}

    std::cout <<" area : "<< ps->area() <<std::endl;
}

int main()
{
    // Shape s;        // 추상클래스는 객체 못만듬

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