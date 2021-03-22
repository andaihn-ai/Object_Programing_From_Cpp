#ifndef ARRAY_H
#define ARRAY_H

// 상수 ARRAYSIZE 전역변수로 선언후 사용


class Array{

private:
    int *pArr_;
    int size_;
    // static 맴버변수
    static const int ARRAYSIZE;

public:
    //Array();

    //explicit 명시적인 형변환을 막는다(변환생성자 동작 x)       | implicit 묵시적인 형변환
    // int형이 array 형으로 바뀌지 않는다.

    explicit Array(int size = ARRAYSIZE);

    Array(const int * pArr, int size);
    Array(const Array & rhs/*, int size*/);
    ~Array();

    Array& operator=(const Array& rhs);
    
    //set 함수 대신 치환연산을 통해서 내용을 바꾼다. 
    bool operator==(const Array& rhs) const;

    
    //치환문에 왼쪽에도 쓸 수 있다.
    int& operator[](int index);
    // 상수 객체의 reference 에서 꺼내기 떄문에 const int & 이다.
    const int& operator[](int index) const;

    // get 함수
    int size() const;


};

#endif