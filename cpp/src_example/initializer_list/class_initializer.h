#ifndef CLASS_INITIALIZER_H_
#define CLASS_INITIALIZER_H_

#include <iostream>

/*
    Initializer list를 사용하면 인스턴스 생성과 동시에 초기화
    Initializer list를 사용하는 것이 효율적이고,
    레퍼런스와 상수 사용이 가능함.
    레퍼런스와 상수를 사용하고자 할 경우, Initializer list를 사용해야 함
*/
class ClassInitializer{

public:

    ClassInitializer(int x, int y);
    ~ClassInitializer();

    void Print(void);

private:

    int x;
    int y;
    const int const_val;

};

#endif //CLASS_INITIALIZER_H_