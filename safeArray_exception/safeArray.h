#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

 // Array상속 Array 클래스로 부터 public을 상속받아 SafeArray를 만든다.
class SafeArray : public Array{            // 'is a' : SafeArray is a Array
private : 

public :
    //SafeArray(int size);
    
    //explicit SafeArray(int size = SafeArray::Array::getArraySize();)      // default인자로 함수호출...private 맴버함수
    explicit SafeArray(int size = SafeArray::Array::ARRAYSIZE);             // protected 맴버로 접근 => 자식쪽의 맴버가 접근 가능
    
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray& rhs);
    virtual ~SafeArray();

    SafeArray& operator=(const SafeArray& rhs);
    bool operator==(const SafeArray& rhs) const;


    //overriding(name, return type, param) is same!
    virtual int& operator[](int index);
    virtual const int& operator[](int index) const;
};

#endif