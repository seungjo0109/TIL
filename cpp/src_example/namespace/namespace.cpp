#include "namespace.h"

void namespace1::foo(void){
    std::cout << "namespace1::foo()" << std::endl;
}

void namespace1::call_only_in_this_file(void)
{   
    //only_in_this_file();    //compile error!
}

void namespace2::foo(void){
    std::cout << "namespace2::foo()" << std::endl;
}
void namespace2::func(void){
    foo();
    namespace1::foo();
}