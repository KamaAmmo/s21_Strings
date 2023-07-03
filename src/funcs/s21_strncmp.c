#include "../s21_string.h"

int s21_strncmp(
    const char *str1, const char *str2,
    size_t n) {  //отличие от memcmp: memcmp пофиг на /0, => strncmp is better
  int res = 0;
  const char *p1 = (const char *)str1;
  const char *p2 = (const char *)str2;
  for (int i = 0; (i < n) && p1[i] && p2[i] && !res; i++) res = p1[i] - p2[i];
  return res;
}
