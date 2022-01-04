#include "class_initializer.h"

ClassInitializer::ClassInitializer(int x, int y)
: x(x), y(y), const_val(10) // intialize const variable
{

}

ClassInitializer::~ClassInitializer() {}

void ClassInitializer::Print(void)
{
    std::cout<< "x: "<<x<<", y: "<< y << ", const_val: "<<const_val<<std::endl;
}