#ifndef NAMESPACE_H_
#define NAMESPACE_H_

#include <iostream>
#include "namespace_anonymous.h"

namespace namespace1 {
    void foo(void);
    void call_only_in_this_file(void);
}

namespace namespace2 {
    void foo(void);
    void func(void);
}

#endif  //NAMESAPCE_H_