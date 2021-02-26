# Object_Programing_From_Cpp
## array2
앞서 구현한 array의 전역변수 ARRAYSIZE를 static 맴버변수로 변경하고, 생성자 리스트 초기화를 사용해 봅니다. 


### array.h
```c
extern const int ARRAYSIZE;

```
위의 코드를 Array클래스의 private 영역으로 옮긴뒤 extern 대신 static 맴버 변수로 선언한다.
```c
  private:
      int *pArr_;
      int size_;
      // static 맴버변수
      static const int ARRAYSIZE;

```
#### 완성된 array.h
```c
#ifndef ARRAY_H
#define ARRAY_H

// 상수 ARRAYSIZE 전역변수로 선언후 사용


class Array{

private:
    int *pArr_;
    int size_;
    // static 맴버변수
    static const int ARRAYSIZE;

public:
    //Array();

    //explicit 명시적인 형변환을 막는다(변환생성자 동작 x)       | implicit 묵시적인 형변환
    // int형이 array 형으로 바뀌지 않는다.

    explicit Array(int size = ARRAYSIZE);

    Array(const int * pArr, int size);
    Array(const Array & rhs/*, int size*/);
    ~Array();

    Array& operator=(const Array& rhs);
    
    //set 함수 대신 치환연산을 통해서 내용을 바꾼다. 
    bool operator==(const Array& rhs) const;

    
    //치환문에 왼쪽에도 쓸 수 있다.
    int& operator[](int index);
    // 상수 객체의 reference 에서 꺼내기 떄문에 const int & 이다.
    const int& operator[](int index) const;

    // get 함수
    int size() const;


};

#endif
```

### array.cpp
#### static 맴버 변수 정의
```c
// 전역공간에 정의
//const int ARRAYSIZE = 100;

```
위의 코드를 Array::을 붙여 아래와 같이 변경한다.  
```c

// sttic 맴버변수 정의
const int Array::ARRAYSIZE = 100;

```
생성자 리스트 초기화를 한다.
  - : 맴버변수(???) 의 형식이다.
  - 맴버 변수를 초기화 하고, 해당 구문을 주석 처리한다.
```c
Array::Array(int size)
:pArr_(new int[size]),size_(size)       /* 생성자 초기화 리스트 */
{
    //this->pArr_ = new int[size];
    assert(this->pArr_ );
    //this->size_ = size;
}
Array::Array(const int *pArr, int size)
:pArr_(new int[size]), size_(size)
{
    //this->pArr_ = new int[size];
    assert(this->pArr_ );
    for(int i = 0; i<size; ++i){
        this->pArr_[i] = pArr[i];
    }
    //this->size_ = size;
}

Array::Array(const Array& rhs/*, int size*/)
:pArr_(new int [rhs.size_]), size_(rhs.size_)
{
    //this->pArr_ = new int[rhs.size_];
    assert(this->pArr_);
    for(int i = 0; i< rhs.size_; ++i){
        this->pArr_[i] = rhs.pArr_[i];
    }

    //this->size_ = rhs.size_;
}

```
#### 완성된 array.cpp
```c
#include <cassert>
#include "array.h"

const int Array::ARRAYSIZE = 100;

Array::Array(int size)
:pArr_(new int[size]),size_(size)       /* 생성자 초기화 리스트 */
{
    
    assert(this->pArr_ );
    
}
Array::Array(const int *pArr, int size)
:pArr_(new int[size]), size_(size)
{
    //this->pArr_ = new int[size];
    assert(this->pArr_ );
    for(int i = 0; i<size; ++i){
        this->pArr_[i] = pArr[i];
    }
    //this->size_ = size;
}

Array::Array(const Array& rhs/*, int size*/)
:pArr_(new int [rhs.size_]), size_(rhs.size_)
{
    //this->pArr_ = new int[rhs.size_];
    assert(this->pArr_);
    for(int i = 0; i< rhs.size_; ++i){
        this->pArr_[i] = rhs.pArr_[i];
    }

    //this->size_ = rhs.size_;
}

Array::~Array()
{
    delete [] this->pArr_;
}

Array& Array::operator=(const Array& rhs){
    if(this != &rhs){
        delete[] this->pArr_;
        this->pArr_ = new int[rhs.size_];
        assert(this->pArr_ );

        for(int i = 0; i < rhs.size_; ++i){
            this->pArr_[i] = rhs.pArr_[i];
        }
        this->size_ = rhs.size_;
    }
    return * this;
}
bool Array::operator==(const Array& rhs) const
{
    if(this->size_ != rhs.size_){
        return false;
    }
    
    int i;
    for(i = 0; i < this->size_; ++i){
        if(this->pArr_[i] != rhs.pArr_[i])
            break;
    }
    
    return (i == this->size_);
}
//get 함수
int Array::size() const
{
    return this->size_;
}

int& Array::operator[](int index){
    return this->pArr_[index];
}
    
const int& Array::operator[](int index) const{

    return this->pArr_[index];
}
```

### main.cpp
#### 완성된 main.cpp
```c
#include <iostream>
#include "array.h"

int main(){

    //Array arr1;
    Array arr2(10);

    int nums[] = {1,2,3,4,5};
    Array arr3(nums,5);
    Array arr4(arr3);

    
    if(arr3 == arr4){
        std::cout << "arr3 and arr4 are equal" << std::endl;
    }else{std::cout << "arr3 and arr4 are not equal" << std::endl;}

    for(int i = 0; i< arr3.size(); ++i){
        std::cout<< arr3[i] << std::endl;       //arr3[i]--> arr3.operator[](i)

    }

    
    return 0;

}
```
