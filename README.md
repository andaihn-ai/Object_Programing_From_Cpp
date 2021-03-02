# Object_Programing_From_Cpp
## String
String클래스는 포인터를 맴버 변수로 가진다.

### string.h
  - 문자열이 들어가기위해 char형 str 포인터 사용
  - 길이정보를 저장하는 int 형 len 번수 사용
#### 생성자 정의
```c

    String();
    String(const char * str);
    String(const String & rhs);
    ~String();
    
```
#### get/set 함수 정의
  - str값을 리턴하는 get함수는 주소값을 넘기기 때문에 const이다.
  - get 함수와 length 함수는 lead only 이기 때문에 상수 객체이다.
  - set은 정의하지 않는다. 
  - set함수 대신 치환을 통해 바꾼다. 
```c

    const char * c_str() const;
    int length() const;
    
```
#### 치환 연산 정의

```c

    String& operator=(const char * str);

```
#### 오버로딩 치환 연산자 정의
  - 임시객체를 생성하지 않기 위해 생성
```c

    String* operator&(const String & rhs);

```
#### 비교 연산 정의
```c

    bool operator==(const String & rhs) const;

```
#### 반복되는 함수 정의
  - 다른 맴버함수를 구현하기 위해서 존재하는 맴버함수
  - helper function
```c

    void set_str(const char * str);

```
#### default 인자
```c
    String(const char * str = NULL);
```
#### 더하기 연산자 정의
  - 반환타입은 const String 타입
  - 함수이름은 String클래스 안의 operator+
  - 인자는 String타입을 reference로 받아온다
  - 내용이 바뀌지 않기 때문에 const 맴버함수
```c
    const String operator+(const String& rhs) const;
```
#### 출력하는 함수정의
  - class선언
  - 전역함수로 연산자중복
```c
    class String;
    std::ostream& operator<<(std::ostream& out, const String& rhs);
```
#### 힙상에 있는 문자열을 가리키는 함수정의
  - 더하기 맴버함수
  - String(const char * str = NULL); 와 구별하기 위해서(오버로딩 충돌) 의미없는 인자인 bool 인자를 두 번째 인자로 받는다.
```c
    void set_str(const char * str, bool);
```
#### 완성된 string.h
```c
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

class String{

friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
char * str;
int len;

String(char * str, bool );

void set_str(const char * str);

public:

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

#endif
```
### string.cpp
#### 생성자 구현
```c

    String::String()
    {
        this->str = new char[1];
        assert(this->str );
        this->str[0] = "\0";

        this->len = 0;
    }
    
    String::String(const char* str, bool b)
    {
        this->str = (char *)str;
        this->len = strlen(str);
    }
    String::String(const char * str)
    {
        this->set_str(str);
    }
    String::String(const String & rhs)
    {
        this->str = new char[strlen(rhs.str)+1];
        assert(this->str );
        strcpy(this->str, rhs.str);
        this->len = rhs.len;
    }

```
#### 치환 연산 구현
  - this->str에 공간할당 
  - this->str이 null이 아닌지 체크
  - daisy-chaining을 위해서 자기 자신 객체를 넘겨준다
  - 자기 자신을 치환할때 원본이 delete로 날라가는 문제를 해결하기 위해 주소값을 비교하여 같은 값이 아닌 경우 실행
```c
   
   String::String(const String & rhs)
    {
        if(this != rhs){   
            delete [] this->str;
            
            this->str = new char[strlen(rhs.str)+1];
            assert(this->str );
            strcpy(this->str, rhs.str);

            this->len = strlen(rhs.str);
        }
        return * this;
    }
    
```
#### 오버로딩 치환 연산자 구현
  - 임시객체를 생성하지 않기 위해 const char * str인자로 넘긴다.
```c

    String& String::operator=(const char * str)
    {
        delete [] this->str;
        this->str = new char[strlen(str)+1];
        assert(this->str );
        strcpy(this->str, str);

        this->len = strlen(str);

        return * this;

    }
    
```
#### 비교 연산 구현
  - 첫번째 문자의 주소값을 주어 \0 까지 비교한다.
  - strcmp 값이 0인지 체크
```c

    bool String::operator==(const String & rhs) const
    {
        return strcmp(this->str, rhs.str) == 0;
    }

```
#### 반복되는 코드를 없애기 위해 set_str함수 구현
  - this에 사용되기 위해 String클래스의 맴버함수로 만들어준다.
  - 생성자 함수의 반복되는 부분을 개선한다.
  - 치환 연산자 함수의 반복되는 부분을 개선한다.
```c
    void String::set_str(const char *str)
    {
        if(str ){

            this->str = new char[strlen(str)+1];
            assert(this->str );
            strcpy(this->str, str);

            this->len = strlen(str);
        }else{
            this->str = new char[1];
            assert(this->str );
            this->str[0] = "\0";

            this->len = 0;
        }
    }
    /******************생성자함수***********************/
    String::String()
    {
        this->set_str(NULL);
    }
    String::String(const char * str)
    {
        this->set_str(str);
    }

    String::String(const char * str)
    {
        this->set_str(str);
    }

    String::String(const String & rhs)
    {
        this -> set_str(rhs.str);
    }
    /******************치환연산자 함수***********************/
    String& String::operator=(const String & rhs)
    {
        if(this != & rhs)
        {
            delete [] this->str;
            this->set_str(rhs.str)
        }

        return * this;
    }

    String& String::operator=(const char * str)
    {
        delete [] this->str;

        this->set_str(str);

        return * this;

    }
```

