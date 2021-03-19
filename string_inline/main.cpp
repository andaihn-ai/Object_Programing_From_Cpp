#include <iostream>
#include <cstring>
#include "string.h"

int main(){
    String s1;
    String s2 = "just the way yor are";
    String s3 = s2;

    s1 = s2 ;
    s1 = "wonderful tonight";

    std::cout << "s1 : " << s1.c_str() << "\t" << s1.lenght() << std::endl;
    std::cout << "s2 : " << s2.c_str() << "\t" << s2.lenght() << std::endl;
    std::cout << "s3 : " << s3.c_str() << "\t" << s3.lenght() << std::endl;

    if(s1 == s2){
        std::cout << "s1 and s2 are equal" << std::endl;
    }else{
        std::cout << "s1 and s2 are not equal" << std::endl;
    }

    String s4;
    s4 = s1 + " "+ "Billy Joel";
    std::cout << "s4 : " << s4 << std::endl;



    return 0 ;
    
}