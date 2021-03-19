# Object_Programing_From_Cpp
## inline
  - 함수는 반복되는 코드를 줄이고 C언어에 없는 연산자를 사용하기 위해 사용자 정의 연산을 만들어 사용합니다.
  - 함수 호출에는 오버헤드가 있는 단점이 있습니다. 
  - inline함수는 함수의 사이즈가 커지는 대신 속도에 대한 오버헤드가 줄어듭니다.
  - 함수 자체가 심플한경우 인라인 함수로 인스턴스(내부에서 작성된)코드를 작성하는 것을 권장합니다.

## C 언어에서의 inline 함수
  - inline 함수는 원래 C++ 함수입니다. 성능이 좋아서 C에서도 사용하게된 사례입니다.
  
### max.c
  - a와 b를 비교하여 더 큰값을 리턴하는 함수입니다.
  - 아래와 같이 간단한 함수의 경우 인자전달, 리턴값 반환 등에 오버헤드가 발생하기 때문에 인라인 함수를 활용하는 것이 좋습니다.
```c
int findMax(int a, int b)
{
    return (a>b) ? a:b;
}

int main(void)
{
    int a = 100;
    int b = 200;

    int max = findMax(a,b);
    printf("max: %d\n", max);

    return 0;
}

```
### max에 식을 전달
```c
int main(void)
{
    int a = 100;
    int b = 200;

    int max = (a>b) ? a : b;
    printf("max: %d\n", max);

    return 0;
}
```

### 매크로 함수 정의
  - 전처리문을 사용한 매크로 함수입니다. 전처리가 끝나면 MAX(a,b) 는 (a,b) ((a)>(b)? (a):(b) 로 치환됩니다.
  - 매크로 함수는 단순히 코드 치환이기 때문에 타입체크를 하지 않습니다. 인자에 식을 전달하는 경우 생각지 못한 side effects가 발생할 수 있습니다.
  - 매크로 함수 대신 인라인 함수를 사용하는 것을 권장합니다.
```c
#include <stdio.h>
#define Max(a,b) ((a)>(b)? (a):(b))

int main(void)
{
    int a = 100;
    int b = 200;

    int max = MAX(a,b);
    printf("max: %d\n", max);

    return 0;
}
```
### inline 함수
  - findMax 함수에 inline 함수라고 명시해 줍니다. 
  - 컴파일러가 필요시에 인라인 함수로 처리합니다.
  - inline 함수는 헤더파일에 들어갑니다. 아래와 같이 main과 같은 페이지에 사용될 경우 함수 선언을 위해 exturn 키워드를 명시해 줍니다. 
```c
exturn inline int findMax(int a, int b)
{
    return (a>b) ? a:b;
}

int main(void)
{
    int a = 100;
    int b = 200;

    int max = findMax(a,b);
    printf("max: %d\n", max);

    return 0;
}

```

## C++에서의 inline 함수 
### string.h
  - 헤더파일의 클래스 안에서 함수 정의를 하는 것은 inline 함수로 만들겠다는 뜻입니다.
```c
   ~String() { };
```
### string.cpp
  - 명시적으로 inline 함수를 정의합니다.
  - 함수의 본체 안에 루틴이 있거나, 또 다른 함수를 호출하는 등 복잠한 함수에 대해서는 inline 함수로 처리되지 않습니다.
  - 함수의 본체가 1~2 줄로 간단할 경우 효과적으로 inline 함수를 사용할수 있습니다. 
  - client 코드에서 사용되는 시점에 처리되어야 하기 때문에 cpp파일에 정의 해논 함수를 헤더파일로 옮깁니다.
  - 헤더파일로 옮긴 함수에 inline 키워드를 달아줍니다.
### 완성된 string.h

```c
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

class String{

friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
int len;

String(char * str, bool );

void set_str(const char * str);

public:
    char * str;
    String(const char * str = NULL);
    String(const String & rhs);
    ~String();

   
    String& operator=(const String & rhs);
    String& operator=(const char * str);
    
    String* operator&(const String & rhs);
    //const String * operator&() const;

    bool operator==(const String & rhs) const;

    const String operator+(const String& rhs) const;

    const char * c_str() const;
    int lenght() const;

    
};
inline std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str;

}
inline String::String(char * str, bool)
{
    this->str = str;
    this->len = strlen(str);

}

inline String::String(const char * str)
{
    this->set_str(str);
}
inline String::String(const String & rhs)
{
    this -> set_str(rhs.str);
}

inline String::~String()
{
    delete [] this->str;
}

inline bool String::operator==(const String & rhs) const
{
    return strcmp(this->str, rhs.str) == 0;
}

inline const char * String::c_str() const
{
    return this->str;
}

inline int String::lenght() const
{
    return this->len;
}


#endif
```
## string.inl 파일 만들기
  - 헤더파일에 작성한 inline 함수들을 inline 함수 파일을 만들어 옮겨 작성 합니다.
  - 헤더파일에는 #include "string.inl" 의 전처리문을 사용해 inline 함수 파일을 불러옵니다. 

  - inline 함수를 조건부 컴파일(사용할 때 와 안할 때) 하기 위해서 입니다. inline함수로 서 사용할 때에는 헤더파일에 include 해줍니다. 
### string.h 
  - inline 함수로써 사용할 때
  - ifdef구문을 통해 INLINE 상수가 정의되어 있으면 inline함수로 사용됩니다.
```c
    #ifdef INLINE
    #include "string.inl"
    #endif
```
### string.cpp
  - 일반 함수로 사용하기 위해는 cpp 파일에 함수를 불러옵니다.
  - cpp 파일에서 inline 키워드를 제거하기 위해 전처리 지시문을 통해 inline 키워드에 아무것도 정의하지 않습니다.
  - ifndef구문을 통해 INLINE 상수가 정의되어 있지 않으면 일반 함수로 사용됩니다.
```c
    #ifndef INLINE
    #define inline 
    #include "string.inl"
    #endif
```
### string.inl
```c
inline std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str;

}
inline String::String(char * str, bool)
{
    this->str = str;
    this->len = strlen(str);

}

inline String::String(const char * str)
{
    this->set_str(str);
}
inline String::String(const String & rhs)
{
    this -> set_str(rhs.str);
}

inline String::~String()
{
    delete [] this->str;
}



inline bool String::operator==(const String & rhs) const
{
    return strcmp(this->str, rhs.str) == 0;
}

inline const char * String::c_str() const
{
    return this->str;
}

inline int String::lenght() const
{
    return this->len;
}

```

## 컴파일 및 빌드
  - 일반함수로 사용
```c
g++ -c main.cpp 
g++ -c string.cpp 
g++ -o test main.o string.o
./test.exe
```
  - inline함수로 사용
```c
g++ -c main.cpp -DINLINE
g++ -c string.cpp -DINLINE
g++ -o test main.o string.o
./test.exe
```
## 실행결과
```c
s1 : wonderful tonight  17
s2 : just the way yor are       20
s3 : just the way yor are       20
s1 and s2 are not equal
s4 : wonderful tonight Billy Joel
```
