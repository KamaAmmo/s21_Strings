#include "../s21_string_tests.h"

const char const_str[5][100] = {"Hello, World!", "line1\nline2\nline3",
                                "hmm\0huh?", "", "%%"};

START_TEST(const_str_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, const_str[_i], NULL);
  int r_val_s21 = s21_sprintf(str_s21, const_str[_i], NULL);
  ck_assert_int_eq(r_val, r_val_s21);
  ck_assert_str_eq(str, str_s21);
}

const char char_f[3][100] = {"[%c]", "[%5c]", "[%-5c]"};
const char char_c[3] = {'a', '\n', '\0'};

START_TEST(char_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, char_f[_i / 3], char_c[_i % 3]);
  int r_val_s21 = s21_sprintf(str_s21, char_f[_i / 3], char_c[_i % 3]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

const char int_f[8][100] = {"[%d]",  "[%5d]",  "[%-5d]", "[%+d]",
                            "[% d]", "[%+ d]", "[%+5d]", "[% 5d]"};
const int int_i[8] = {0, 5, -5, 100000, 12116, INT32_MAX, -256, -8};

START_TEST(int_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, int_f[_i / 8], int_i[_i % 8]);
  int r_val_s21 = s21_sprintf(str_s21, int_f[_i / 8], int_i[_i % 8]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

const char str_f[5][100] = {"[%s]", "[%20s]", "[%-20s]", "[%20.5s]", "%.2s"};
const char str_s[5][100] = {"Hello, World!", "line1\nline2\nline3", "hmm\0huh?",
                            "", "%%"};

START_TEST(str_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, str_f[_i / 5], str_s[_i % 5]);
  int r_val_s21 = s21_sprintf(str_s21, str_f[_i / 5], str_s[_i % 5]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

// "[%05d]", "[%+05d]", "[% 05d]"
Suite *suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");

  TCase *tc_base = tcase_create("Base");
  tcase_add_loop_test(tc_base, const_str_test, 0, 5);
  tcase_add_loop_test(tc_base, char_test, 0, 9);
  tcase_add_loop_test(tc_base, int_test, 0, 64);
  tcase_add_loop_test(tc_base, str_test, 0, 25);
  suite_add_tcase(s, tc_base);

  return s;
}