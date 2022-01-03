#include "constructor_overloading.h"

Date::Date(){
    std::cout << "Date() constructor" << std::endl;
    year = 2022;
    month = 1;
    day = 2;
}

Date::Date(int year, int month, int day){
    std::cout << "Constructor with 3 args" << std::endl;
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::ShowDate(){
    std::cout << year <<  "." << month << "." << day << std::endl;
}