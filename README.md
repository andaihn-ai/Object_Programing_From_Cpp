# Object_Programing_From_Cpp
## array

### array.h
#### 맴버변수 정의
```c
    int *pArr_;
    int size_;
```
#### 맴버 함수 정의
  - explicit 명시적인 형변환을 막는다(변환생성자 동작 x)    
  - int형이 array 형으로 바뀌지 않는다.

```c
     explicit Array(int size = ARRAYSIZE);
```
##### 생성자 정의
```c
    explicit Array(int size = ARRAYSIZE);

    Array(const int * pArr, int size);
    Array(const Array & rhs/*, int size*/);
    ~Array();

```
##### 치환연산자 정의
  - setting 함수를 대신해 내용을 변경한다.
```c
    Array& operator=(const Array& rhs);
    
```
##### 비교 연산자 정의
 ```c
    bool operator==(const Array& rhs) const;
    
```
##### 대괄호 연산자 정의
  - 상수 객체의 reference 에서 꺼내기 떄문에 const int & 이다.
  - 치환문 왼쪽에서도 쓸 수 있다.
```c
    int& operator[](int index);
    const int& operator[](int index) const;

```

##### get함수 정의
```c
  int size() const;
```
#### 완성된 array.h
```c
#ifndef ARRAY_H
#define ARRAY_H

// 상수 ARRAYSIZE 전역변수로 선언후 사용
extern const int ARRAYSIZE;

class Array{

private:
    int *pArr_;
    int size_;

public:
    //Array();

   
    explicit Array(int size = ARRAYSIZE);

    Array(const int * pArr, int size);
    Array(const Array & rhs/*, int size*/);
    ~Array();

    Array& operator=(const Array& rhs);
     
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


#### 완성된 array.cpp
```c
#include <cassert>
#include "array.h"


// #define 은 전처리때 코드 치환이 된다
// 상수처리 해놓으면  컴파일될때 타입채킹한다.
// 전역공간에 정의
const int ARRAYSIZE = 100;


/*
Array::Array()
{
    this->pArr_ = new int[100];
    assert(this->pArr_ );
    this->size_ = 100;
}
*/
Array::Array(int size){
    this->pArr_ = new int[size];
    assert(this->pArr_ );
    this->size_ = size;
}
Array::Array(const int *pArr, int size)
{
    this->pArr_ = new int[size];
    assert(this->pArr_ );
    for(int i = 0; i<size; ++i){
        this->pArr_[i] = pArr[i];
    }
    this->size_ = size;
}

Array::Array(const Array& rhs/*, int size*/){
    this->pArr_ = new int[rhs.size_];
    assert(this->pArr_);
    for(int i = 0; i< rhs.size_; ++i){
        this->pArr_[i] = rhs.pArr_[i];
    }

    this->size_ = rhs.size_;
}

Array::~Array()
{
    delete [] this->pArr_;
}
// 자기 자신을 치환할때 원본이 delete로 날라가는 문제를 해결하기 위해 주소값을 비교하여 같은 값이 아닌 경우 실행
// 사이즈도 치환해준다.
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
{    // this->size_ 와  rhs.size 가 다르다면 비교할 필요 없음
    if(this->size_ != rhs.size_){
        return false;
    }
    // 사이즈가 같다면 반복문을 이용해 같은지 비교한다.
    int i;
    for(i = 0; i < this->size_; ++i){
        if(this->pArr_[i] != rhs.pArr_[i])
            break;
    }
    //i 와 사이즈가 같으면 마지막 까지 같다.
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
    // 힙상에 element가 생성될 공간을 만들어놈
    // 그 공간을 reference로 넘긴다.
    return this->pArr_[index];
}
```

### main.cpp


#### 완성된 main.cpp
```c
#ifndef ARRAY_H
#define ARRAY_H

// 상수 ARRAYSIZE 전역변수로 선언후 사용
extern const int ARRAYSIZE;

class Array{

private:
    int *pArr_;
    int size_;

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
