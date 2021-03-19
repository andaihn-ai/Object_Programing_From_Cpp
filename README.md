# Object_Programing_From_Cpp
## type casting
  - static_cast <type> (expression);
  - reinterpret_cast<type> (expression);
  - const_cast<type> (expression);
  - dynamic_cast<type> (expression);

## static_cast
  - 가장많이 사용됩니다.
  - 컴파일 시간에 타입이 호환이 되는지 체크 합니다.

## reinterpret_cast
  - 컴파일때 에러가 나면 강제형변환을 할 때 사용합니다.

## const_cast
  - 상수객체의 const 속성을 없앨때 사용합니다.

## dynamic_cast
  - RTTI 에서사용합니다.
  - 원래의 파생(자식) 클래스 타입으로 바꿀때 사용합니다.

## static_cast 예제 
### score.cpp
  - 평균값을 구하는 부분에서 int형sum을 3으로 나누기 위해 double로 형변환을 합니다.
```c
    average = static_cast<double> (sum) / 3;

```
### 완성된 score.cpp
```c
#include <stdio.h>

int main(void)
{
    int kor, eng, mat;
    scanf("%d %d %d", &kor, &eng, &mat);
    
    int sum;
    double average;
    sum = kor + eng + mat;
    average = static_cast<double> (sum) / 3;

    printf("sum : %d\tarverate: %.2f\n", sum, average);

    return 0;
}
```


## reinterpret_cast 예제 
### pointer.cpp
  - static_cast는 에러를 뱉습니다.
  - 컴파일 시간에 타입이 호환이 되지 않습니다.
  - 강제 형 변환을 시도합니다.
```c
   p = reinterpret_cast<char *>(&a);
```
### 완성된 pointer.cpp
```c
#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    char * p;

    p = reinterpret_cast<char *>(&a);

    printf(" *p : 0x%x\n",*p);
    
    return 0 ;

}
```

## const_cast 예제
### const_cast.cpp
  - const 속성을 없애고 싶을떄 사용합니다.
  - const T타입의 포인터를 T타입 포인터로 바꾸고 싶을때, const T타입의 레퍼런스를 T타입의 레퍼런스로 바꾸고 싶을때 사용합니다.
```c
#include <iostream>

void f(int *p)
{
    //* p = 100;
}

int main()
{
    const int i = 0;
    
    //f((int * )&i);
    f( const_cast<int *>(&i) );
    std::cout << "i : " << i << std::endl;
    return 0;
}

```
## dynamic_cast 예제
### main.cpp
  - 부모 클래스 타입의 포인터가 자식클래스의 객체를 가리킬때, 부모 클래스 타입의 레퍼런스가 자식 클래스 타입의 객체를 가리킬때 사용합니다.
  - 원래의 파생(자식) 클래스 타입으로 바꿀때 사용합니다.
```c
void printArea(const Shape * ps)
{
    if (typeid(*ps) == typeid(Rectangle))      
    { 
        std::cout << "Rectangle";
        //Rectangle *pRec = (Rectangle * )ps;
        Rectangle * pRec = dynamic_cast<const Rectangle * >(ps)
        //
    }
    else if (typeid(*ps) == typeid(Circle))
    { 
        std::cout << "Circle";
        //Circle * pCir = (Circle)ps;
        Circle * pCir = dynamic_cast<const Circle * >(ps);
        //
    }
    else{;}

    std::cout <<" area : "<< ps->area() <<std::endl;
}

```
