#pragma once

#include "PersonName/PersonName.h"
#include "Email/Email.h"

#define ITU_PHONE_LEN 15

typedef struct person_t {
    PersonName const name;
    Email const email;
    char phonenbr[ITU_PHONE_LEN];
} Person;