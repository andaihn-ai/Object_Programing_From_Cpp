#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;                
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);      
    Complex c4 = c3;

    Complex c5;
    c5  = c3;

    c1 = 3.0;           /*c1.operator=(3.0) or ::operator=(c1,3.0)*/

    c4 = c2 + c3;       /* c5.operator=(c2 +c3) --> c5.operator=(c2.operator+(c3))*/
                        /* ::.operator=(c5, c2 +c3) --> ::operator=(c5, ::operator+(c2, c3))*/

    c5 = c2 -c3;                                
    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;
    std::cout << "c5 : (" << c5.real() << ", " << c5.imag() << "i)" << std::endl;
    
 
    if(c3.real() == c5.real() && c3.imag() == c5.imag()){
        std::cout << "c3 and c5 are equal" << std::endl;
    }else{
        std::cout << "c3 and c5 are not equal" << std::endl;
    }

    return 0 ;       /*소멸자 */


}