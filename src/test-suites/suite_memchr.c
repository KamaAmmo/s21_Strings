#include "../s21_string_tests.h"

START_TEST(test_memchr_1) {
  char example1[256] = "/////ddd///dfg/";
  int c = 'g';
  size_t n = 19;
  ck_assert_uint_eq((unsigned long)memchr(example1, c, n),
                    (unsigned long)s21_memchr(example1, c, n));
}
END_TEST

START_TEST(test_memchr_2) {
  char example1[256] = "/////ddd///dfg/";
  int c = 'g';
  size_t n = 0;
  ck_assert_uint_eq((unsigned long)memchr(example1, c, n),
                    (unsigned long)s21_memchr(example1, c, n));
}
END_TEST

START_TEST(test_memchr_3) {
  char example1[256] = "sssddvs\0twgfwg";
  int c = 'g';
  size_t n = 16;
  ck_assert_uint_eq((unsigned long)memchr(example1, c, n),
                    (unsigned long)s21_memchr(example1, c, n));
}
END_TEST

START_TEST(test_memchr_4) {
  char example1[256] = "sssddvs\0twgfwg";
  int c = '\0';
  size_t n = 16;
  ck_assert_uint_eq((unsigned long)memchr(example1, c, n),
                    (unsigned long)s21_memchr(example1, c, n));
}
END_TEST

Suite *suite_memchr() {
  Suite *s = suite_create("s21_memchr");

  TCase *tc_core = tcase_create("t_case_memchr");

  tcase_add_test(tc_core, test_memchr_1);
  tcase_add_test(tc_core, test_memchr_2);
  tcase_add_test(tc_core, test_memchr_3);
  tcase_add_test(tc_core, test_memchr_4);
  suite_add_tcase(s, tc_core);

  return s;
}