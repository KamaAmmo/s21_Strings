#include <stdlib.h>

#include "../s21_string_tests.h"

START_TEST(test_to_upper_1) {
  char example1[256] = "AABBccbD";
  char example2[256] = "AABBCCBD";
  char *test = s21_to_upper(example1);
  ck_assert_str_eq(test, example2);
  free(test);
}
END_TEST

START_TEST(test_to_upper_2) {
  char example1[256] = "1234df";
  char *test = s21_to_upper(example1);
  ck_assert_str_eq(test, "1234DF");
  free(test);
}
END_TEST

START_TEST(test_to_upper_3) {
  char example1[256] = "Ag1fF23r";
  char *test = s21_to_upper(example1);
  ck_assert_str_eq(test, "AG1FF23R");
  free(test);
}
END_TEST

Suite *suite_to_upper() {
  Suite *s = suite_create("s21_to_upper");

  TCase *tc_core = tcase_create("");

  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  suite_add_tcase(s, tc_core);

  return s;
}