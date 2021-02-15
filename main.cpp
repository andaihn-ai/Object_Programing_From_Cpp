#include "stack.h"
#include <iostream>

int main()
{
    Stack s1(10), s2(100);       /*생성자 호출*/

    s1.push(100);
    s1.push(200);
    s1.push(300);
    
    s2.push(900);
    s2.push(700);
    s2.push(800);
    
    
    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;

    std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
    std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
    std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;

    return 0;        /*소멸자 호출*/

}