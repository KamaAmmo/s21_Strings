#include "../s21_string_tests.h"

START_TEST(test_strncmp_1) {
  char example1[256] = "/////ddd///dfg/";
  char example2[256] = "/////ddd///dfg/";
  s21_size_t n = 14;
  ck_assert_uint_eq(strncmp(example1, example2, n),
                    strncmp(example1, example2, n));
}
END_TEST

START_TEST(test_strncmp_2) {
  char example1[256] = "/////ddd///dfg/";
  char example2[256] = "/////ddd///dfg/";
  s21_size_t n = 14;
  ck_assert_uint_eq(strncmp(example1, example2, n),
                    s21_strncmp(example1, example2, n));
}
END_TEST

START_TEST(test_strncmp_3) {
  char example1[256] = "dbdeb";
  char example2[256] = "dbdeb";
  s21_size_t n = 27;
  ck_assert_uint_eq(strncmp(example1, example2, n),
                    s21_strncmp(example1, example2, n));
}
END_TEST

START_TEST(test_strncmp_4) {
  char example1[256] = "\0sac";
  char example2[256] = "asc\0";
  s21_size_t n = 4;
  ck_assert_uint_eq(strncmp(example1, example2, n),
                    s21_strncmp(example1, example2, n));
}
END_TEST

START_TEST(test_strncmp_5) {
  char example1[256] = "\0sac";
  char example2[256] = "\0asc\0";
  s21_size_t n = 255;
  ck_assert_uint_eq(strncmp(example1, example2, n),
                    s21_strncmp(example1, example2, n));
}
END_TEST

Suite *suite_strncmp() {
  Suite *s = suite_create("s21_strncmp");

  TCase *tc_core = tcase_create("t_case_strncmp");

  tcase_add_test(tc_core, test_strncmp_1);
  tcase_add_test(tc_core, test_strncmp_2);
  tcase_add_test(tc_core, test_strncmp_3);
  tcase_add_test(tc_core, test_strncmp_4);
  tcase_add_test(tc_core, test_strncmp_5);
  suite_add_tcase(s, tc_core);

  return s;
}