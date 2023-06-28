#include "../s21_string.h"

//находим первое вхождение любого символа из str2 в строке str1

char *s21_strpbrk(const char *str1, const char *str2) {
  char *search = NULL;
  for (; *str1 != '\0'; ++str1) {
    if (s21_strchr(str2, *str1)) {
      search = (char *)str1;
      break;
    }
  }
  return search;
}
