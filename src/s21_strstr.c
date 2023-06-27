#include "../s21_string.h"

//первое вхождение подстроки в строку

char *s21_strstr(const char *haystack, const char *needle) {
  char *search = S21_NULL;
  char *hay = (char*)haystack;
  for (; *hay != '\0'; hay++) {
    if (!search) {
      if (*hay == *needle) {
        search = hay;
        char* nd = (char*)needle;
        for (; *nd != '\0'; nd++, hay++) {
          if (*hay == '\0') {
            search = S21_NULL;
            break;
          }
          if (*hay != *nd)
              search = S21_NULL;
        }
      }
    }
  }
  return search;
}
