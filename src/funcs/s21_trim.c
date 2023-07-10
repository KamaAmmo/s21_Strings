#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

int char_in_trim(char a, const char *trim_chars, s21_size_t len_trim) {
  for (s21_size_t i = 0; i < len_trim; i++)
    if (trim_chars[i] == a) return 1;
  return 0;
}

void check_begin_src(const char *src, const char *trim_chars, int *c) {
  s21_size_t len_trim = s21_strlen(trim_chars);
  s21_size_t len_src = s21_strlen(src);
  for (s21_size_t t = 0; t < len_src; t++) {
    if (char_in_trim(src[t], trim_chars, len_trim))
      *c += 1;
    else
      break;
  }
}

void check_end_src(const char *src, const char *trim_chars, s21_size_t len1,
                   s21_size_t len2, int *c) {
  for (s21_size_t t = len1 - 1; t != 0; t--) {
    if (char_in_trim(src[t], trim_chars, len2))
      *c += 1;
    else
      break;
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
    if (len2 == 0) {
      check_begin_src(src, " ", &cbegin);
      check_end_src(src, " ", len1, 1, &cend);
    } else {
      check_begin_src(src, trim_chars, &cbegin);
      check_end_src(src, trim_chars, len1, len2, &cend);
    }

    for (s21_size_t i = cbegin; i < len1 - cend; i++) {
      tmp[t] = src[i];
      t++;
    }
    tmp[t] = '\0';
  }
  return (void *)tmp;
}
