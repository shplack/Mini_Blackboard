#pragma once

#define MAX_EMAIL_CHARS 85

typedef struct email_t {
    char alias[MAX_EMAIL_CHARS];
    char domain[MAX_EMAIL_CHARS];
    char root[MAX_EMAIL_CHARS];
} Email;

Email newEmail(char const * email);
char * emailToString(Email email);