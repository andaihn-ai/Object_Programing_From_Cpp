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
