# Object_Programing_From_Cpp

## template
  - 템플릿이란 매개변수의 타입에 따라 함수나 클래스 생성하는 메커니즘을 의미합니다.
  - 탬플릿을 사용하면 별도의 함수나 클래스를 만들지 않고, 하나의 함수나 클래스에서 여러 타입이 동작할 수 있습니다.
  - 타입을 받아서 만들어 지는 코드에 tamplate <typename T> 를 붙여줍니다.
  - 임의의 타입을 받아 저장하는 Array <T> 를 붙여줍니다. 클래스 이름, 생성자와 소멸자는 <T>를 사용하지 않습니다.


## array.h
### class Array 정의
```c
tamplate <typename T>
class Array{
private :

protect : 

public :
};
```
### private 맴버변수 정의
  - 사용자 정의형 메모리
  - 포인터를 맴버로 가지고 힙메모리를 사용합니다(deep copy).
```c
private :
    T *pArr_;                

```
### protect 맴버변수 정의

```c
protected :                          
    static const int ARRAYSIZE;
    int size_;
              
```
## public 맴버변수 정의
  - 아래와 같이 전역변수, 생성자, 소멸자, 연산자를 정의합니다.
### 전역변수 정의
```c
    static int getArraySize();      
```
### 생성자정의
```c
    explicit Array(int size = Array<T>::ARRAYSIZE);
    Array(const T * pArr, int size);
    Array(const Array<T> & rhs);
```
### 소멸자 정의
  - 가상함수가 선언되면 소멸자는 반드시 가상으로 선언해야 합니다.
```c
    virtual ~Array();
 ```
 ### 연산자 정의
 ```c
    Array<T>& operator=(const Array<T>& rhs);

    bool operator==(const Array<T>& rhs) const;
```
### 가상함수 대괄호 연산자 정의
  - virtual 멤버함수의 원형;
  - virtual 키워드를 사용해 가상함수를 선언하면 파생 클래스에서 재정의된 맴버 함수도 자동으로 가상 함수가 됩니다. 
  - 클래스 내에 가상함수가 하나 이상 포함이 되면 소멸자에는 반드시 virtual를 붙여줍니다.
  - 가상함수는 프로그램이 실행될 때 객체를 결정하므로, 컴파일 타임에 해당 객체를 특정할 수 없습니다.
  - 가상함수는 런타임에 올바르게 실행되어야 하기 때문에 동적으로 바인딩(함수를 호출하는 코드에서 어느 블록에 있는 함수를 실행하라는 의미로 해석) 합니다.
  - 가상함수도 결합하는 타입이 분명할때에는 일반 함수와 같이 정적 바인딩 합니다.
  - 클래스 타입의 포인터나 참조를 통하여 호출될 때만 동적 바인딩을 하게됩니다.
  - 가상함수를 사용하면 함수의 호출 과정이 복잡해지므로, 메모리와 실행속도 측면에서 부담이됩니다. 따라서 C++에서 기본 바인딩은 정적 바인딩이며, 필요한 경우 가상함수로 선언하도록 합니다.
  - 파생 클래스가 재정의할 가능성이 있는 함수는 모두 가상함수로 선언하는 것을 권장합니다.
```c
    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;
```
### 배열 사이즈 함수 정의
```c
    int size() const;

```
## 헤더파일에 array.cpp 함수 구현
### array template
  - 임의의 타입으로 작성된 함수에 특정 타입을 매개변수로 전달하면, 컴파일러에서 함수를 생성하기 때문에 template에는 cpp파일이 없습니다.
  - array.cpp 파일을 헤더 파일로 옮겨 임의의 타입으로 함수를 작성합니다.
```c
#include <cassert>

template <typename T>
const int Array<T>::ARRAYSIZE = 100;

template <typename T>
int Array<T>::getArraySize()
{
    return Array<T>::ARRAYSIZE;        //전역변수값을 리턴
}
```
### 생성자 템플릿 구현
  - 임의의 타입 T타입으로 저장하기 위해 자료형 <T>를 붙여줍니다.
```c
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
```
### 소멸자 템플릿 구현 
  - 임의의 타입 T타입으로 저장하기 위해 자료형 <T>를 붙여줍니다.
```c
template <typename T>
Array<T>::~Array()
{
    delete [] pArr_;
}
```
### 치환 연산자 템플릿 구현
  - 임의의 타입 T타입으로 저장하기 위해 자료형 <T>를 붙여줍니다.

```c
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
```
### 비교 연산자 템플릿 구현
  - 임의의 타입 T타입으로 저장하기 위해 자료형 <T>를 붙여줍니다.
```c
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
```
### 대괄호 연산자 템플릿 구현
  - 임의의 반환값을 T 타입으로 정의해 줍니다.
```c
template <typename T>
T& Array<T>::operator[](int index)
{
    return pArr_[index];
}
```
### const 대괄호 연산자 템플릿 구현
  - 임의의 반환값을 T 타입으로 정의해 줍니다.
```c
template <typename T>
const T& Array<T>::operator[](int index) const
{
    return pArr_[index];
}

```
### array 사이즈 리턴 템플릿 구현
```c
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
## main.cpp
### 전처리문
```c
#include <iostream>
#include "array.h"

```
### array 생성
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

## 완성된 main.cpp
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
## 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -o test main.o
./test.exe
```
## 실행결과
```c
1
2
3
4
5
1.1
2.2
3.3
4.4
5.5
```
