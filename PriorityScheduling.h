#ifndef PRIORITY_SCHEDULING_H
#define PRIORITY_SCHEDULING_H

// Task structure
typedef struct {
    int id;
    int priority;
    void (*function)(void);
} Task;



void initializeTasks();
void addTask(int priority, void (*function)(void));
void removeTask(int taskId);
void scheduleTasks();
void cleanup();

#endif // PRIORITY_SCHEDULING_H

