#include "../s21_string_tests.h"

START_TEST(test_memset_1) {
  char example1[256] = "/////ddd///dfg/";
  int c = 'f';
  size_t n = 14;
  ck_assert_uint_eq((unsigned long)memset(example1, c, n),
                    (unsigned long)s21_memset(example1, c, n));
}
END_TEST

START_TEST(test_memset_2) {
  char example1[256] = "/////d\011fg/";
  int c = '0';
  size_t n = 14;
  ck_assert_uint_eq((unsigned long)memset(example1, c, n),
                    (unsigned long)s21_memset(example1, c, n));
}
END_TEST

START_TEST(test_memset_3) {
  char example1[256] = "/////d\011fg/";
  int c = 'v';
  size_t n = 14;
  ck_assert_uint_eq((unsigned long)memset(example1, c, n),
                    (unsigned long)s21_memset(example1, c, n));
}
END_TEST

Suite *suite_memset() {
  Suite *s = suite_create("s21_memset");

  TCase *tc_core = tcase_create("t_case_memset");

  tcase_add_test(tc_core, test_memset_1);
  tcase_add_test(tc_core, test_memset_2);
  tcase_add_test(tc_core, test_memset_3);

  suite_add_tcase(s, tc_core);

  return s;
}