#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *tmp = S21_NULL;
  if (str) {
    s21_size_t len = strlen(str);
    tmp = malloc((len + 1) * sizeof(char));
    for (int i = 0; i != len; i++) {
      if (str[i] > 'A' && str[i] < 'Z') tmp[i] = str[i] + ('a' - 'A');
    }
  }
  return (void *)tmp;
}
