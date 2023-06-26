#include "../s21_string_tests.h"

Suite *suite_to_lower() {
  Suite *s = suite_create("s21_to_lower");

  TCase *tc_core = tcase_create("");
  suite_add_tcase(s, tc_core);

  return s;
}