#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
    char *destination = (char *)dest;
    char *source = ( char *)src;
    for(size_t i = 0; (i < n) && destination[i] && source[i]; i++) destination[i] = source[i];
}
