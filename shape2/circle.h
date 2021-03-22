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