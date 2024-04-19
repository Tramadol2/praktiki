#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void infoOutput(void* student) {
    struct Student* s = (struct Student*)student;
    printf("Фамилия: %s\n", s->surname);
    printf("Имя: %s\n", s->name);
    printf("Пол: %s\n", s->pol);
    printf("Возраст: %d\n", s->age);
    printf("Группа: %d\n", s->group);
    printf("Отметка по математике: %f\n", s->mathMark);
    printf("Отметка по физике: %f\n", s->physicsMark);
    printf("Отметка по химии: %f\n\n", s->chemistryMark);
}

struct Student* initstudent(char* surname, char* name, char* pol, int age, int group, float mathMark, float physickMark, float chemistryMark) {
    struct Student* result = malloc(sizeof(struct Student));
    result->surname = strdup(surname);
    result->name = strdup(name);
    result->pol = strdup(pol);
    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physickMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;

    return result;
}



