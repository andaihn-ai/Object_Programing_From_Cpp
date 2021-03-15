# Object_Programing_From_Cpp

### template
  - 템플릿이란 매개변수의 타입에 따라 함수나 클래스 생성하는 메커니즘을 의미합니다.
  - 탬플릿을 사용하면 별도의 함수나 클래스를 만들지 않고, 하나의 함수나 클래스에서 여러 타입이 동작할 수 있습니다.

## array template
### array.h
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
### array.cpp
```c

// template 코드는 cpp파일이 없다.
// 타입을 받아 코드를 생성하기 떄문

```
### main.cpp
```c
#include <iostream>
#include "array.h"


int main()
{
    // 내부적으로 int 형을 저장하는 array 
    // <> 안의 타입을 받아 타입에 타겟팅되는 소스코드 생성

    int nums[]={1, 2, 3, 4, 5 };                    // int형 nums 배열 생성
    Array<int> arr1(nums, 5);                       // int 형 array코드

    for(int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }

    double nums2[]={1.1, 2.2, 3.3, 4.4, 5.5 };
    Array<double> arr2(nums2, 5);                   // double 형 array코드

    for(int i = 0; i < arr2.size(); ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
```

### 컴파일 및 빌드

### 실행결과
