#include "Person.h"
#include <malloc.h>
#include <string.h>

#define MAX_INFO_SIZE 4096

char * personInfoStr(Person const * const person) {
    char *info = malloc(MAX_INFO_SIZE);
    unsigned long index = 0;

    char * fullName = getNameStr(person->name);

    char name_intro[] = "Name: ";
    strcpy(info, name_intro);
    index += strlen(name_intro);

    strcpy(info + index, "\n");
    index++;

    char email_intro[] = "Email: ";
    strcpy(info+index, email_intro);
    index += strlen(email_intro);

    strcpy(info + index, "\n");
    index++;

    char ph_nbr_intro[] = "Phone Number: ";
    strcpy(info + index, ph_nbr_intro);
    index += strlen(ph_nbr_intro);

    strcpy(info + index, "\n");

    char *info_done = malloc(strlen(info));
    strcpy(info_done, info);
    free(info);

    return info_done;
}