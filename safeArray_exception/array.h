#ifndef ARRAY_H
#define ARRAY_H

//array class 

class Array{
private :
    int * pArr_;
    int size_;
protected:

public:

    static const int ARRAYSIZE;
    explicit Array(int size = Array::ARRAYSIZE);
    Array(const int * pArr, int size);
    Array(const Array & rhs);
    ~Array();

    Array& operator=(const Array& rhs);
    bool operator==(const Array& rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    int size() const;

};

#endif