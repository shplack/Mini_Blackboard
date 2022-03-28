#pragma once

#include "../Person.h"

#define STUDENT_ID_LEN 10

typedef struct student_t {
    Person const person;
    char const id[STUDENT_ID_LEN];
    unsigned short class_year;
} Student;