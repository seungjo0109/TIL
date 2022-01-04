#include "class_initializer.h"

int main(void)
{
    ClassInitializer ci1(1, 2);
    ClassInitializer ci2(ci1);

    ci1.Print();
    ci2.Print();

    return 0;
}