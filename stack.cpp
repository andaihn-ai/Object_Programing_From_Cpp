#include "stack.h"
#include <cstdio>
#include <cstdlib>
#include <cassert>

 Stack::Stack(int)
{
    /* this->pArr = (int *)malloc(sizeof(int)*size); */
    this->pArr = new int[size];
    assert(this->pArr /*!= NULL*/);
    this->size = size;
    this->tos = 0;
}
 Stack::~Stack()
{
    /*free(this->pArr);*/
    delete [] this->pArr;
}
void Stack::push(int data)
{ 
    assert(this->tos != this->size);
    this->pArr[this->tos] = data;
    ++this->tos;
}

int Stack::pop(void)
{
    assert(this->tos != 0);
    --this->tos;
    return this->pArr[this->tos];
}


