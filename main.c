#include <stdio.h>
#include <stdlib.h>
#include "PriorityScheduling.h"

void task1() {
    printf("Executing Task 1\n");
}

void task2() {
    printf("Executing Task 2\n");
}

int main() {
    // Initialize tasks
    initializeTasks();

    // Add example tasks
    addTask(2, task1);
    addTask(1, task2);

    // Schedule and execute tasks
    scheduleTasks();

    // Clean up memory
    cleanup();

    return 0;
}
