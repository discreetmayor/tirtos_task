/*
 * Task.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: discreetmayor
 */

#include <Task.h>

void Task::create(int priority, int stackSize) {
    create(priority, stackSize, NULL);
}

void Task::create(int priority, int stackSize, UArg arg) {
    Task_Params taskParams;
    Task_Params_init(&taskParams);
    taskParams.priority = priority;
    taskParams.stackSize = stackSize;
    taskParams.arg0 = (UArg)this;
    taskParams.arg1 = arg;
    Task_create((Task_FuncPtr)abstractTaskFxn, &taskParams, NULL);
}

extern "C" {
    void abstractTaskFxn(UArg arg0, UArg arg1) {
        Task *task = reinterpret_cast<Task*>(arg0);
        if(task) {
            task->run(arg1);
        }
    }
}
