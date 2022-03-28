#include "List.h"

static ListElement *initNodeWithData(void * const data) {
    ListElement *elem = malloc(sizeof(ListElement));
    elem->data = data;
    return elem;
}

bool insert(List * const list, void * const data) {
    if (list == NULL)
        return false;

    ListElement *elem = initNodeWithData(data);

    if (list->size == 0) {
        list->head = elem;
        elem->next = elem;
        elem->prev = elem;
    } else {
        elem->prev = list->head->prev;
        elem->next = list->head;

        list->head->prev->next = elem;
        list->head->prev = elem;
    }

    list->size++;
    return true;
}

bool insertAt(List * const list, void * const data, unsigned long index) {
    if (list == NULL)
        return false;

    if (index >= list->size || index <= list->size * -1)
        return false;

    ListElement *elem = initNodeWithData(data);

    ListElement *tmp = list->head;
    for (int i = 0; i < (index < 0) ? index*-1 - 1 : index; i++)
        tmp = index < 0 ? tmp->prev : tmp->next;

    elem->next = tmp;
    elem->prev = tmp->prev;
    tmp->prev->next = elem;
    tmp->prev = elem;

    list->size++;

    return true;
}

void * get(List * const list, unsigned long const index) {
    if (list == NULL)
        return NULL;

    if (list->size == 0)
        return NULL;

    if (index >= list->size || index < (list->size * -1) + 1)
        return NULL;

    ListElement *tmp = list->head;
    for (int i = 0; i < (index < 0) ? index*-1 - 1 : index; i++)
        tmp = index < 0 ? tmp->prev : tmp->next;

    return tmp->data;
}

long long search(List * const list, void const * const data) {
    if (list == NULL)
        return -1;

    if (list->size == 0)
        return -1;

    unsigned long index = 0;
    for (ListElement const * tmp = list->head; tmp; tmp = tmp->next)
        if (data == tmp->data) return index;

    return -1;
}

long long search_mem(List * const list, void const * const data, unsigned long size) {
    if (list == NULL)
        return -1;

    if (list->size == 0)
        return -1;

    unsigned long index = 0;
    for (ListElement const * tmp = list->head; tmp; tmp = tmp->next) {
        bool found = true;

        for (unsigned long i = 0; i < size; i++) {
            if (*(char *) (tmp->data + i) != *(char *) (data + i)) {
                found = false;
                break;
            }
        }

        if (found)
            return index;

        index++;
    }

    return -1;
}

void push(List * const list, void * const data) {
    if (list == NULL)
        return;

    ListElement *elem = initNodeWithData(data);

    if (list->size == 0) {
        elem->next = elem;
        elem->prev = elem;
    } else {
        list->head->prev->next = elem;
        list->head->prev = elem;
        elem->next = list->head;
        elem->prev = list->head->prev;
    }

    list->head = elem;
    list->size++;
}

void * pop(List * const list) {
    if (list == NULL)
        return NULL;

    if (list->size == 0)
        return NULL;

    ListElement *tmp = list->head;

    void * const data = tmp->data;

    if (tmp->next)
        tmp->next->prev = tmp->prev;

    if (tmp->prev)
        tmp->prev->next = tmp->next;

    free(tmp);

    return data;
}

void enqueue(List * const list, void * const data) {
    if (list == NULL)
        return;

    ListElement *elem = initNodeWithData(data);

    if (list->size == 0) {
        elem->next = elem;
        elem->prev = elem;
    } else {
        elem->next = list->head;
        elem->prev = list->head->prev;
        list->head->prev->next = elem;
        list->head->prev = elem;
    }

    list->size++;
}

void * dequeue(List * const list) {
    return pop(list);
}