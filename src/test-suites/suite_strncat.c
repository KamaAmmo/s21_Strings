#include "../s21_string_tests.h"

START_TEST(test_strncat_1) {
  char example1[256] = "sdf FFF UWEuw 0";
  char example2[256] = "";
  ck_assert_uint_eq(
      (unsigned long)strncat(example1, example2, s21_strlen(example1)),
      (unsigned long)s21_strncat(example1, example2, s21_strlen(example1)));
}
END_TEST

START_TEST(test_strncat_2) {
  char example1[256] = "\n\t";
  char example2[256] = "\0";
  ck_assert_uint_eq(
      (unsigned long)strncat(example1, example2, s21_strlen(example1)),
      (unsigned long)s21_strncat(example1, example2, s21_strlen(example1)));
}
END_TEST

START_TEST(test_strncat_3) {
  char example1[256] = "/0";
  char example2[256] = "\0";
  ck_assert_uint_eq(
      (unsigned long)strncat(example1, example2, s21_strlen(example1)),
      (unsigned long)s21_strncat(example1, example2, s21_strlen(example1)));
}
END_TEST

Suite *suite_strncat() {
  Suite *s = suite_create("s21_strncat");

  TCase *tc_core = tcase_create("t_case_strncat");
  tcase_add_test(tc_core, test_strncat_1);
  tcase_add_test(tc_core, test_strncat_2);
  tcase_add_test(tc_core, test_strncat_3);
  suite_add_tcase(s, tc_core);

  return s;
}