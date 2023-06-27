#include "../s21_string.h"

//разбивает строку на лексемы

char *s21_strtok(char *str, const char *delim) {
    static char *ptr;
    if ( *ptr == '\0' )
        return S21_NULL;
    if (str)
        for (ptr = str; s21_strchr(delim, *ptr); ++ptr)
            ;
    str = ptr;
    while (*ptr && ! s21_strchr(delim, *ptr))
        ++ptr;
    while (*ptr && s21_strchr(delim, *ptr) )
        *ptr++ = '\0';
    return str;
}
