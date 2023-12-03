#ifndef MAIN_H
#define MAIN_H

// Define a structure to hold task information
struct TaskInfo {
    const char* name;
    void (*function)(void);
};

// Declare taskInfoArray as extern
extern struct TaskInfo taskInfoArray[];

// Function prototypes
void taskFunction1();
void taskFunction2();
void taskFunction3();
void (*getTaskFunction(const char* taskName))(void);

// Map task names to their corresponding functions
struct TaskInfo taskInfoArray[] = {
    {"taskFunction1", taskFunction1},
    {"taskFunction2", taskFunction2},
    {"taskFunction3", taskFunction3},
    // Add more tasks as needed
};
#endif // MAIN_H
