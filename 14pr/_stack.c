#include "_stack.h"
#include <stdio.h>
#include "student.h"
#include <stdlib.h>



void load_students_from_file(struct Stack *stack, const char* filename);
void saveStudentsToFile(struct Stack *Stack,  const char *filename);


void push_stack(struct Stack* stack, void* elem) {
    struct Node* new_head = malloc(sizeof(struct Node));
    new_head->data = *((struct Student*)elem);
    new_head->next = stack->top;
    stack->top = new_head;
    stack->size += 1;
}

void* pop_stack(struct Stack* stack) {
    if (stack->size == 0) {
        return NULL;
    }
    struct Node* elem = stack->top;
    struct Student* result = malloc(sizeof(struct Student));
    *result = stack->top->data;
    stack->top = stack->top->next;
    stack->size -= 1;
    free(elem);
    return result;
}

struct Stack* init(struct Stack* result) {
    result = malloc(sizeof(struct Student));
    result->top = NULL;
    result->size = 0;
    result->push = push_stack;
    result->pop = pop_stack;
    result->load_students_from_file =  load_students_from_file;
    result->saveStudentsToFile =  saveStudentsToFile;
    return result;
}

void load_students_from_file(struct Stack *stack, const char* ) {

    FILE* fp = fopen("students.txt", "r");




    while(!feof(fp)){
        struct Student* _student = (struct Student*)initstudent("a", "a", "m", 0, 0, 0, 0, 0);

        fscanf(fp, "%s %s %s %d %d %f %f %f", _student->surname, _student->name, _student->pol
                , &_student->age, &_student->group, &_student->mathMark
                , &_student->physicsMark, &_student->chemistryMark);

       stack->push(stack,_student);
    }


    fclose(fp);
}


void saveStudentsToFile(struct Stack *Stack, const char *) {
    FILE *file = fopen("students.txt", "w");

    while (Stack->size > 0) {
        struct Student *student =(struct Student*)Stack->pop(Stack);
        fprintf(file, "%s %s %s %d %d %f %f %f", student->surname, student->name, student->pol
                , student->age, student->group, student->mathMark
                , student->physicsMark, student->chemistryMark);


    }

    fclose(file);
}