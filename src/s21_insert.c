#include "s21_string.h"

// need test !!!

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *tmp = S21_NULL;
  s21_size_t len2 = strlen(src);
  s21_size_t len1 = strlen(str);
  if (src && str && (start_index <= len2)) {
    tmp = malloc((len1 + len2 + 1) * sizeof(char));
    for (int i = 0; i != len1 + len2; i++) {
      if (start_index > i)
        tmp[i] = src[i];
      else if ((i >= start_index) && (i < (start_index + len1)))
        tmp[i] = str[i - start_index];
      else
        tmp[i] = src[i - len1];
    }
  }
  return (void *)tmp;
}
