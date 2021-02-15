#ifndef QUEUE_H
#define QUEUE_H


struct Queue 
{

    int *pArr;
    int size;
    int front;
    int rear;
 
    void initQueue(int * pArr,int size);
    void cleanUp();
    void push(int data);
    int pop();
};

#endif