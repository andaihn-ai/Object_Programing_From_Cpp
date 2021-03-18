# Object_Programing_From_Cpp
## safeArray exception

### safeArray.h
```c
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
```
### safeArray.cpp
  - safeArray쪽에서 예외처리 하는것이 아닌 client(main) 쪽에서 예외처리를 해줍니다.
  - throw()키워드를 이용해 예외값을 넘겨줍니다.
```c
int& SafeArray::operator[](int index)
{

  throw int(1); 
  return this->Array::operator[](index);
}
const int& SafeArray::operator[](int index) const
{
  throw int(1);

  return this->Array::operator[](index);
}

```
### 완성된 safeArray.cpp
```c
#include <cassert>
#include "safeArray.h"

SafeArray::SafeArray(int size)
: Array(size)
{

}
SafeArray::SafeArray(const int *pArr, int size)
: Array(pArr, size)
{
    
}
SafeArray::SafeArray(const SafeArray& rhs)
: Array( (Array)rhs)              //slicing                  
{
    
}
SafeArray::~SafeArray()
{
    
}

SafeArray& SafeArray::operator=(const SafeArray& rhs)      
{
    return (SafeArray&)this->Array::operator=((Array)rhs);     
}
bool SafeArray::operator==(const SafeArray& rhs) const
{
    return this->Array::operator==( (Array)rhs);               
}

int& SafeArray::operator[](int index)
{
    
    throw int(1); 
    return this->Array::operator[](index);
}
const int& SafeArray::operator[](int index) const
{
    throw int(1);
    
    return this->Array::operator[](index);
}
```
### array.h
```c
#ifndef ARRAY_H
#define ARRAY_H

//array class 

class Array{
private :
    

    int * pArr_;
    int size_;
public:
    static const int ARRAYSIZE;
    explicit Array(int size = Array::ARRAYSIZE);
    Array(const int * pArr, int size);
    Array(const Array & rhs);
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
```c
#include "array.h"
#include <cassert>

const int Array::ARRAYSIZE = 100;

Array::Array(int size)
: pArr_(new int[size]), size_(size)
{
    assert(pArr_);
}
Array::Array(const int * pArr, int size)
:  pArr_(new int[size]), size_(size)
{
    assert(pArr_);
    for(int i = 0; i<size; ++i )
    {
        pArr_[i] = pArr[i];
    }
}
Array::Array(const Array & rhs)
: pArr_(new int[rhs.size_]),size_(rhs.size_)        // 복사생성자 이기 떄문에 원본 객체의 값을 받아와서 생성
{
    assert(pArr_);
    for(int i = 0; i < rhs.size_; ++i){
        pArr_[i] = rhs.pArr_[i];
    }
}
Array::~Array()
{
    delete [] pArr_;
}
Array& Array::operator=(const Array& rhs)
{
    if(this != &rhs)
    {
        delete [] pArr_;
        pArr_ = new int[rhs.size_];
        assert(pArr_ );
        size_ = rhs.size_;
        for(int i = 0; i< rhs.size_; ++i){
            pArr_[i] = rhs.pArr_[i];
        }
    }
    return * this;
}
bool Array::operator==(const Array& rhs) const
{
    if (size_ != rhs.size_){
        return false;
    }
    int i ;
    for( i = 0; i< rhs.size_; ++i){
        if(pArr_[i] != rhs.pArr_[i]){
            break;
            }
    }
    return (i == rhs.size_);
}

int& Array::operator[](int index)
{
    return pArr_[index];
}
const int& Array::operator[](int index) const
{
    return pArr_[index];
}

int Array::size() const
{
    return size_;
}
```
### main.cpp
  - 예외가 발생할 만한 코드블럭을 try 문으로 묶어준다.
```c
try         
  {
      Array arr5(nums,5);
      for (int i = 0; i<= arr5.size(); ++i){
          std::cout<< arr5[i] << std::endl;
          }

      Array *pArr = new SafeArray(nums,5);                   
      (*pArr)[5] = 5;   

      delete pArr; 

  } 
```
  - safeArray 쪽에서 예외를 발생시키면 catch문으로 받습니다.
  - 위에서 처리하고 남은 나머지들은 catch(...)문에서 처리합니다.
  - cerr함수는 내부적으로 버퍼를 사용하지 않고 출력합니다.
```c
catch(int e) {
      std::cerr << "we receive exception code : " << e << std::endl;
      return e;
  } catch(double e) {
      //
  } catch(...) {          
      // 위에서 처리하고 남은 나머지들
  }
```
### 완성된main.cpp
```c
#include <iostream>
#include "safeArray.h" 


int main(){

    SafeArray arr1;
    SafeArray arr2(10);
    int nums[] = {1,2,3,4,5};
    SafeArray arr3(nums,5);
    SafeArray arr4(arr3);

    arr1 = arr3;

    if(arr1 == arr3){
        std::cout << "arr1 and arr3 are equal" << std::endl;

    }else{
        std::cout << "arr1 and arr3 are not equal" << std::endl;
    }
    
    // 예외가 발생할 가능성이 있는 블록을 묶어준다 
    try         
    {
        Array arr5(nums,5);
        for (int i = 0; i<= arr5.size(); ++i){
            std::cout<< arr5[i] << std::endl;
            }

        Array *pArr = new SafeArray(nums,5);                   
        (*pArr)[5] = 5;   
        
        delete pArr; 
        
    } catch(int e) {
        std::cerr << "we receive exception code : " << e << std::endl;
        return e;
    } catch(double e) {
        //
    } catch(...) {          
        // 위에서 처리하고 남은 나머지들
    }


    
    return 0 ;
}
```
