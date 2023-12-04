#include <stdio.h>
#include <stdlib.h>
#include "PriorityScheduling.h"

// Example tasks
void task1() {
    printf("Executing Task 1\n");
    contextSwitch();
}

void task2() {
    printf("Executing Task 2\n");
    contextSwitch();
}

void task3() {
    printf("Executing Task 3\n");
    contextSwitch();
}

int main() {   
    // Initialize tasks
    initializeTasks();

    // Add example tasks
    addTask(2, 5, task1);
    addTask(1, 4, task2);
    addTask(3, 3, task3);

    // Schedule and execute tasks
    scheduleTasks();


    // Clean up memory
    cleanup();

    return 0;
}
