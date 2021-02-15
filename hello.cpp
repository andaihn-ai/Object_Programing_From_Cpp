#include <iostream>

int main(){
    
    std::cout<<"hello, world"<< std::endl;
    
    /* 함수 이름 앞에 :: 붙이면 전역공간에 접근한다는 뜻이다. */

    /*std::cout << "hello, world";*/
    /*std::cout.operator<<("hello,world");*/        /*맴버함수 형태*/
    ::operator <<(std::cout, "hello,world");      /*전역함수 형태*/
    
    /*std::cout << std::endl;*/
    std::cout.operator<<(std::endl);
    /* operator<<(std::cout, std::endl); */
    

    /*오퍼레이터 연산자 중복*/
    ::operator<<(std::cout,"hello, world.").operator << (std::endl);



    return 0 ;

}