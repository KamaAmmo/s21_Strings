#include "../s21_string_tests.h"

START_TEST(test_memcpy_1) {
  char example1[256] = "1234";
  char dest[256] = "-101c";
  size_t n = 3;
  ck_assert_str_eq(memcpy(dest, example1, n), s21_memcpy(dest, example1, n));
}
END_TEST

START_TEST(test_memcpy_2) {
  char example1[256] = "\0sdv";
  char dest[256] = "sdvs//\0";
  size_t n = 8;
  ck_assert_str_eq(memcpy(dest, example1, n), s21_memcpy(dest, example1, n));
}
END_TEST

START_TEST(test_memcpy_3) {
  char example1[256] = "\0sdv";
  char dest[256] = "";
  size_t n = 8;
  ck_assert_str_eq(memcpy(dest, example1, n), s21_memcpy(dest, example1, n));
}
END_TEST

START_TEST(test_memcpy_4) {
  char example1[256] = "//%dwq\011sdv";
  char dest[256] = "//\n12/////";
  size_t n = 8;
  ck_assert_str_eq(memcpy(dest, example1, n), s21_memcpy(dest, example1, n));
}
END_TEST

Suite *suite_memcpy() {
  Suite *s = suite_create("s21_memcpy");

  TCase *tc_core = tcase_create("t_case_memcpy");

  tcase_add_test(tc_core, test_memcpy_1);
  tcase_add_test(tc_core, test_memcpy_2);
  tcase_add_test(tc_core, test_memcpy_3);
  tcase_add_test(tc_core, test_memcpy_4);
  suite_add_tcase(s, tc_core);

  return s;
}
