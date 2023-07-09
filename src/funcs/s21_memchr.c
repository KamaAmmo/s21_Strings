#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  for (s21_size_t i = 0; (i < n) && !res; i++) {
    if (ptr[i] == c) res = &ptr[i];
  }
  return res;
}
