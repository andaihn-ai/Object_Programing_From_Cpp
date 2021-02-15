#include <cstdlib>
#include <cassert>
#include "queue.h"

void Queue::initQueue(Queue *pq,int size)
{
    this -> pArr = (int *)malloc(sizeof(int) * size);
    assert(this->pArr);
    this ->size = size;
    this -> front = 0;
    this -> rear = 0;
}  
void Queue::cleanUp()
{
    free(this -> pArr);
    
}
void Queue::push(int data)
{
    assert(this->rear != this->size);
    this->pArr[this->rear] = data;
    ++this->rear;

}
int Queue::pop()
{
    assert(this->front != this->rear);
    
    int tmp = this-> front;
    ++this->front;
    return this->pArr[tmp];
}
