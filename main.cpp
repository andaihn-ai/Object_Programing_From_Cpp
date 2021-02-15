#include "queue.h"
#include <iostream>

int main ()
{
    Queue q1, q2;
    initQueue(&q1,100);
    initQueue(&q2,10);

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
    
    q1.cleanUp();
    q2.cleanUp();
    return 0;     
}