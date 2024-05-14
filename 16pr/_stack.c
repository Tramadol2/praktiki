#include "_stack.h"
#include <stdio.h>
#include "student.h"
#include <stdlib.h>
#include <string.h>



void load_students_from_file(struct Stack *stack, const char* filename);
void saveStudentsToFile(struct Stack *Stack,  const char *filename);


void push_stack(struct Stack* stack, void* elem) {
    struct Node* new_head = malloc(sizeof(struct Node));
    if(new_head == NULL){
       perror("Ошибка при выделении памяти для Node");
        exit(1);
    }
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
    if(result == NULL){
        perror("Ошибка при выделении памяти для студента");
        exit(1);
    }
    *result = stack->top->data;
    stack->top = stack->top->next;
    stack->size -= 1;
    free(elem);
    return result;
}

struct Stack* init(struct Stack* result) {
    result = malloc(sizeof(struct Student));
    if(result == NULL){
        perror("Ошибка при создании стека");
        exit(1);
    }
    result->top = NULL;
    result->size = 0;
    result->push = push_stack;
    result->pop = pop_stack;
    result->load_students_from_file =  load_students_from_file;
    result->saveStudentsToFile =  saveStudentsToFile;
    return result;
}

void load_students_from_file(struct Stack *stack, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, fp) == 1) {
        stack->push(stack, &student);
    }
    fclose(fp);
}


void saveStudentsToFile(struct Stack *stack, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
       exit(EXIT_FAILURE);
    }

    while(!feof(file)) {
        int surnameSize;
        int nameSize;
        int sexSize;

        struct Student* _student = stack->pop(stack);
        fread(&surnameSize, sizeof(int), 1, file);
        _student->surname = calloc(surnameSize, sizeof(char));
        fread(_student->surname, sizeof(char), surnameSize, file);

        fread(&nameSize, sizeof(int), 1, file);
        _student->name = calloc(nameSize, sizeof(char));
        fread(_student->name, sizeof(char), nameSize, file);

        fread(&sexSize, sizeof(int), 1, file);
        _student->pol  = calloc(sexSize, sizeof(char));
        fread(_student->pol, sizeof(char), sexSize, file);

        fread(&_student->age, sizeof(int), 1, file);
        fread(&_student->group, sizeof(int), 1, file);
        fread(&_student->mathMark, sizeof(float), 1, file);
        fread(&_student->physicsMark, sizeof(float), 1, file);
        fread(&_student->chemistryMark, sizeof(float), 1, file);

        if(strlen(_student->surname) != 0){
            _student->infoOutput(_student);

            stack->push(stack,_student);
        }

        free(_student->surname);
        free(_student->name);
        free(_student->pol);
    }
}