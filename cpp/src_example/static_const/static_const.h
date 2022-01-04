#ifndef STATIC_CONST_H_
#define STATIC_CONST_H_

#include <iostream>

class StaticConst{

public:

    StaticConst();
    ~StaticConst();

    static void PrintStaticVal(void);

    void PrintConst(void) const;

private:

static int static_val;

int x;

};

#endif //STATIC_CONST_H_