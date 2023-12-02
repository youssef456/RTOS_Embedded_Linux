#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "PriorityScheduling.h"

// Global array to store tasks
Task *tasks;
int numTasks;

// Global variable to simulate the context switch time
int contextSwitchTime = 1; // in milliseconds

// Time quantum for Round Robin scheduling
int timeQuantum = 2;  // in milliseconds 
  
// Initialize tasks
void initializeTasks() {
    tasks = NULL;
    numTasks = 0;
}

// Add a new task
void addTask(int priority, int burstTime, void (*function)(void)) {
    tasks = realloc(tasks, (numTasks + 1) * sizeof(Task));
    if (tasks == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    Task newTask = {numTasks + 1, priority, burstTime, burstTime, function};
    tasks[numTasks++] = newTask;
}

Task* removeTask(int taskId) {
    for (int i = 0; i < numTasks; ++i) {
        if (tasks[i].id == taskId) {
            // Remove task by shifting elements
            for (int j = i; j < numTasks - 1; ++j) {
                tasks[j] = tasks[j + 1];
            }

            // Decrease the number of tasks
            tasks = realloc(tasks, (numTasks - 1) * sizeof(Task));
            --numTasks;

            // Debugging: Print tasks array after removal
            printf("Debug: Tasks array after removal:\n");
            for (int k = 0; k < numTasks; ++k) {
                printf("Debug: Task ID: %d\n", tasks[k].id);
            }

            return tasks;  // Return the updated pointer
        }
    }

    fprintf(stderr, "Task with ID %d not found\n", taskId);
    return tasks;  // Return the original pointer if the task is not found
}



void scheduleTasks() {
    int currentTime = 0;
    int taskIndex = 0;

    while (numTasks > 0 && tasks != NULL) {
        // Ensure taskIndex is within bounds
        taskIndex = taskIndex % numTasks;

        Task *currentTask = &tasks[taskIndex];

        printf("Debug: Current Task ID: %d\n", currentTask->id);

        if (currentTask->remainingTime > 0) {
            int executionTime = (currentTask->remainingTime < timeQuantum) ? currentTask->remainingTime : timeQuantum;

            printf("Debug: Executing Task %d\n", currentTask->id);

            usleep(contextSwitchTime * 1000);

            currentTask->function();

            currentTask->remainingTime -= executionTime;
            currentTime += executionTime;

            // Check if taskIndex goes beyond the number of tasks after execution
            if (taskIndex >= numTasks) {
                taskIndex = 0;
            }
        } else {
            printf("Debug: Task %d completed. Remaining tasks: %d\n", currentTask->id, numTasks);

            tasks = removeTask(currentTask->id);

            // Check if taskIndex goes beyond the number of tasks after removal
            if (taskIndex >= numTasks) {
                taskIndex = 0;
            }
        }
    }
}





// Context Switching logic (a more realistic simulation)
void contextSwitch() {
    struct timespec sleepTime, remaining;

    sleepTime.tv_sec = 0;
    sleepTime.tv_nsec = contextSwitchTime * 1000000;  // Convert milliseconds to nanoseconds

    nanosleep(&sleepTime, &remaining);
}

// Cleanup function
void cleanup() {
    free(tasks);
}


