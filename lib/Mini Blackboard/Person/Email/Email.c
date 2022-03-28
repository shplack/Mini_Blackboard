#include "Email.h"
#include <string.h>
#include <malloc.h>

Email newEmail(char const * const email)
{
    Email new_email;

    unsigned long atIndex = strcspn(email, "@");
    strncpy(new_email.alias, email, atIndex-1);

    char const * const domain = email + atIndex;
    unsigned long dotIndex = strcspn(domain, ".");
    strncpy(new_email.domain, domain, dotIndex-1);

    char const * const root = domain + dotIndex;
    strcpy(new_email.root, root);

    return new_email;
}

char const * emailToString(Email const email)
{
    unsigned long alias_size = strlen(email.alias);
    unsigned long domain_size = strlen(email.domain);
    unsigned long root_size = strlen(email.root);

    char * email_str = malloc(alias_size + domain_size + root_size);

    strcpy(email_str, email.alias);
    strcpy(email_str + alias_size, email.domain);
    strcpy(email_str + alias_size + domain_size, email.root);

    return email_str;
}