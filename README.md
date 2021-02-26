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

    
    int& operator[](int index);
    const int& operator[](int index) const;

    int size() const;


};

#endif
```
### array.cpp
##### 상수 ARRAYSIZE 정의
  - #define 은 전처리 떄 코드 치환이 된다. 
  - 상수로 처리 해놓으면 컴파일 될 때 좀더 엄격하게 타입채킹 한다.
  - 전역공간에 정의
```c
    const int ARRAYSIZE = 100;
```
##### 생성자 함수 구현
```c
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

```

##### 소멸자 함수 구현
```c

    Array::~Array()
    {
        delete [] this->pArr_;
    }
```

##### 치환 연산자 구현
  - 자기 자신을 치환할때 원본이 delete로 날라가는 문제를 해결하기 위해 주소값을 비교하여 같은 값이 아닌 경우 실행
  - 사이즈도 함께 치환해준다.
```c
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
```

##### 비교 연산자 구현
  - this->size_ 와  rhs.size 가 같은지 체킹하고,  다르다면 비교할 필요 없다.
  - 사이즈가 같다면 반복문을 이용해 같은지 비교한다.
  - i 와 맴버변수의 사이즈가 같다면 마지막까지 같은 걸로 간주한다.
```c
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
```

##### get함수 구현
```c
    int Array::size() const
    {
        return this->size_;
    }
```

##### 대괄호함수 구현
  - 힙상에 element가 생성될 공간을 만들어놈
  - 그 공간을 reference로 넘긴다.
```c
    int& Array::operator[](int index){
        return this->pArr_[index];
    }

    const int& Array::operator[](int index) const{
        return this->pArr_[index];
    }
```

#### 완성된 array.cpp
```c
#include <cassert>
#include "array.h"

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
