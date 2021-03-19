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