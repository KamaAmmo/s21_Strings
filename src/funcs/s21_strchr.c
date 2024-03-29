#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  char *src = (char *)str;
  while (*src && !res) {
    if (*src == c) res = src;
    src++;
  }
  if (*src == c) res = src;
  return res;
}
