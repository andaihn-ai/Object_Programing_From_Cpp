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