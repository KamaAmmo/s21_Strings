#include "../s21_string.h"

//находит последнее вхождение символа в строку

char* s21_strrchr(const char *str, int c) {
    char *search = NULL;
    char* p = (char*)str;
    while (*p != '\0') {
      if (*p == c)
          search = p;
      p++;
    }
    return search;
}
