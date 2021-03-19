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
    // assert(index >= 0 && index < this->Array::size_ );          // 범위를 벗어나면 프로그램 종료...(X) client 쪽에서 예외 처리를 하도록 한다(O)
    
    throw int(1); // int 형으로 객체를 만듬 -> 1로 세팅된 int값을 예외 값을 던짐

    return this->Array::operator[](index);
}
const int& SafeArray::operator[](int index) const
{
  
    // assert(index >= 0 && index < this->Array::size_ );          
   
    throw int(1);
    
    return this->Array::operator[](index);
}