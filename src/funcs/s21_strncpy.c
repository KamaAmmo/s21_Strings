#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *destination = (char *)dest;
  const char *source = (char *)src;
  for (s21_size_t i = 0; i < n; i++, destination++, source++) {
    if (!*destination || !*source) break;
    *destination = *source;
  }
  *destination = '\0';
  return dest;
}
