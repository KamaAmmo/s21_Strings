#include "../s21_string_tests.h"

START_TEST(test_strlen_1) {
  char example[256] = "123456";
  ck_assert_int_eq(strlen(example), s21_strlen(example));
}
END_TEST

START_TEST(test_strlen_2) {
  char example[256] = "";
  ck_assert_int_eq(strlen(example), s21_strlen(example));
}
END_TEST

START_TEST(test_strlen_3) {
  char example[256] = "\n rrwg \t \09";
  ck_assert_int_eq(strlen(example), s21_strlen(example));
}
END_TEST

START_TEST(test_strlen_4) {
  char example[256] = "\0 \\koko[mi";
  ck_assert_int_eq(strlen(example), s21_strlen(example));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("s21_strlen");

  TCase *tc_core = tcase_create("t_case_strlen");

  tcase_add_test(tc_core, test_strlen_1);
  tcase_add_test(tc_core, test_strlen_2);
  tcase_add_test(tc_core, test_strlen_3);
  tcase_add_test(tc_core, test_strlen_4);

  suite_add_tcase(s, tc_core);

  return s;
}