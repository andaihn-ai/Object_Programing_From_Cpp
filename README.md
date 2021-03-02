# Object_Programing_From_Cpp
C++을 통해 객체 지향 프로그래밍을 학습합니다.

## class타입의 자료를 인자로 전달
  - 오버헤드를 줄이기 위해 reference 사용
### date.h  
#### const 타입의 reference
```c
void printDate(const Date &rd);

```
### 완성된 date.h
```c
#ifndef DATE_H
#define DATE_H

typedef struct{
    int year;
    int month;
    int day;
}Date;

void printDate(const Date &rd);

#endif 
```
### date.cpp
```c
#include <iostream>
#include "date.h"
void printDate(const Date &rd)
{
    std::cout << "(" << rd.year << "/" << rd.month << "/" << rd.day << ")" << std::endl;    
}
```
### main.cpp
  ```c
#include <iostream>
#include "date.h"

int main(){

    Date today;
    today.year = 2021;
    today.month = 1;
    today.day = 3;

    Date birthday = {2005,8,2};

    printDate(today);

    return 0;
}

  ```
#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c date.cpp
g++ -o test date.o main.o
./queue
```
#### 샐행결과
```c
(2021/1/3)
