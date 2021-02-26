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