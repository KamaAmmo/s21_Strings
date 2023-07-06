#include "../s21_string_tests.h"

START_TEST(test_insert_1) {
  char example1[16] = "//ddd///";
  char delim[4] = "123";
  size_t n = 2;
  ck_assert_str_eq(s21_insert(example1, delim, n), "//123ddd///");
}
END_TEST

START_TEST(test_insert_2) {
  char example1[2] = "ahg";
  char delim[2] = "vvvvv";
  size_t n = 1;
  ck_assert_str_eq(s21_insert(example1, delim, n), "avvhvv");
}
END_TEST

Suite *suite_insert() {
  Suite *s = suite_create("s21_insert");

  TCase *tc_core = tcase_create("");

  tcase_add_test(tc_core, test_insert_1);
  tcase_add_test(tc_core, test_insert_2);
  suite_add_tcase(s, tc_core);

  return s;
}