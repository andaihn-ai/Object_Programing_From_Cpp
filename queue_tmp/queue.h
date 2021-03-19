#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

template <typename T>
class Queue{
private:
    static const int QUEUESIZE;

    Array<T> arr_;
    int front_;
    int rear_;

    Queue(const Queue<T>& rhs);
    Queue<T>& operator=(const Queue<T> & rhs);

public:
 
    explicit Queue(int size = QUEUESIZE);
    
    void push(const T & data);
    const T pop();

    bool isFull() const;
    bool isEmpty() const;
};

#include <cassert>


template <typename T>
const int Queue<T>::QUEUESIZE = 100;

template <typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{
    
}

template <typename T>
void Queue<T>::push(const T& data)
{   
    assert( !isFull());
    arr_[rear_] = data;
    ++rear_;
}

template <typename T>
const T Queue<T>::pop()
{
    assert( !isEmpty());
    
    int tmp = front_;
    ++front_;
    return arr_[tmp];
  
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return (front_ == rear_);
}

template <typename T>
bool Queue<T>::isFull() const
{
    return (rear_ == arr_.size());
}




#endif