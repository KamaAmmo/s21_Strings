#include <stdlib.h>

#include "../s21_string_tests.h"

START_TEST(test_insert_1) {
  char example1[256] = "//ddd///";
  char delim[256] = "123";
  size_t n = 2;
  char *test = s21_insert(example1, delim, n);
  ck_assert_str_eq(test, "//123ddd///");
  free(test);
}
END_TEST

START_TEST(test_insert_2) {
  char example1[256] = "ahg";
  char delim[2566] = "vvvvv";
  size_t n = 1;
  char *test = s21_insert(example1, delim, n);
  ck_assert_str_eq(test, "avvvvvhg");
  free(test);
}
END_TEST

Suite *suite_insert() {
  Suite *s = suite_create("s21_insert");

  TCase *tc_core = tcase_create("");

  tcase_add_test(tc_core, test_insert_1);
  tcase_add_test(tc_core, test_insert_2);
  suite_add_tcase(s, tc_core);

  return s;
}