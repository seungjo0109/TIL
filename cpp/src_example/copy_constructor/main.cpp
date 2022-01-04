#include "sample_class.h"

int main(void){
    
    SampleClass sc1(1, 2);
    SampleClass sc2(sc1);       //copy
    SampleClass sc3 = sc2;      //copy

    sc1.Print();
    sc2.Print();
    sc3.Print();

    return 0;
}