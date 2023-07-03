#include "../s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
    unsigned char *dest = (unsigned char *)str;
    for (int i = 0; i < n; i++) dest[i] = c;
    return dest;
}