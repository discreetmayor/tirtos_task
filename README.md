# Tirtos_Task
A very basic class to instanciate TIRTOS tasks.

__How to use__ 

1. Add a TI tirtos build (ie, tirtos_builds_CC1352R1_LAUNCHXL_release_ccs) as a build dependency

2. Create a task class that extends the base class and implements the "run" method:

```cpp
class MyTask : public Task {
	MyTask();
	//...
	void run(UArg arg);
}

void MyTask::run(UArg arg) {
	//do some TIRTOS stuff
}
```

3. Instanciate and create your task

```cpp
#define TASK_PRIORITY 1
#define TASK_STACK_SIZE 512

int main() {
	MyTask *tirtosTask = new MyTask();
	tirtosTask->create(TASK_PRIORITY, TASK_STACK_SIZE);
}
```

