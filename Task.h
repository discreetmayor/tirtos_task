/*
 * Task.h
 *
 *  Created on: Nov 17, 2018
 *      Author: mh
 */

#ifndef PHOSPHORBOARD_TASKS_TASK_H_
#define PHOSPHORBOARD_TASKS_TASK_H_

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>

extern "C" {
  void abstractTaskFxn(UArg arg0, UArg arg1);
}

class Task {
public:
    Task() {};
    virtual ~Task() {};
    virtual void run(UArg arg) = 0;
    void create(int priority, int stackSize);
    void create(int priority, int stackSize, UArg arg);
};

#endif /* PHOSPHORBOARD_TASKS_TASK_H_ */
