#include <stdlib.h>

#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *tmp = S21_NULL;
  if (str) {
    s21_size_t len = s21_strlen(str);
    tmp = malloc((len + 1) * sizeof(char));
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z')
        tmp[i] = str[i] + ('a' - 'A');
      else
        tmp[i] = str[i];
    }
    tmp[len] = '\0';
  }
  return (void *)tmp;
}
