#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *tmp = s21_NULL;
  if (str) {
    s21_size_t len = s21_strlen(str);
    tmp = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z')
        tmp[i] = str[i] - ('a' - 'A');
      else
        tmp[i] = str[i];
    }
  }

  return (void *)tmp;
}