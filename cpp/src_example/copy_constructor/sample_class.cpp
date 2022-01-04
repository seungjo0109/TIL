#include "sample_class.h"

SampleClass::SampleClass(int x, int y)
: x(x), y(y)
{
    std::cout << "call constructor!" << std::endl;
}

SampleClass::SampleClass(const SampleClass& sc)
: x(sc.x), y(sc.y)
{
    std::cout << "call copy constructor!" << std::endl;
}

SampleClass::~SampleClass()
{
    std::cout<< "call destructor!" << std::endl;
}

void SampleClass::Print(void)
{
    std::cout<< "x: "<< x << ", y: "<< y << std::endl;
}

