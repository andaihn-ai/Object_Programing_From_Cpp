# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## 참조(Reference)
  - aliasing : 하나의 공간에 여러개의 이름을 붙여서 씀
  - call by reference
  - 연산자 중복을 사용하기 위해 존재한다.
  - 변수 앞에 &를 붙이면 reference가 된다.
  - 선언과 동시에 반드시 값을 초기화해 주어야 한다.  ex) int &r = a;
  - 포인터(call by value)와 다르게 일반 변수명(r)처럼 사용한다.
  - 복사생성자와 소멸자를 호출하지 않아 오버헤드를 줄일수 있다.

```c
int a = 100;
int &r = a;
r = 200;
std::cout<<a;    //200
```

### reference.h
```c
#ifndef REFERENCE_H
#define REFERENCE_H
class Reference
{
    private:
    public:
};
#endif
```

### main.cpp
```c
#include <iostream>


void swap(int &ra, int &rb);

int main(){

    int a = 100;
    int b = 200;
    swap(a,b);
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
}
void swap(int &ra, int &rb){
    
    int temp = ra;
    ra = rb;
    rb = temp;
}

```
#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c reference.cpp
g++ -o test reference.o main.o
./queue
```
#### 샐행결과
```c
a : 200
b :100
