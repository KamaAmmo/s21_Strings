#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  const char *p1 = (const char *)str1;
  const char *p2 = (const char *)str2;
  for (int i = 0; (i < n) && !res; i++) res = p1[i] - p2[i];
  return res;
}