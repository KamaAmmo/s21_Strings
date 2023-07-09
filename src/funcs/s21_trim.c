#include <stdio.h>

#include "../s21_string.h"

// int check_end_src(const char *src, const char *trim_chars, size_t len1,
//                   size_t len2);
// int check_begin_src(const char *src, const char *trim_chars, size_t len2);

void check_begin_src(const char *src, const char *trim_chars, size_t len2,
                     int *c) {
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

void check_end_src(const char *src, const char *trim_chars, size_t len1,
                   size_t len2, int *c) {
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
  size_t len1 = s21_strlen(src);
  size_t len2 = s21_strlen(trim_chars);
  if (src) {
    tmp = malloc((len1) * sizeof(char));
    int cbegin = 0, cend = 0;
    check_begin_src(src, trim_chars, len2, &cbegin);
    check_end_src(src, trim_chars, len1, len2, &cend);
    int t = 0;
    for (int i = len2 * cbegin; i < len1 - (len2 * cend); i++) {
      tmp[t] = src[i];
      t++;
    }
  }
  return tmp;
}
