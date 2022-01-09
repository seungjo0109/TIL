#include "explicit_mutable.h"

void TestExplicit(ExplicitMutable em)
{
    std::cout << "name: " << em.name_ << std::endl;
}

int main(void)
{
    ExplicitMutable em("name");
    ExplicitMutable tm(2);
    //ExplicitMutable em = "name"; // copy constructor, compile error

    TestExplicit(em);
    //TestExplicit("name2");  //implicit conversion, compile error

    tm.TestMutable(10);

    return 0;
}