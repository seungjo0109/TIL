#ifndef EXPLICIT_MUTABLE_H_
#define EXPLICIT_MUTABLE_H_

#include <string>
#include <iostream>

class ExplicitMutable 
{

public:

    explicit ExplicitMutable(const char* name) : name_(name) {};
    // ExplicitMutable(const char* name) : name_(name) {};
    ExplicitMutable(int data): data_(data) {};

    ~ExplicitMutable() {} ;

    void TestMutable(int x) const 
    {
        data_ = x;
        std::cout << "data: "<< data_ << std::endl;
    };

    const char* name_;
    mutable int data_;
    //int data_;            // compile error        
};

#endif // EXPLICIT_MUTABLE_H_