# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.

#### 입력값이 없는 cpp 의 기본 골격
```c
#inclue <iostream>
int main()
{

  return 0;
}
```
#### 왼쪽 시프트 연산
  ##### 비트연산
  ##### 전역함수를 호출 하는 연산
  - operator+(a,b)
  ```c
  ::operator<<(std::cout, "hello,world");
  ```
  ##### 맴버함수를 호출하는 연산
  - a.operator+(b)
  ```c
  std::cout.operator<<(std::endl);
  ```
  - 연산자 중복
  ```c
  ::operator<<(std::cout,"hello, world.").operator << (std::endl);
  ```
  
##### 완성된 hello.cpp
```c
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
```
#### 컴파일 및 빌드
```c
g++ - c hello.cpp
g++ -o hello hello.o
./hello
```
#### 샐행결과
```c
hello, world
hello, world
hello, world.
```
