#include "../s21_string.h"
//Вычисляет длину начального сегмента str1, который полностью состоит из
//символов, не входящих в str2.
size_t s21_strcspn(const char *str1, const char *str2) {
  size_t len = 0;
  size_t is_include = 0;
  while (*str1) {
    char *ptr = (char *)str2;
    while (*ptr) {
      if (*str1 == *ptr) is_include = 1;
      ptr++;
    }
    if (!is_include) len++;
    str1++;
  }
  return len;
}
