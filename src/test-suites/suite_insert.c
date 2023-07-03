#include "../s21_string_tests.h"

Suite *suite_insert() {
  Suite *s = suite_create("s21_insert");

  TCase *tc_core = tcase_create("");
  suite_add_tcase(s, tc_core);

  return s;
}