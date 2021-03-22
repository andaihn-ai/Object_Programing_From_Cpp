#include <cassert>
#include "array.h"


// #define 은 전처리때 코드 치환이 된다
// 상수처리 해놓으면  컴파일될때 타입채킹한다.
// 전역공간에 정의
//const int ARRAYSIZE = 100;

// sttic 맴버변수 정의
const int Array::ARRAYSIZE = 100;

/*
Array::Array()
{
    this->pArr_ = new int[100];
    assert(this->pArr_ );
    this->size_ = 100;
}
*/


// 생성자에서 맴버변수들에게 값을 줄 때 생성자 초기화 리스트로 줄 수 있다.

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