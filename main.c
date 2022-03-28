#include <stdio.h>
#include <string.h>

int main() {
    char he[] = "hello";
    printf("%lu", strcspn(he, "l"));
}
