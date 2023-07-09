#include "../s21_string_tests.h"

START_TEST(test_strtok_1) {
  char example1[256] = "/////ddd///dfg/";
  char example2[256] = "/////ddd///dfg/";
  char delim[256] = "/";
  ck_assert_str_eq(strtok(example1, delim), s21_strtok(example2, delim));
}
END_TEST

START_TEST(test_strtok_2) {
  char example1[256] = "\n\t";
  char example2[256] = "\n\t";
  char delim[256] = "n";
  ck_assert_str_eq(strtok(example1, delim), s21_strtok(example2, delim));
}
END_TEST

START_TEST(test_strtok_3) {
  char example1[256] = "/0";
  char example2[256] = "/0";
  char delim[256] = "";
  ck_assert_str_eq(strtok(example1, delim), s21_strtok(example2, delim));
}
END_TEST

Suite *suite_strtok() {
  Suite *s = suite_create("s21_strtok");

  TCase *tc_core = tcase_create("t_case_strtok");

  tcase_add_test(tc_core, test_strtok_1);
  tcase_add_test(tc_core, test_strtok_2);
  tcase_add_test(tc_core, test_strtok_3);

  suite_add_tcase(s, tc_core);

  return s;
}