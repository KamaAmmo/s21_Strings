#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  const char *temp_str1 = str1;
  const char *temp_str2 = str2;
  int find_flag = 0;
  while (*temp_str1 != '\0') {
    while (*temp_str2 != '\0') {
      if (*temp_str2 == *temp_str1) {
        result = (char *)temp_str1;
        find_flag = 1;
        break;
      }
      ++temp_str2;
    }
    if (find_flag) {
      break;
    }
    temp_str2 = str2;
    ++temp_str1;
  }
  return result;
}
