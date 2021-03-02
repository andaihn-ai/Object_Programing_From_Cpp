# Object_Programing_From_Cpp
## Stack from C to Cpp

### stack.h

#### 완성된 stack.h
```c
#ifndef STACK_H
#define STACK_H

class Stack{
private:
    static const int STACKSIZE;

    int *pArr_;
    int size_;
    int tos_;

    // client 코드에서 사용할 수 없다.
    Stack(const Stack& rhs);
    Stack& operator=(const Stack & rhs);

public:
    // Stack* operator&();
    // const Stack* operator&() const;

    explicit Stack(int size = STACKSIZE);
    ~Stack();

    void push(int data);
    int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif
```

### stack.cpp
#### 생성자 초기화 리스트 사용
  -  맴버 변수를 초기화 하면 this-> 를 생략할 수 있다.
 ```c
     Stack::Stack(int size)
    : pArr_(new int[size]), size_(size), tos_(0)
    {
        assert(pArr_);      //this-> 생략
    }

 ```
#### push / pop 함수 구현
```c
    void Stack::push(int data)
    {   
        assert(!isFull());
        pArr_[tos_] = data;
        ++tos_;
    }
    int Stack::pop()
    {
        assert(!isEmpty());
        --tos_;
        return pArr_[tos_];
    }
```

#### isFull/ isEmpty함수 구현
  - 스택의 값이 꽉 차있을 때 push를 하거나, 비어있을 때 pop하면 안되기 떄문에 오류검사를 하기 위해 사용한다.
 ```c
     bool Stack::isFull() const
    {
        return (tos_ == size_);
    }
    bool Stack::isEmpty() const
    {
        return (tos_ == 0);
    }

 ```
#### 완성된 stack.cpp
```c
#include <cassert>
#include "stack.h"

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
    assert(pArr_);      //this-> 생략
}

Stack::~Stack()
{
    delete [] pArr_;
}

void Stack::push(int data)
{   
    assert(!isFull());
    pArr_[tos_] = data;
    ++tos_;
}
int Stack::pop()
{
    assert(!isEmpty());
    --tos_;
    return pArr_[tos_];
}

bool Stack::isFull() const
{
    return (tos_ == size_);
}
bool Stack::isEmpty() const
{
    return (tos_ == 0);
}

```

### main.cpp
#### push함수 사용 
  - s1 스택에 값을 넣는다.
```c
    s1.push(100);
    s1.push(200);
    s1.push(300);
```
#### pop함수 사용
  - 반복문을 이용해 스택의 값을 pop하여 출력한다.
 ```c
     while( !s1.isEmpty()){
        std::cout<< "s1 pop(): " << s1.pop() << std::endl;
    }
 ```
#### 완성된 main.cpp
```c
#include <iostream>
#include "stack.h"

int main()
{   
    // 내부적으로 default size의 s1이 만들어짐
    // stack s1(100)
    Stack s1;

    // Stack s2 = 10 x
    Stack s2(10);

    // 복사생성자는 동작하지 않도록 구현한다.
    //    Stack s3(s2);
    s1.push(100);
    s1.push(200);
    s1.push(300);

    while( !s1.isEmpty()){
        std::cout<< "s1 pop(): " << s1.pop() << std::endl;
    }
    return 0 ;

}
```

#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c queue.cpp
g++ -o queue queue.o
./queue
```
#### 샐행결과
```c
s1 pop(): 300
s1 pop(): 200
s1 pop(): 100
```
