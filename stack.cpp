#include <cassert>
#include "stack.h"
#include "array.h"

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: arr_(size), tos_(0)
{

}

// 소멸자는 자동을 컴파일러가 생성해줌

void Stack::push(int data)
{   
    assert(!isFull());
    // array클래스 타입의 객체의 대괄호 연산  사용
    arr_[tos_] = data;
    ++tos_;
}
int Stack::pop()
{
    assert(!isEmpty());

    --tos_;
    return arr_[tos_];
}

bool Stack::isFull() const
{
    return (tos_ == arr_.size());
}
bool Stack::isEmpty() const
{
    return (tos_ == 0);
}
