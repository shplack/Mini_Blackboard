#pragma once

#include "PersonName/PersonName.h"
#include "Email/Email.h"

#define ITU_PHONE_LEN 15 // some standard called ITU standard that dictates the length of a phone number

typedef struct person_t {
    PersonName const name;
    Email const email;
    char phonenbr[ITU_PHONE_LEN];
} Person;

char * personInfoStr(Person const * person);