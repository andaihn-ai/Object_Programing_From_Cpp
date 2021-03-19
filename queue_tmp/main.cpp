#include <iostream>
#include "queue.h"

int main ()
{
  
    Queue<int> q1;
    Queue<int> q2(10);
    
    q1.push(100);
    q1.push(200);
    q1.push(300);

    while( !q1.isEmpty()){
        std::cout << "q1 pop() : " << q1.pop() << std::endl;    
    }

    
    return 0;       
}