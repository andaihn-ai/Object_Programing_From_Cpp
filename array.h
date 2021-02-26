#ifndef ARRAY_H
#define ARRAY_H

class Array{

private:
    int *pArr_;
    int size_;
    static const int ARRAYSIZE;

public:
    
    explicit Array(int size = ARRAYSIZE);

    Array(const int * pArr, int size);
    Array(const Array & rhs/*, int size*/);
    ~Array();

    Array& operator=(const Array& rhs);
    
    bool operator==(const Array& rhs) const;

    
    int& operator[](int index);
    const int& operator[](int index) const;

    int size() const;


};

#endif