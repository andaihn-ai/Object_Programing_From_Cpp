#ifndef SHAPE_H
#define SHAPE_H

class Shape{                        // Abstract Base Class(ABC)
//private :                                         -
protected :             // 자식쪽에서 사용할수있게..  #

    int x_;
    int y_;

public :                                //   +
    // default 생성자               // is not generated   추상클래스이기때문에
    // 치환연산                     // can not used
    // &

    Shape(int x, int y);
    
    virtual ~Shape()            // cpp에 구현할 소멸자를 헤더파일의 클레스에서 바로 구현할 수 있다
    {

    }  

    void move(int x, int y);
    // double area() const;
    
    virtual double area() const = 0 ;      // pure virtual function
};
#endif