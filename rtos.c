// main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "PriorityScheduling.h"
#include "main.h"

void printMenu() {
    printf("\n===== RTOS Simulator Menu =====\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. Run Simulation\n");
    printf("4. Exit\n");
}

void addExampleTasks() {
    addTask(2, 5, "taskFunction1");
    addTask(1, 4, "taskFunction2");
    addTask(3, 3, "taskFunction3");
}

int main() {
    initializeTasks();

    // Add some example tasks
    addExampleTasks();

    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int priority, burstTime;
                char functionName[50];
                printf("Enter task priority: ");
                scanf("%d", &priority);
                printf("Enter task burst time: ");
                scanf("%d", &burstTime);
                printf("Enter task function name: ");
                scanf("%s", functionName);

                // Find the function pointer based on the function name
                void (*taskFunction)(void) = NULL;
                if (strcmp(functionName, "taskFunction1") == 0) {
                    taskFunction = taskFunction1;
                } else if (strcmp(functionName, "taskFunction2") == 0) {
                    taskFunction = taskFunction2;
                } else if (strcmp(functionName, "taskFunction3") == 0) {
                    taskFunction = taskFunction3;
                } else {
                    printf("Invalid task function name.\n");
                    break;
                }

                addTask(priority, burstTime, taskFunction);
                printf("Task added successfully!\n");
                break;
            }
            case 2: {
                int taskId;
                printf("Enter task ID to remove: ");
                scanf("%d", &taskId);
                removeTask(taskId);
                printf("Task removed successfully!\n");
                break;
            }
            case 3:
                scheduleTasks();
                printf("Simulation completed!\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    cleanup();

    return 0;
}

// Example task functions
void taskFunction1() {
    printf("Executing Task 1\n");
    contextSwitch();
}

void taskFunction2() {
    printf("Executing Task 2\n");
    contextSwitch();
}

void taskFunction3() {
    printf("Executing Task 3\n");
    contextSwitch();
}

