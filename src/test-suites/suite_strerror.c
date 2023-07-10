#include "../s21_string_tests.h"

START_TEST(test_strerror_1) {
  char *ex1 = strerror(0);
  char *ex2 = s21_strerror(0);
  ck_assert_uint_eq((unsigned long)*ex1, (unsigned long)*ex2);
}
END_TEST

START_TEST(test_strerror_2) {
  char *ex1 = strerror(7);
  char *ex2 = s21_strerror(7);
  ck_assert_uint_eq((unsigned long)*ex1, (unsigned long)*ex2);
}
END_TEST

START_TEST(test_strerror_3) {
  char *ex1 = strerror(108);
  char *ex2 = s21_strerror(108);
  ck_assert_uint_eq((unsigned long)*ex1, (unsigned long)*ex2);
}
END_TEST

START_TEST(test_strerror_4) {
  char *ex1 = strerror(-3);
  char *ex2 = s21_strerror(-3);
  ck_assert_uint_eq((unsigned long)*ex1, (unsigned long)*ex2);
}
END_TEST

Suite *suite_strerror() {
  Suite *s = suite_create("s21_strerror");

  TCase *tc_core = tcase_create("t_case_strerror");

  tcase_add_test(tc_core, test_strerror_1);
  tcase_add_test(tc_core, test_strerror_2);
  tcase_add_test(tc_core, test_strerror_3);
  tcase_add_test(tc_core, test_strerror_4);
  suite_add_tcase(s, tc_core);

  return s;
}