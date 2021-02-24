# Object_Programing_From_Cpp
## Queue from C to Cpp
### queue.h / queue.c /  main.c 를 cpp로 변경합니다.
  #### main.cpp
  #### 확장자를 .c에서 .cpp로 바꿉니다.
  - C의 문법은 CPP문법에 전부 적용되지 않습니다. 현재 시점에서 C의 대부분의 문법은 CPP에 적용 됩니다.
  #### 데이터와 관련된 연산을 연결하기위해 맴버 맴버함수를 사용합니다.
  - initQueue(&q1,100) → q1.initQueue(100)
  - push(&q1, 300) → q1.push(300) 
  ##### 완성된 main.cpp 코드
  ```c
#include "queue.h"
#include <iostream>

int main ()
{
    /*생성자 호출*/

    Queue q1(100), q2(10);
   

    q1.push(100);
    q1.push(200);
    q1.push(300);

    q2.push(900);
    q2.push(800);
    q2.push(700);

    std::cout << "q1 1st pop() : " << q1.pop() << std::endl;
    std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;
    std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;

    std::cout << "q2 1st pop() : " << q2.pop() << std::endl;
    std::cout << "q2 2nd pop() : " << q2.pop() << std::endl;
    std::cout << "q2 3rd pop() : " << q2.pop() << std::endl;
 
    return 0;        /*소멸자 호출*/
}
  ```
  
  ### queue.h
  #### queue와 관련된 전역함수를 멤버함수로 작성합니다.
  데이터와 관련된 연산을 구조체 안에 넣어 묶습니다.
  - void push(Queue * pq, int data) {...} ---> void Queue::push(int data) {...}
 

##### 완성된 queue.h
 ```c
#ifndef QUEUE_H
#define QUEUE_H


class Queue 
{
private :
    int *pArr;
    int size;
    int front;
    int rear;

public :
    Queue(int size);        /*생성자 : constructor*/
    ~Queue();               /*소멸자 : destructor */

    push(int data);
    int pop();
};

#endif
 ```
### queue.cpp
#### 맴버함수를 정의할 때는 함수이름 앞에 구조체 이름::을 써줍니다.
  - Queue::push(int data)
  - ps->  →  this->  ex) s1.push(100)    s2.push(800)
  - 멤버함수는 반드시 객체를 통해서 호출해야 한다. 
  - 멤버함수는 자신을 호출한 객체를가리키는 this 라는 포인터를 가진다.
  - 구조체 안에 있는 맴버변수에 접근할 떄는 this-> 를 통해 접근
##### 완성된 queue.cpp
  ```c
#include <cassert>
#include "queue.h"

Queue::Queue(int size)
{
    /* this -> pArr = (int *)malloc(sizeof(int)* size); */
    this -> pArr = new int[size];
    assert(this->pArr);
    this ->size = size;
    this -> front = 0;
    this -> rear = 0;
}  
Queue::~Queue()
{
    /*free(pq -> pArr);*/
    delete [] this->pArr;
}

Queue::push(int data)
{
    assert(this->rear != this->size);
    this->pArr[this->rear] = data;
    ++this->rear;

}
Queue::pop(void)
{
    assert(this->front != this->rear);
    
    int tmp = this-> front;
    ++this->front;
    return this->pArr[tmp];
}

  ```


- typedef struct {...} Stack; ---> struct Stack {...};
 - int main(void) {...} ---> int main() {...}
  - CPP에서는 strcut 키워드 불필요
- namespace 가 적용된 header file사용. <stdio.h> --> <cstdio>
 
10. stream input / output
