#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;                 /*(0.0, 0.0) */
    /*Complex c2(3.0);*/        /*(3.0, 0.0) */
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);       /*(3.0, 4.0) */

    c1.real(3.0);
    c1.imag(4.0);

    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    
    Complex c4;
    c4.real(c1.real()+c2.real());
    c4.imag(c1.imag()+c2.imag());
    std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;


    if(c1.real() == c3.real() && c1.imag() == c3.imag()){
        std::cout << "c1 and c3 are equal" << std::endl;
    }else{
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    return 0 ;       /*소멸자 */


}