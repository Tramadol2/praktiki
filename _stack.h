#ifndef STACK_H
#define STACK_H

#include "student.h"

struct Node {
    struct Student data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    unsigned long int size;
    void (*push)(struct Stack* stack, void* elem);
    void* (*pop)(struct Stack* stack);
    void (*saveStudentsToFile)(struct Stack *,  const char* );
    void (*load_students_from_file)(struct Stack*, const char* );
};

struct Stack* init(struct Stack* result);

#endif