#ifndef PRIORITY_SCHEDULING_H
#define PRIORITY_SCHEDULING_H

// Task structure
typedef struct {
    int id;
    int priority;
    int burstTime;  // Time required to complete the task
    int remainingTime;  // Time remaining to complete the task
    void (*function)(void);
} Task;



void initializeTasks();
void addTask(int priority, int burstTime, void (*function)(void));
Task* removeTask(int taskId);
void scheduleTasks();
void contextSwitch();
void cleanup();

#endif // PRIORITY_SCHEDULING_H

