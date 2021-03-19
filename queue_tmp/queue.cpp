#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0),rear_(0)
{
    assert(pArr_);      //this-> 생략
}

Queue::~Queue()
{
    delete [] pArr_;
}

void Queue::push(int data)
{   
    assert( !isFull());
    pArr_[rear_] = data;
    ++rear_;
}
int Queue::pop()
{
    assert( !isEmpty());
    
    int tmp = front_;
    ++front_;
    return pArr_[tmp];
  
}

bool Queue::isEmpty() const
{
    return (front_ == rear_);
}
bool Queue::isFull() const
{
    return (rear_ == size_);
}
