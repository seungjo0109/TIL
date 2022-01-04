#ifndef SAMPLE_CLASS_H_
#define SAMPLE_CLASS_H_

#include <iostream>

class SampleClass{

public:
    SampleClass(int x, int y);
    SampleClass(const SampleClass& sc); // copy constructor, deep copy

    ~SampleClass();

    void Print(void);

private:

    int x;
    int y;

};

#endif //SAMPLE_CLASS_H_