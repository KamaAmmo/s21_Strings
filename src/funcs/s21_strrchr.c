#include "../s21_string.h"

//находит последнее вхождение символа в строку

char *s21_strrchr(const char *str, int c) {
  char *res = (char *)str + s21_strlen(str);
  while (res != str && *res != c) res--;
  if (res == str && *res != c) res = NULL;
  return res;
}
