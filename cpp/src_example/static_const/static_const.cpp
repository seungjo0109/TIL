#include "static_const.h"

int StaticConst::static_val = 0;
void StaticConst::PrintStaticVal(void){
    std::cout << "static_val: " << static_val << std::endl;
}

StaticConst::StaticConst()
{
    static_val++;

    std::cout<<"static_val: "<< static_val << std::endl;
}

StaticConst::~StaticConst() {}

void StaticConst::PrintConst(void) const{

    //x = 10;

    std::cout << "call PrintConst" << std::endl;
}