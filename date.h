#ifndef DATE_H
#define DATE_H

typedef struct{
    int year;
    int month;
    int day;
}Date;

void printDate(const Date &rd);

#endif 