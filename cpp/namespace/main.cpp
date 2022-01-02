#include "namespace.h"

int main(void){
    
    namespace1::foo();
    namespace2::foo();
    namespace2::func();

    namespace1::call_only_in_this_file();

    return 0;
}