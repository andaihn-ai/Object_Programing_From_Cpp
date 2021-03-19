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

// double Shape::area() const
// {
//     // is not implemented!

// }