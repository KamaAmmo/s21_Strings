#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  for (int i = 0; (i <= n) && !res; i++) {
    if (ptr[i] == c) res = (void *)&ptr[i];
  }
  return res;
}