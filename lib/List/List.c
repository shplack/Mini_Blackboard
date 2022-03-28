#include "List.h"

static ListElement *initNodeWithData(void * const data) {
    ListElement *elem = malloc(sizeof(ListElement));
    elem->data = data;
    return elem;
}

bool insert(List * list, void * const data) {
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

bool insertAt(List * list, void * const data, unsigned long index) {
    if (list == NULL)
        return false;

    if (index >= list->size || index <= list->size * -1)
        return false;

    ListElement *elem = initNodeWithData(data);

    ListElement *tmp = list->head;
    for (int i = 0; i < (index < 0) ? index*-1 - 1 : index; i++) {
        tmp = index < 0 ? tmp->prev : tmp->next;
    }


    return true;
}