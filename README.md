# Object_Programing_From_Cpp

### template
  - 템플릿이란 매개변수의 타입에 따라 함수나 클래스 생성하는 메커니즘을 의미합니다.
  - 탬플릿을 사용하면 별도의 함수나 클래스를 만들지 않고, 하나의 함수나 클래스에서 여러 타입이 동작할 수 있습니다.

## array template
  - 임의의 타입으로 작성된 함수에 특정 타입을 매개변수로 전달하면, 컴파일러에서 함수를 생성하기 때문에 template에는 cpp파일이 없습니다.
  - array.cpp 파일을 헤더 파일로 옮겨 임의의 타입으로 함수를 작성합니다.
### array.h
#### class Array 정의
```c
class Array{
private :

protect : 

public :
};
```
#### private 맴버변수 정의
  - 사용자 정의형 메모리
  - 포인터를 맴버로 가지고 힙메모리를 사용합니다(deep copy).
```c
private :
    T *pArr_;                

```
#### protect 맴버변수 정의

```c
protected :                          
    static const int ARRAYSIZE;
    int size_;
              
```
#### public 맴버변수 정의
#### 전역변수 정의
```c
    static int getArraySize();      
```
#### 생성자정의
```c
    explicit Array(int size = Array<T>::ARRAYSIZE);
    Array(const T * pArr, int size);
    Array(const Array<T> & rhs);
    virtual ~Array();
 ```
 #### 연산자 정의
 ```c
    Array<T>& operator=(const Array<T>& rhs);

    bool operator==(const Array<T>& rhs) const;

    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;

    int size() const;

```
### 헤더파일에 함수 구현
```c
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

```

### 완성된 array.h
```c
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>          
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
#### 전처리문
```c
#include <iostream>
#include "array.h"

```
#### array 생성
  - 내부적으로 int형을 저장하는 nums array 생성
  - <> 안에 타입을 받아 타입에 타겟팅 되는 Array타입의 arr1 배열 초기화
  - 배열을 인자로 전달할때 첫 번째 element의 시작주소(nums)와 사이즈(5)를 전달한다. 
  - 매개변수로 넘겨준 nums 안의 값이 arr1에 들어갑니다.
  - 반복문을 통해 arr1의 값을 출력합니다.
```c
int main()
{

    int nums[]={1, 2, 3, 4, 5 };                  
    Array<int> arr1(nums, 5);                     

    for(int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }
 ```
  - 내부적으로 double 형을 저장하는 nums2 array 생성
  - <> 안에 타입을 받아 타입에 타겟팅 되는 Array 타입의 arr2 배열 생성
  - 배열을 인자로 전달할때 첫 번째 element의 시작주소(nums2)와 사이즈(5)를 전달한다. 
  - 매개변수로 넘겨준 nums2 안의 값이 arr2에 들어갑니다.
  - 반복문을 통해 arr2의 값을 출력합니다.
 ```c
    double nums2[]={1.1, 2.2, 3.3, 4.4, 5.5 };
    Array<double> arr2(nums2, 5);                   // double 형 array코드

    for(int i = 0; i < arr2.size(); ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
```
### 완성된 main.cpp
```c
#include <iostream>
#include "array.h"


int main()
{
 
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
