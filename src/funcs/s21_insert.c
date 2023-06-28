#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *tmp = NULL;
  size_t len2 = s21_strlen(src);
  size_t len1 = s21_strlen(str);
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
