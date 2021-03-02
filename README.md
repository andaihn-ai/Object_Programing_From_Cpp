# Object_Programing_From_Cpp
## Stack from C to Cpp

### stack.h
#### array 클래스 상속
  - has-a 관계
  - stack클래스가 array클래스를 갖고있다.
  - 맴버변수로 클래스를 갖는 관계이다
 #### Array객체의 맴버변수 정의
```c
        Array arr_;  
```

#### 완성된 stack.h
```c
#ifndef STACK_H
#define STACK_H
#include "array.h"

class Stack{
private:
    static const int STACKSIZE;

    // int *pArr_;
    // int size_;
    Array arr_;      //상속 : has-a 관계 stack클래스가 array클래스를 갖고있다. 맴버변수로 클래스를 갖는 관계

    int tos_;

    Stack(const Stack& rhs);
    Stack& operator=(const Stack & rhs);

public:

    explicit Stack(int size = STACKSIZE);
    

    void push(int data);
    int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif

```

### stack.cpp
#### include "array.cpp
  - Array 클래스의 객체를 사용하기 위해 전처리한다
 ```c
     #include "array.h" 
 ```
 
 #### push /pop 함수 구현
   -  array클래스 타입의 객체의 대괄호 연산  사용
 ```c
     void Stack::push(int data)
    {   
        assert(!isFull());

        arr_[tos_] = data;
        ++tos_;
    }
    int Stack::pop()
    {
        assert(!isEmpty());

        --tos_;
        return arr_[tos_];
    }
    
    int Stack::pop()
    {
    assert(!isEmpty());

    --tos_;
    return arr_[tos_];
    }
 ```
  
 #### isFull/ isEmpty 함수 구현
   -  array클래스 안의 객체를 통해 size맴버함수 호출
 ```c
     
    bool Stack::isFull() const
    {
        return (tos_ == arr_.size());
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
g++ -c stack.cpp
g++ -o test stack.o main.o
./queue
```
#### 샐행결과
```c
s1 pop(): 300
s1 pop(): 200
s1 pop(): 100

