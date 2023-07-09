#include <stdlib.h>

#include "../s21_string_tests.h"

START_TEST(test_to_lower_1) {
  char example1[256] = "AABBccbD";
  char example2[256] = "aabbccbd";
  char *test = s21_to_lower(example1);
  ck_assert_str_eq(test, example2);
  free(test);
}
END_TEST

START_TEST(test_to_lower_2) {
  char example1[256] = "1234Df";
  char *test = s21_to_lower(example1);
  ck_assert_str_eq(test, "1234df");
  free(test);
}
END_TEST

START_TEST(test_to_lower_3) {
  char example1[256] = "Ag1fF23r";
  char *test = s21_to_lower(example1);
  ck_assert_str_eq(test, "ag1ff23r");
  free(test);
}
END_TEST

Suite *suite_to_lower() {
  Suite *s = suite_create("s21_to_lower");

  TCase *tc_core = tcase_create("t_case_to_lower");
  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  suite_add_tcase(s, tc_core);

  return s;
}