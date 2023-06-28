#include "../s21_string.h"

size_t s21_strlen(const char *str) {
    if (!str)
        return 0;
    size_t i = 0;
    for (; *(str+i); i++) {
    }
    return i;
}
