#include <stdlib.h>

#include "../s21_string_tests.h"

START_TEST(test_trim_1) {
  char example1[256] = "//ddd///dfg//";
  char delim[256] = "/";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "ddd///dfg");
  free(test);
}
END_TEST

START_TEST(test_trim_2) {
  char example1[256] = "abcab//ddd///dfg//";
  char delim[256] = "abc";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "ab//ddd///dfg//");
  free(test);
}
END_TEST

START_TEST(test_trim_3) {
  char example1[256] = "abcab//ddd";
  char delim[256] = "ddddddd";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "abcab//ddd");
  free(test);
}
END_TEST

Suite *suite_trim() {
  Suite *s = suite_create("s21_trim");

  TCase *tc_core = tcase_create("");

  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_trim_3);
  suite_add_tcase(s, tc_core);

  return s;
}