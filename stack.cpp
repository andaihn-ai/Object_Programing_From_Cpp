#include <cassert>
#include "stack.h"

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
    assert(pArr_);      //this-> 생략
}

Stack::~Stack()
{
    delete [] pArr_;
}

void Stack::push(int data)
{   
    assert(!isFull());
    pArr_[tos_] = data;
    ++tos_;
}
int Stack::pop()
{
    assert(!isEmpty());
    --tos_;
    return pArr_[tos_];
}

bool Stack::isFull() const
{
    return (tos_ == size_);
}
bool Stack::isEmpty() const
{
    return (tos_ == 0);
}
