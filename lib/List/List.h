#pragma once

#include <stdbool.h>
#include <malloc.h>

typedef struct list_element_t {
    void                    * data;
    struct list_element_t   * next;
    struct list_element_t   * prev;
} ListElement;

typedef struct list_t {
    unsigned long size;
    ListElement * head;
} List;

bool insert(List * list, void * data);
bool insertAt(List * list, void * data, unsigned long index);
void * get(List * list, unsigned long index);
long long search(List * list, void const * data);
long long search_mem(List * list, void const * data, unsigned long size);
void push(List * list, void * data);
void * pop(List * list);
void enqueue(List * list, void * data);
void * dequeue(List * list);
bool isEmpty(List const * list);