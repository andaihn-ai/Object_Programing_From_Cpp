#include <iostream>
#include <cstring>
#include <assert.h>
#include "string.h"

#ifndef INLINE
#define inline 
#include "string.inl"
#endif

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



/*-------------------------------------------------------------*/
//self-assignment test
//자기 자신을 치환할때 원본이 delete로 날라가는 문제를 해결하기 위해






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



const String String::operator+(const String& rhs) const
{
    char *buf = new char[this->len + rhs.len + 1];
    assert(buf );
    strcpy(buf, this->str);
    strcat(buf, rhs.str);

    String result(buf, true);
    
    return result;
}


