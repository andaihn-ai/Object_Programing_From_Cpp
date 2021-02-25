#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;                
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);      
    Complex c4 = c3;


    c2 = 4.0;

    c2 = c1 + c3;
    c2 = c1 - c3;          

    std::cout << "c1 : "<< c1 << std::endl;
    std::cout << "c2 : "<< c2 << std::endl;
    std::cout << "c3 : "<< c3 << std::endl;
    std::cout << "c4 : "<< c4 << std::endl;
    
   //std::cout << c1;  

    if(c1 == c3){
        std::cout << "c3 and c5 are equal" << std::endl;
    }else{
        std::cout << "c3 and c5 are not equal" << std::endl;
    }

    const Complex c5(3.0,4.0);
    double re = c5.real();
    return 0 ;     


}