#### 더하기 연산자 함수 구현

  - 문자열의 길이를 모르기 때문에 임시로 공간을 할당한다.
  - string타입의 result 객체를 만든다. 
  - 버퍼(임시공간)에 this-> 복사
  - 버퍼에 rhs.str을 더한다
  - result 객체에 버퍼를 넘겨준다
  - result를 반환한다.

```c
    const String String::operator+(const String& rhs) const
    {
        char *buf = new char[this->len + rhs.len + 1];
        assert(buf );
        strcpy(buf, this->str);
        strcat(buf, rhs.str);

        String result(buf, true);

        return result;
    }

```
#### 출력함수 구현
```c

    std::ostream& operator<<(std::ostream& out, const String& rhs)
    {
        return out << rhs.c_str();
    }
```
#### 힙상에 있는 문자열을 가리키는 함수구현
  - 더하기 맴버함수
  - String(const char * str = NULL); 와 구별하기 위해서(오버로딩 충돌) 의미없는 인자인 bool 인자를 두 번째 인자로 받는다.
```c
    void set_str(const char * str, bool);
```
#### 완성된 string.cpp
```c
#include <iostream>
#include <cstring>
#include <assert.h>
#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    return out << rhs.str;

}

// 반복되는 코드를 줄이는 함수
void String::set_str(const char * str)
{
    if(str ){
        
        this->str = new char[strlen(str)+1];
        assert(this->str );
        strcpy(this->str, str);

        this->len = strlen(str);
    }else{
        this->str = new char[1];
        assert(this->str );
        this->str[0] = '\0';

        this->len = 0;
    }
}

String::String(char * str, bool)
{
    this->str = str;
    this->len = strlen(str);

}

String::String(const char * str)
{
    this->set_str(str);
}

/*-------------------------------------------------------------*/
//self-assignment test
//자기 자신을 치환할때 원본이 delete로 날라가는 문제를 해결하기 위해
String::String(const String & rhs)
{
    this -> set_str(rhs.str);
}

String::~String()
{
    delete [] this->str;
}





String& String::operator=(const String & rhs)
{
    if(this != & rhs)
    {
        delete [] this->str;
        this->set_str(rhs.str);
    }
    
    return * this;
}

String& String::operator=(const char * str)
{
    delete [] this->str;

    this->set_str(str);

    return * this;

}

bool String::operator==(const String & rhs) const
{
    return strcmp(this->str, rhs.str) == 0;
}


const String String::operator+(const String& rhs) const
{
    char *buf = new char[this->len + rhs.len + 1];
    assert(buf );
    strcpy(buf, this->str);
    strcat(buf, rhs.str);

    String result(buf, true);
    
    return result;
}

const char * String::c_str() const
{
    return this->str;
}

int String::lenght() const
{
    return this->len;
}



```
### main.cpp
  - default생성자
  - 변환생성자
  - 복사생성자
```c

    String s1;
    String s2 = "just the way yor are";
    String s3 = s2;

```
#### 변환생성자 
  - s1.operator=("wonderful tonight");
  - 임시객체 생성 String tmp("wonderful tonight");
  - 임시객체 치환 s1.operator=(tmp);
  - 소멸자 호출 s1.~String();
  - 임시객체 만들어 지면서 생성자, 소멸자 호출 
```c
    s1 = s2 ;
    s1 = "wonderful tonight";
```
#### 완성된 main.cpp
```c
#include <iostream>
#include <cstring>
#include "string.h"

int main(){
    String s1;
    String s2 = "just the way yor are";
    String s3 = s2;

    s1 = s2 ;
    s1 = "wonderful tonight";

    std::cout << "s1 : " << s1.c_str() << "\t" << s1.lenght() << std::endl;
    std::cout << "s2 : " << s2.c_str() << "\t" << s2.lenght() << std::endl;
    std::cout << "s3 : " << s3.c_str() << "\t" << s3.lenght() << std::endl;

    if(s1 == s2){
        std::cout << "s1 and s2 are equal" << std::endl;
    }else{
        std::cout << "s1 and s2 are not equal" << std::endl;
    }

    String s4;
    s4 = s1 + " "+ "Billy Joel";
    std::cout << "s4 : " << s4 << std::endl;



    return 0 ;
    
}
```
#### 컴파일 및 빌드
```c
g++ -c main.cpp
g++ -c string.cpp
g++ -o test string.o main.o
./queue
```
#### 샐행결과
```c
s1 : wonderful tonight  17
s2 : just the way yor are       20
s3 : just the way yor are       20
s1 and s2 are not equal
s4 : wonderful tonight Billy Joel
