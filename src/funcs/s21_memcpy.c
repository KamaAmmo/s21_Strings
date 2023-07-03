#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *destination = (char *)dest;
  char *source = (char *)src;
  for (int i = 0; (i < n); i++) destination[i] = source[i];
}
