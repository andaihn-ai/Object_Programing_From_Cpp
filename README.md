# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.
## 참조(Reference)
  - aliasing : 하나의 공간에 여러개의 이름을 붙여서 씀
  - call by reference
  - 연산자 중복을 사용하기 위해 존재
  - 변수 앞에 &를 붙이면 reference가 됨
  - 메모리공간을 차지하지 않기 떄문에 선언과 동시에 반드시 값을 초기화해 주어야 함  ex) int &r = a;
  - 포인터(call by value)와 다르게 일반 변수명(r)처럼 사용
  - 
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
