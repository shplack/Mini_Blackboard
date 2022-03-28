#pragma once

#define MAX_NAME_CHAR 20

typedef struct person_name_t {
    char first[MAX_NAME_CHAR];
    char middle[MAX_NAME_CHAR];
    char last[MAX_NAME_CHAR];
} PersonName;

