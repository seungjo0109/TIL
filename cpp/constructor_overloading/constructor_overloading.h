#ifndef CONSTRUCTOR_OVERLOADING_H_
#define CONSTRUCTOR_OVERLOADING_H_

#include <iostream>

class Date{
    
public:

    //Data() = default;     default constructor

    Date();
    Date(int year, int month, int day);

    void ShowDate();

private:
    int year;
    int month;
    int day;
};

#endif // CONSTRUCTOR_OVERLOADING_H_