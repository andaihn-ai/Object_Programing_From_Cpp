#include <iostream>
#include <cstring>
#include <assert.h>
#include "string.h"


StringRep::StringRep(const char * str)
{
    if(str ){
        
        this->str = new char[strlen(str)+1];        // 공간할당
        assert(this->str );         
        strcpy(this->str, str);                     // this->str에 str 복사

        this->len = strlen(str);                    // 길이값 넣어줌
    }
    else{                                          // str이 null 이면
        this->str = new char[1];                    // 공간 1개 할당
        assert(this->str );         
        this->str[0] = '\0';                        // 할당한 공간에 널문자를 준다. 

        this->len = 0;                              // 문자열의 길이는 0
    }
}

StringRep::~StringRep()
{
    delete [] this->str;
}

std::ostream& operator<<(std::ostream & out, const String& rhs)     // 출력함수
{
    return out << rhs.c_str(); 
}

//1
String::String(const char * str)
{
    this->rep  = new StringRep(str);      //rep객체를 만들어줌
    this->rep->rc = 1;                    // 처음 만들어진 객체 counting
}

String::String(const String & rhs)          // 복사생성자
{
    // shallow copy
    // 참조개수 1개 증가.
    this->rep = rhs.rep;                    // 복사
    ++this->rep->rc;                        // 복사생성자가 생성됐기 때문에 rc값 1 증가
}

//1
String::~String()
{
    //레퍼런스 객체의 rc값이 없을때 소멸된다.
    --this->rep->rc;                // 다른포인터가 rc값을 가르키고 있을수도 있기 때문에 우선 rc값을 1감소 rc 값이 0이 된다는 말은 더이상 가르키는 포인터가 없는것
    
    if (this->rep->rc == 0)         // 참조하는 포인터가 없을떄 delete
        delete [] this->rep;
}

/*
    나를 참조하는 포인터가 몇개인지 확인

*/

String& String::operator=(const String & rhs)
{
    if(this != &rhs){               // 자기자신을 치환하는지 체크
        --this->rep->rc;            // 다른 객체(s3)를 가리키기 떄문에 1개 감소
        if (this->rep->rc == 0)     // 감소 시켰을때 rc 값이 0 이면 객체 삭제
            delete []   this->rep;

        // shallow copy
        this-> rep = rhs.rep;       // 다른 객체를 가리킴
        ++this->rep->rc;            // rc값 1증가
    }

    return * this;
}


bool String::operator==(const String & rhs) const           
{
    return strcmp(this->rep->str, rhs.rep->str) == 0;           // 문자열 내용 비교

}


const String String::operator+(const String& rhs) const
{
    char * buf =  new char[this->rep->len + rhs.rep->len +1];        // 임시로 더하기한 문자열을 저장하기 위한 공간을 만듭니다.
    assert(buf );                                               
    strcpy(buf, this->rep->str);                                // buf 에 this->rep->str을 넣어줍니다.
    strcat(buf, rhs.rep->str);                                  // strcat를 통해 buf 안의 this->rep->str에 rhs.rep->str를 붙여줍니다.  

    String result(buf);                                          // String 임시 객체를 하나 만들어 buf 를넣어줍니다
    delete [] buf;                                              // 삭제
    return result;
}

const char * String::c_str() const                              // get함수
{
    return this->rep->str;                                      // String 객체쪽의 str을 넘겨줍니다.
}

int String::lengh() const                                        // 길이 리턴 함수
{
    return this->rep->len;
}


