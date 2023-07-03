#include <stdio.h>

#include "../s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = NULL;
  size_t len1 = s21_strlen(src);
  size_t len2 = s21_strlen(trim_chars);
  if (src) {
    tmp = malloc((len1) * sizeof(char));
    int start = check_begin_src(src, trim_chars, len2);
    int end = check_end_src(src, trim_chars, len1, len2);
    int t = 0;
    if (start && end) {  // удалить в начале и в конце
      for (int i = len2; i < len1 - len2; i++) {
        tmp[t] = src[i];
        t++;
      }
    }
    if (start && !end) {  // удалить только в начале
      for (int i = len2; i < len1; i++) {
        tmp[t] = src[i];
        t++;
      }
    }
    if (!start && end) {  // удалить только в конце
      for (int i = 0; i < len1 - len2; i++) {
        tmp[t] = src[i];
        t++;
      }
    }
    if (!start && !end) {  // не удалять
      for (int i = 0; i < len1; i++) {
        tmp[t] = src[i];
        t++;
      }
    }
  }
  return (void *)tmp;
}

int check_begin_src(const char *src, const char *trim_chars, size_t len2) {
  int j = 0;
  while (src[j] == trim_chars[j] && src[j]) {
    j++;
  }
  return (j == len2) ? 1 : 0;
}

int check_end_src(const char *src, const char *trim_chars, size_t len1,
                  size_t len2) {
  int e = len1 - len2, e0 = 0;
  while (src[e] == trim_chars[e0] && src[e]) {
    e++;
    e0++;
  }
  return (e0 == len2) ? 1 : 0;
}