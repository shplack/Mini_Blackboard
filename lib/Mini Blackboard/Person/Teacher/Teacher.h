#pragma once

#include "../Person.h"
#include "Course/Course.h"

#define OFFICE_NBR_LEN 5

typedef struct teacher_t {
    Person const person;
    char const   office_nbr[OFFICE_NBR_LEN];
    List         courses;
} Teacher;
