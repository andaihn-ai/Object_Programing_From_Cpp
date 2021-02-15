#include <iostream>
#include "date.h"
void printDate(const Date &rd)
{
    std::cout << "(" << rd.year << "/" << rd.month << "/" << rd.day << ")" << std::endl;    
}