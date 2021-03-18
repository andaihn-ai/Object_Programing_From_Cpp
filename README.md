# Object_Programing_From_Cpp
## stack tamplate

### stack.h
```c
#ifndef STACK_H
#define STACK_H
#include "array.h"

template <typename T>
class Stack{
private:
    static const int STACKSIZE;

    Array<T> arr_;    

    int tos_;

    Stack(const Stack<T>& rhs);
    Stack<T>& operator=(const Stack<T> & rhs);

public:

    explicit Stack(int size = STACKSIZE);
    
    // void push(T data) 대신 class타입의 객체를 넘길때를 고려하여 void push(const T& data) 로 정의한다.
    void push(const T& data);
    const T pop();

    bool isFull() const;
    bool isEmpty() const;
};


#include <cassert>

template <typename T>
const int Stack<T>::STACKSIZE = 100;

template <typename T>
Stack<T>::Stack(int size)
: arr_(size), tos_(0)
{

}

template <typename T>
void Stack<T>::push(const T & data)
{   
    assert(!isFull());
    arr_[tos_] = data;
    ++tos_;
}

template <typename T>
const T Stack<T>::pop()
{
    assert(!isEmpty());

    --tos_;
    return arr_[tos_];
}

template <typename T>
bool Stack<T>::isFull() const
{
    return (tos_ == arr_.size());
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (tos_ == 0);
}


#endif
```
###
```c
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>           // 소스코드를 구성하고 있는 클래스, 변수, 함수 에 template <typename T> 준다. type T 를 받아서 소스코드 생성
class Array{

private :
    T *pArr_;                
protected :                          
    static const int ARRAYSIZE;
    int size_;

public:
    
    static int getArraySize();      

    explicit Array(int size = Array<T>::ARRAYSIZE);
    Array(const T * pArr, int size);
    Array(const Array<T> & rhs);
    virtual ~Array();
   
    Array<T>& operator=(const Array<T>& rhs);

    bool operator==(const Array<T>& rhs) const;

    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;

    int size() const;

};

#include <cassert>

template <typename T>
const int Array<T>::ARRAYSIZE = 100;

template <typename T>
int Array<T>::getArraySize()
{
    return Array<T>::ARRAYSIZE;        //전역변수값을 리턴
}

template <typename T>
Array<T>::Array(int size)
: pArr_(new int[size]), size_(size)
{
    assert(pArr_);
}

template <typename T>
Array<T>::Array(const T * pArr, int size)
:  pArr_(new T[size]), size_(size)
{
    assert(pArr_);
    for(int i = 0; i<size; ++i )
    {
        pArr_[i] = pArr[i];
    }
}


template <typename T>
Array<T>::Array(const Array<T> & rhs)
: pArr_(new T[rhs.size_]),size_(rhs.size_)        // 복사생성자 이기 떄문에 원본 객체의 값을 받아와서 생성
{
    assert(pArr_);
    for(int i = 0; i < rhs.size_; ++i){
        pArr_[i] = rhs.pArr_[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete [] pArr_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(this != &rhs)
    {
        delete [] pArr_;
        pArr_ = new T[rhs.size_];
        assert(pArr_ );
        size_ = rhs.size_;
        for(int i = 0; i< rhs.size_; ++i){
            pArr_[i] = rhs.pArr_[i];
        }
    }
    return * this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& rhs) const
{
    if (size_ != rhs.size_){
        return false;
    }
    int i ;
    for( i = 0; i< rhs.size_; ++i){
        if(pArr_[i] != rhs.pArr_[i])
        {break;}
    }
    return (i == rhs.size_);
}

template <typename T>
T& Array<T>::operator[](int index)
{
    return pArr_[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    return pArr_[index];
}

template <typename T>
int Array<T>::size() const
{
    return size_;
}

#endif
```

### main.cpp
```c
}

```
