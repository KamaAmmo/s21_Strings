#include <stdlib.h>

#include "../s21_string.h"

void check_begin_src(const char *src, const char *trim_chars, int *c) {
  int j = 0;
  int i = 0;
  while (src[i] == trim_chars[j] && src[i]) {
    j++;
    i++;
    if (trim_chars[j] == 0) {
      j = 0;
      *c += 1;
    }
  }
}

void check_end_src(const char *src, const char *trim_chars, s21_size_t len1,
                   s21_size_t len2, int *c) {
  int e = len1 - 1, e0 = len2 - 1;

  while (src[e] == trim_chars[e0] && src[e]) {
    e--;
    e0--;
    if (trim_chars[e0] == 0) {
      e0 = len2 - 1;
      *c += 1;
    }
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = S21_NULL;
  s21_size_t len1 = s21_strlen(src);
  s21_size_t len2 = s21_strlen(trim_chars);
  int t = 0;
  if (src) {
    tmp = malloc((len1 + 1) * sizeof(char));
    int cbegin = 0, cend = 0;
    check_begin_src(src, trim_chars, &cbegin);
    check_end_src(src, trim_chars, len1, len2, &cend);

    for (s21_size_t i = len2 * cbegin; i < len1 - (len2 * cend); i++) {
      tmp[t] = src[i];
      t++;
    }
    tmp[t] = '\0';
  }
  return (void *)tmp;
}
