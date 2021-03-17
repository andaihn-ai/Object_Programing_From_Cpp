# Object_Programing_From_Cpp

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
### safeArray.h
```c
#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <typeinfo>
#include "array.h"

template <typename T>
class SafeArray : public Array<T>{            // 'is a' : SafeArray is a Array
private : 

public :
    //SafeArray(int size);
    
    explicit SafeArray(int size = SafeArray<T>::Array::ARRAYSIZE);             // protected 맴버로 접근 => 자식쪽의 맴버가 접근 가능
    
    SafeArray(const T *pArr, int size);
    SafeArray(const SafeArray<T>& rhs);
    virtual ~SafeArray();

    SafeArray<T>& operator=(const SafeArray<T>& rhs);
    bool operator==(const SafeArray<T>& rhs) const;


    //overriding(name, return type, param) is same!
    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;
};



#include <cassert>

template <typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size)
{

}

template <typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
: Array<T>(pArr, size)
{
    
}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
: Array<T>( (Array<T>)rhs)                                 
{
    
}

template <typename T>
SafeArray<T>::~SafeArray()
{
    
}


template <typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)      
{
    return (SafeArray<T>& )this->Array<T>::operator=(( Array<T>)rhs);    
}

template <typename T>
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
    return this->Array<T>::operator==( (Array<T>)rhs);                
}


template <typename T>
T& SafeArray<T>::operator[](int index)
{
    assert(index >= 0 && index < this->Array<T>::size_ );              // protected 맴버로 접근해 size_ 를 사용할 수 있다.
    
    return this->Array<T>::operator[](index);
}

template <typename T>
const T& SafeArray<T>::operator[](int index) const
{
    assert(index >= 0 && index < this->Array<T>::size_ );              // protected
   
    return this->Array<T>::operator[](index);
}


#endif 
```
### main.cpp
```c
#include <iostream>
#include "safeArray.h"


int main()
{
    // 내부적으로 int 형을 저장하는 array 
    // <> 안의 타입을 받아 타입에 타겟팅되는 소스코드 생성

    int nums[]={1, 2, 3, 4, 5 };                    // int형 nums 배열 생성
    SafeArray<int> arr1(nums, 5);                       // int 형 array코드

    for(int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }

    double nums2[]={1.1, 2.2, 3.3, 4.4, 5.5 };
    SafeArray<double> arr2(nums2, 5);                   // double 형 array코드

    for(int i = 0; i < arr2.size(); ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
```
