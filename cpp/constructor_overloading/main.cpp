#include "constructor_overloading.h"

int main(){
    Date date = Date();
    Date date2(2022, 01, 01);

    date.ShowDate();
    date2.ShowDate();

    return 0;
}