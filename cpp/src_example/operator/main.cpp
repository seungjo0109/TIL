#include "operator.h"

#include <iostream>

int main(void)
{
    Operator op(10);
    Operator op2(10);
    Operator op3(15);
    Operator op4(0);

    std::cout << "op == op2: " << (op == op2) << std::endl;
    std::cout << "op == op3: " << (op == op3) << std::endl;
    std::cout << "op + op3: " << (op+op3) << std::endl;
    op4 = op + op2;
    std::cout << "op4 = op + op2, op4.val_: " << op4.val_ << std::endl;


    return 0;

}