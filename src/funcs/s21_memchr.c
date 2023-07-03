#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n){
    void *res = NULL;
    const unsigned char *ptr =(const unsigned char *)str;
    for (int i = 0; (i <= n) && !res; i++){
        if (ptr[i] == c) res = (void *)&ptr[i];
    }
    return res;
}