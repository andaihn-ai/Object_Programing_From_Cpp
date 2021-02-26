# Object_Programing_From_Cpp
## Queue from C to Cpp

### queue.h
#### static 맴버 변수 정의
```c
    static const int QUEUESIZE;
```
#### 맴버 변수 정의
```c

    int *pArr_;
    int size_;
    int front_;
    int rear_;

```
#### 생성자 정의
```c
    explicit Queue(int size = QUEUESIZE);
```
#### 소멸자 정의
```c
    ~Queue();
```

#### 맴버 함수 정의
```c
    void push(int data);
    int pop();

    bool isFull() const;
    bool isEmpty() const;
```
#### 완성된 queue.h
```c
#ifndef QUEUE_H
#define QUEUE_H

class Queue{
private:
    static const int QUEUESIZE;

    int *pArr_;
    int size_;
    int front_;
    int rear_;

    // client 코드에서 사용할 수 없다.
    Queue(const Queue& rhs);
    Queue& operator=(const Queue & rhs);

public:
    // Queue* operator&();
    // const Queue* operator&() const;

    explicit Queue(int size = QUEUESIZE);
    ~Queue();

    void push(int data);
    int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif
```
### qeueu.cpp

#### static 맴버 변수 구현
```c
    const int Queue::QUEUESIZE = 100;
```

#### 생성자 구현
  - 생성자 리스트 초기화로 맴버변수 초기화 
  - this-> 생략
```c
    Queue::Queue(int size)
    : pArr_(new int[size]), size_(size), front_(0),rear_(0)
    {
        assert(pArr_);      //this-> 생략
    }
```
#### 소멸자 구현
  - 할당한 메모리공간을 없애준다.
```c
    Queue::~Queue()
    {
    delete [] pArr_;
    }
```

#### push 함수 구현
```c
    void Queue::push(int data)
    {   
        assert( !isFull());
        pArr_[rear_] = data;
        ++rear_;
    }
```
#### pop함수 구현
  - 임시 변수 tmp를 사용해 함수를 동작시킨다.
```c
    int Queue::pop()
    {
        assert( !isEmpty());

        int tmp = front_;
        ++front_;
        return pArr_[tmp];

    }
```
#### isEmpty/ isFull  함수 
```c
    bool Queue::isEmpty() const
    {
        return (front_ == rear_);
    }
    bool Queue::isFull() const
    {
        return (rear_ == size_);
    }

```

#### 완성된 queue.cpp
```c
#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0),rear_(0)
{
    assert(pArr_);      //this-> 생략
}

Queue::~Queue()
{
    delete [] pArr_;
}

void Queue::push(int data)
{   
    assert( !isFull());
    pArr_[rear_] = data;
    ++rear_;
}
int Queue::pop()
{
    assert( !isEmpty());
    
    int tmp = front_;
    ++front_;
    return pArr_[tmp];
  
}

bool Queue::isEmpty() const
{
    return (front_ == rear_);
}
bool Queue::isFull() const
{
    return (rear_ == size_);
}

```
### main.cpp
#### 완성된 main.cpp
```c
#include <iostream>
#include "queue.h"

int main ()
{
  
    Queue q1;
    
    q1.push(100);
    q1.push(200);
    q1.push(300);

    while( !q1.isEmpty()){
        std::cout << "q1 pop() : " << q1.pop() << std::endl;    
    }

    
    return 0;       
}
```
