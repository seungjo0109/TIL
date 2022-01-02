#include <iostream>

int main(void){
    int* p = new int;
    *p = 10;

    int arr_size = 5;
    int *arr = new int[arr_size];

    for (int i = 0; i<arr_size; i++){
        std::cin >> arr[i];
    }

    std::cout<< *p << std::endl;

    for (int i = 0; i<arr_size; i++){
        std::cout << arr[i] << std::endl;
    }

    delete p;
    delete[] arr;

    return 0;
}