#include "../s21_string_tests.h"

START_TEST(test_strncpy_1) {
  char example1[256] = "0";
  char example2[256] = "";
  s21_size_t n = 12;
  ck_assert_str_eq(strncpy(example1, example2, n),
                   s21_strncpy(example1, example2, n));
}
END_TEST

START_TEST(test_strncpy_2) {
  char example1[256] = "0";
  char example2[256] = "1111111111111";
  s21_size_t n = 12;
  ck_assert_str_eq(strncpy(example1, example2, n),
                   s21_strncpy(example1, example2, n));
}
END_TEST

START_TEST(test_strncpy_3) {
  char example1[256] = "\010";
  char example2[256] = "\01111111111111";
  s21_size_t n = 312;
  ck_assert_str_eq(strncpy(example1, example2, n),
                   s21_strncpy(example1, example2, n));
}
END_TEST

START_TEST(test_strncpy_4) {
  char example1[256] =
      "\010ao\n jh\\ri\nsnkenbakmb\0aerbkameblmaelmbrakbmaelbm\0";
  char example2[256] = "\011aas\t\n\\dgdb";
  s21_size_t n = 312;
  ck_assert_str_eq(strncpy(example1, example2, n),
                   s21_strncpy(example1, example2, n));
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