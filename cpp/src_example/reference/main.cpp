#include <iostream>

int change_val(int &ref){
    ref = 10;

    return 0;
}

int& return_ref(int& a){
    a = 1;
    return a;
}

// Compile error, Dangling error
// int& return_ref_dangling(void){
//     int a = 1;

//     return a;
// }

int main(void){
    int a = 3;
    int& ref_a = a;             //define reference variable
    
    //int& ref_b;               // compile error
    //int& ref_c = 10;          // compile error
    
    int arr[3] = {1, 2, 3};
    //int& ref_arr[3] = arr;    // compile error
    int(&ref_arr)[3] = arr;     // ref_arr is arr refered to

    const int &ref_d = 10;
    int d = ref_d;

    ref_a = 5;
    std::cout << "a: "<< a << std::endl;
    std::cout << "ref_a: "<< ref_a << std::endl;

    change_val(ref_a);

    std::cout << "a: "<< a << std::endl;
    std::cout << "d: "<< d << std::endl;

    std::cout << "ref_arr: " << ref_arr[0] << ref_arr[1] << ref_arr[2] <<std::endl;


    return 0;
}