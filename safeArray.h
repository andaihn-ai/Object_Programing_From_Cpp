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