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
      Task_Params_init(&params);
      params.arg0 = (UArg)this;
      params.arg1 = arg;
      params.stack = stack;
      params.stackSize = stackSize;
      params.priority = priority;
      Task_construct(&abstractTaskStruct, abstractTaskFxn, &params, NULL);
}

extern "C" {
    void abstractTaskFxn(UArg arg0, UArg arg1) {
        Task *task = reinterpret_cast<Task*>(arg0);
        if(task) {
            task->run(arg1);
        }
    }
}
