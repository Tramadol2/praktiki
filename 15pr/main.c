#include "_stack.h"
#include "student.h"
#include <stdlib.h>
#include<string.h>

int main() {
    system("chcp 65001");

    struct Student* first = initstudent("Илья", "Кондоуров", "m", 17, 207, 5.0, 5.0, 5.0);
    struct Student* second = initstudent("Даня", "Пошушарв", "m", 11, 107, 5.0, 5.0, 2.2);
    struct Student* third = initstudent("Ваня", "Кондратьев", "m", 11, 207, 5.0, 5.0, 5.0);







    struct Stack* students = init(students);
    students->push(students, (void*)first);
    students->push(students, (void*)second);
    students->push(students, (void*)third);


            students->saveStudentsToFile(students,"students.txt");


    struct Stack *stack = init(stack);
    stack->load_students_from_file(stack,"students.txt");
    while (stack->size>0)
    {
        struct Student *penis = (struct student*)stack->pop(stack);
        if (penis->group == 207 && strchr(penis->pol,'m')) {
          penis->infoOutput(penis);
       }


    }
    return 0;
}


