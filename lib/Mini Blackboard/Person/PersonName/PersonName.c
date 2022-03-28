#include "PersonName.h"
#include <malloc.h>
#include <string.h>

PersonName newName(
        char const * const first,
        char const * const middle,
        char const * const last)
{
    PersonName name;
    strncpy(name.first, first, MAX_NAME_CHAR);
    strncpy(name.middle, middle, MAX_NAME_CHAR);
    strncpy(name.last, last, MAX_NAME_CHAR);

    return name;
}

char *getNameStr(PersonName const name) {
    unsigned long size = strlen(name.first) + strlen(name.middle) + strlen(name.last) + 2;
    char * fullName = malloc(size);

    strncpy(fullName,
            name.first,
            strlen(name.first));

    strncpy(fullName + strlen(name.first) + 1,
            name.middle,
            strlen(name.middle));

    strncpy(fullName + strlen(name.first) + strlen(name.middle) + 2,
            name.last,
            strlen(name.middle));

    return fullName;
}