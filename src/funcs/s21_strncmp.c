#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *p1 = (const char *)str1;
  const char *p2 = (const char *)str2;
  int res = 0;
  for (int i = 0; (i < n) && !res; i++) {
    res = p1[i] - p2[i];
    if (!p1[i] || !p2[i]) break;
  }
  return res;
}
