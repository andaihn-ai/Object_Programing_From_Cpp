#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class StringRep{
friend class String;

private :

    char * str;
    int len;
    int rc;             //reference count
    
    StringRep(const char * str);                    // string 맴버함수에서만 사용할수 있다.
    ~StringRep();                                   // string 맴버함수에서만 사용할수 있다.

    StringRep(const StringRep& rhs);                // 복사생성자
    StringRep& operator=(const StringRep& rhs);     // 치환연산자


public :

};

class String{
friend std::ostream& operator<<(std::ostream & out, const String& rhs);

private:
    StringRep * rep;   

public:

    String(const char * str = NULL);
    String(const String & rhs);
    ~String();

    String& operator=(const String & rhs);

    bool operator==(const String & rhs) const;

    const String operator+(const String& rhs) const;

    const char * c_str() const;         // get 함수
    int lengh() const;                 // 길이 리턴 함수

    
};

#endif