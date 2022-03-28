#pragma once

#include "List.h"

#define COURSE_NAME_LEN 50
#define COURSE_CODE_LEN 8

typedef struct course_t {
    char            name[COURSE_NAME_LEN];
    char            code[COURSE_CODE_LEN];
    unsigned char   points;
    unsigned char   period;
    unsigned short  year;
    List            students;
    List            teachers;
} Course;

char * courseInfoStr(Course course);