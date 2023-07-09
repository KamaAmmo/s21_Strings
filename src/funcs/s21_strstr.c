#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *search = s21_NULL;
  char *hay = (char *)haystack;
  if (*needle == '\0') search = (char *)haystack;
  for (; *hay != '\0'; hay++) {
    if (!search) {
      if (*hay == *needle) {
        search = hay;
        char *nd = (char *)needle;
        for (; *nd != '\0'; nd++, hay++) {
          if (*hay == '\0') {
            search = s21_NULL;
            break;
          }
          if (*hay != *nd) search = s21_NULL;
        }
      }
    }
  }
  return search;
}
