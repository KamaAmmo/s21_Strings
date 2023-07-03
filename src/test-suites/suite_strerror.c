#include "../s21_string_tests.h"

// START_TEST(test_strerror_1)
// {
//   char example1[256] = {0};
//   ck_assert_str_eq(strerror(example1), s21_strerror(example1));
// }
// END_TEST

// START_TEST(test_strerror_2)
// {
//   char example1[256] = "";
//   ck_assert_str_eq(strerror(example1), s21_strerror(example1));
// }
// END_TEST

Suite *suite_strerror() {
  Suite *s = suite_create("s21_strerror");

  TCase *tc_core = tcase_create("t_case_strerror");

  // tcase_add_test(tc_core,test_strerror_1);
  // tcase_add_test(tc_core,test_strerror_2);
  suite_add_tcase(s, tc_core);

  return s;
}