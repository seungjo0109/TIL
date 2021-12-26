#ifndef TASK_BASE_H_
#define TASK_BASE_H_

#include <iostream>

class TaskBase{

public:

    TaskBase();
    virtual ~TaskBase();

protected:

    virtual int Initialize(void) = 0;
    virtual int TaskSpawn(void) = 0;
    virtual void Run(void) = 0;
    virtual void PrintStatus(void) = 0;

private:

};


#endif  //TASK_BASE_H_