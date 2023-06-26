#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *tmp = S21_NULL;
  if (str) {
    s21_size_t len = strlen(str);
    tmp = malloc((len + 1) * sizeof(char));
    for (int i = 0; i != len; i++) {
      if (str[i] > 'a' && str[i] < 'z') tmp[i] = str[i] - ('a' - 'A');
    }
  }

  return (void *)tmp;
}

// int main() {
//   char *g = malloc(sizeof(char) * 5);
//   g = "";
//   g = s21_to_upper(g);
//   printf("%s\n", g);
//   printf("%s", g);

//   return 0;
// }