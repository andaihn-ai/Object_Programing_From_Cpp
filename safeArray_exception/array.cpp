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