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


