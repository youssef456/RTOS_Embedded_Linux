#include <stdio.h>
#include <stdlib.h>
#include "PriorityScheduling.h"

// Global array to store tasks
Task *tasks;
int numTasks;
    
// Initialize tasks
void initializeTasks() {
    tasks = NULL;
    numTasks = 0;
}

// Add a new task
void addTask(int priority, void (*function)(void)) {
    tasks = realloc(tasks, (numTasks + 1) * sizeof(Task));
    if (tasks == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    Task newTask = {numTasks + 1, priority, function};
    tasks[numTasks++] = newTask;
}

// Remove a task by ID
void removeTask(int taskId) {
    for (int i = 0; i < numTasks; ++i) {
        if (tasks[i].id == taskId) {
            // Remove task by shifting elements
            for (int j = i; j < numTasks - 1; ++j) {
                tasks[j] = tasks[j + 1];
            }

            // Decrease the number of tasks
            tasks = realloc(tasks, (numTasks - 1) * sizeof(Task));
            --numTasks;
            return;
        }
    }

    fprintf(stderr, "Task with ID %d not found\n", taskId);
}

// Simple Priority Scheduling
void scheduleTasks() {
    while (numTasks > 0) {
        // Find the task with the highest priority
        int highestPriority = 0;
        int highestPriorityTaskIndex = -1;

        for (int j = 0; j < numTasks; ++j) {
            if (tasks[j].priority > highestPriority) {
                highestPriority = tasks[j].priority;
                highestPriorityTaskIndex = j;
            }
        }

        // Execute the task with the highest priority
        if (highestPriorityTaskIndex != -1) {
            tasks[highestPriorityTaskIndex].function();
            // Mark the task as executed by setting priority to a very low value
            tasks[highestPriorityTaskIndex].priority = -1;
        }
    }
}

// Cleanup function
void cleanup() {
    free(tasks);
}


