#include "task_module.h"

TaskModule::TaskModule(){

    if(Initialize()){
        std::cout << "Initiallize is completed!" << std::endl << std::endl;
    }else{
        std::cout << "Initiallize is failed!" << std::endl << std::endl;
    }

    if(TaskSpawn()){
        std::cout << "TaskSpwan is completed!" << std::endl << std::endl;
    }else{
        std::cout << "TaskSpwan is failed!" << std::endl << std::endl;
    }

}

TaskModule::~TaskModule(){
    std::cout << "Call TaskModule destructor" << std::endl << std::endl;
    thread_task.join();
}

int TaskModule::Initialize(){
    std::cout << "Initiallize TaskModule" << std::endl << std::endl;

    return 1;
}

int TaskModule::TaskSpawn(){

    std::cout<<"Task thread for task_module test" << std::endl;
    thread_task = boost::thread(&TaskModule::Run, this);
    tid = thread_task.get_id();

    return 1;

}

void TaskModule::Run(){

    while(1){

        PrintStatus();

        boost::this_thread::sleep(boost::posix_time::millisec(500));
    }

}

void TaskModule::PrintStatus(){

    std::cout << "TCP thread " << tid << "is activated" << std::endl;

}