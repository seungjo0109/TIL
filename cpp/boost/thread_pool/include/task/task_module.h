#ifndef TASK_MODULE_H_
#define TASK_MODULE_H_

#include <boost/thread/thread.hpp>

#include "task_base.h"

class TaskModule : public TaskBase{

public:

    TaskModule();
    ~TaskModule() override;

private:

    int Initialize(void) override;
    int TaskSpawn(void) override;
    void Run(void) override;
    void PrintStatus(void) override;

    //task thread for task_module test
    boost::thread thread_task;
    boost::thread::id tid;

};


#endif // TASK_MODULE_H_