#include "../s21_string_tests.h"

START_TEST(test_strncpy_1) {
  char example1[256] = "0";
  char example2[256] = "0";
  char example3[256] = "";
  s21_size_t n = 12;
  ck_assert_str_eq(strncpy(example1, example3, n),
                   s21_strncpy(example2, example3, n));
}
END_TEST

START_TEST(test_strncpy_2) {
  char example1[256] = "\0";
  char example2[256] = "\0";
  char example3[256] = "1111111111111";
  s21_size_t n = 12;
  ck_assert_str_eq(strncpy(example1, example3, n),
                   s21_strncpy(example2, example3, n));
}
END_TEST

START_TEST(test_strncpy_3) {
  char example1[512] = "\010";
  char example2[512] = "\010";
  char example3[256] = "\01111111111111";
  s21_size_t n = 312;
  ck_assert_str_eq(strncpy(example1, example3, n),
                   s21_strncpy(example2, example3, n));
}
END_TEST

START_TEST(test_strncpy_4) {
  char example1[512] = "\010ao\n jh\\ri\n\0a\0";
  char example2[512] = "\010ao\n jh\\ri\n\0a\0";
  char example3[512] = "\011aas\t\n\\dg";
  s21_size_t n = 312;
  ck_assert_str_eq(strncpy(example1, example3, n),
                   s21_strncpy(example2, example3, n));
}
END_TEST

Suite *suite_strncpy() {
  Suite *s = suite_create("s21_strncpy");

  TCase *tc_core = tcase_create("t_case_strncpy");

  tcase_add_test(tc_core, test_strncpy_1);
  tcase_add_test(tc_core, test_strncpy_2);
  tcase_add_test(tc_core, test_strncpy_3);
  tcase_add_test(tc_core, test_strncpy_4);
  suite_add_tcase(s, tc_core);

  return s;
}