#include <iostream>


void swap(int &ra, int &rb);

int main(){

    int a = 100;
    int b = 200;
    swap(a,b);
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
}
void swap(int &ra, int &rb){
    
    int temp = ra;
    ra = rb;
    rb = temp;
}