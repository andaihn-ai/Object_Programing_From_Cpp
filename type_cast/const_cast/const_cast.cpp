#include <iostream>

void f(int *p)
{
    //* p = 100;
}

int main()
{
    const int i = 0;
    
    //f((int * )&i);
    f( const_cast<int *>(&i) );
    std::cout << "i : " << i << std::endl;
    return 0;
}