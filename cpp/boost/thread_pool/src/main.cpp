#include <iostream>

#include "task_module.h"

int main(int argc, char *argv[]){

    TaskModule *task_module = new TaskModule();

    std::cout<< "task_module test" << std::endl;

    while(1)
    {

        boost::this_thread::sleep(boost::posix_time::millisec(10000));
    }

    return 0;
}