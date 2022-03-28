#pragma once

#include <stdbool.h>
#include <malloc.h>

typedef struct list_element_t {
    void * data;
    struct list_element_t * next;
    struct list_element_t * prev;
} ListElement;

typedef struct list_t {
    unsigned long size;
    ListElement * head;
    ListElement * tail;
} List;

