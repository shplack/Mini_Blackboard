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