#include "../s21_string_tests.h"

Suite *suite_strncpy() {
  Suite *s = suite_create("s21_strncpy");

  TCase *tc_core = tcase_create("");
  suite_add_tcase(s, tc_core);

  return s;
}