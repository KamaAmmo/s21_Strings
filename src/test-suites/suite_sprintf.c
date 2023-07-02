#include <locale.h>

#include "../s21_string_tests.h"

#define CSTR_N 5
const char *const_str[CSTR_N] = {"Hello, World!", "line1\nline2\nline3",
                                 "hmm\0huh?", "", "%%"};

#define CHAR_N 5
#define CHAR_M 3
const char *char_f[CHAR_N] = {"[%c]", "[%5c]", "[%-5c]", "%05c", "%#5c"};
const char char_v[CHAR_M] = {'a', '\n', '\0'};

#define WCHAR_N 6
#define WCHAR_M 6
const char *wchar_f[WCHAR_N] = {"[%lc]", "[%5lc]", "[%-5lc]",
                                "%.1lc", "%0lc",   "%0lc"};
const wchar_t wchar_v[WCHAR_M] = {L'⓲', L'♳', L'⑽', L'℟', L'⾹', L'\0'};

#define INT_N 13
#define INT_M 8
const char *int_f[INT_N] = {"[%d]",     "[%5d]",  "[%-5d]", "[%+d]", "[% d]",
                            "[%+ d]",   "[%+5d]", "[% 5d]", "%.0d",  "[%05d]",
                            "[%05.2d]", "%.3d",   "[%#5d]"};
const int int_v[INT_M] = {0, 5, -5, 100000, 12116, INT32_MAX, -256, -8};

#define DOUBLE_N 16
#define DOUBLE_M 12
const char *double_f[DOUBLE_N] = {"[%f]",     "[%5f]",  "[%-5f]",  "[%+f]",
                                  "[% f]",    "[%+ f]", "[%+5f]",  "[% 5f]",
                                  "%.0f",     "[%.5f]", "[%5.0f]", "[%-5.15f]",
                                  "[%+.-5f]", "%06f",   "%#f",     "%F"};
const double double_v[DOUBLE_M] = {
    0.0,     -0.0,    25,      253.505,  1.28887484e-15, 0.3333333333,
    25e+100, DBL_MIN, DBL_MAX, INFINITY, -INFINITY,      NAN};

#define STR_N 5
#define STR_M 5
const char *str_f[STR_N] = {"[%s]", "[%20s]", "[%-20s]", "[%20.5s]", "%.2s"};
const char *str_v[STR_M] = {"Hello, World!", "line1\nline2\nline3", "hmm\0huh?",
                            "", "%%"};

#define WSTR_N 5
#define WSTR_M 5
const char *wstr_f[WSTR_N] = {"[%s]", "[%20s]", "[%-20s]", "[%20.5s]", "%.2s"};
const wchar_t *wstr_v[WSTR_M] = {L"Привет, мир!", L"Ⲯ⧃①♑ⶍ≃⃗⏁‡♃⛕⼾⾨Ⲥ∆┤⭘⢸⚓⠊",
                                 L"ⷆⳕ⪡⹛◑\0♳❇⚜", L"⿁⎛⺘♈⌹ℛ⦚", L"sfaf⭓⫚⾟⤓⨄⧛⬵"};

#define UINT_N 8
#define UINT_M 8
const char *uint_f[INT_N] = {"[%d]",  "[%5d]",  "[%-5d]", "[%+d]",
                             "[% d]", "[%+ d]", "[%+5d]", "[% 5d]"};
const unsigned int uint_v[INT_M] = {0, 5, -5, 100000, 12116, INT32_MAX, 256, 8};

#define HEX_N 18
const char *hex_f[HEX_N] = {"[%x]",   "[%5x]",  "[%-5x]", "[%+x]",  "[% x]",
                            "[%+ x]", "[%+5x]", "[% 5x]", "[%.0x]", "[%X]",
                            "[%5X]",  "[%-5X]", "[%+X]",  "[% X]",  "[%+ X]",
                            "[%+5X]", "[% 5X]", "[%.0X]"};
// reuses uint_v

#define OCT_N 11
const char *oct_f[OCT_N] = {"[%o]",   "[%5o]",  "[%-5o]", "[%+o]",
                            "[% o]",  "[%+ o]", "[%+5o]", "[% 5o]",
                            "[%.0o]", "[%#o]",  "[%#.0o]"};
// reuses uint_v

#define EXP_N 16
const char *exp_f[EXP_N] = {"[%g]",     "[%5e]",  "[%-5e]",  "[%+g]",
                            "[% g]",    "[%+ g]", "[%+5e]",  "[% 5e]",
                            "%.0e",     "[%.5e]", "[%5.0e]", "[%-5.15e]",
                            "[%+.-5e]", "%06e",   "%#f",     "%F"};
// reuses double_v

#define GSPEC_N 16
const char *gspec_f[GSPEC_N] = {"[%g]",     "[%5g]",  "[%-5g]",  "[%+g]",
                                "[% g]",    "[%+ g]", "[%+5g]",  "[% 5g]",
                                "%.0g",     "[%.5g]", "[%5.0g]", "[%-5.15g]",
                                "[%+.-5g]", "%06g",   "%#g",     "%G"};
// reuses double_v

START_TEST(const_str_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, const_str[_i], NULL);
  int r_val_s21 = s21_sprintf(str_s21, const_str[_i], NULL);
  ck_assert_int_eq(r_val, r_val_s21);
  ck_assert_str_eq(str, str_s21);
}

START_TEST(char_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, char_f[_i / CHAR_M], char_v[_i % CHAR_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, char_f[_i / CHAR_M], char_v[_i % CHAR_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(wchar_test) {
  setlocale(LC_ALL, "");
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, wchar_f[_i / WCHAR_M], wchar_v[_i % WCHAR_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, wchar_f[_i / WCHAR_M], wchar_v[_i % WCHAR_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(int_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, int_f[_i / INT_M], int_v[_i % INT_M]);
  int r_val_s21 = s21_sprintf(str_s21, int_f[_i / INT_M], int_v[_i % INT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(double_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, double_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, double_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(str_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, str_f[_i / STR_M], str_v[_i % STR_M]);
  int r_val_s21 = s21_sprintf(str_s21, str_f[_i / STR_M], str_v[_i % STR_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(wstr_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, wstr_f[_i / 5], wstr_v[_i % 5]);
  int r_val_s21 = s21_sprintf(str_s21, wstr_f[_i / 5], wstr_v[_i % 5]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(uint_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, uint_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, uint_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(hex_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, hex_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, hex_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(oct_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, oct_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, oct_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(exp_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, exp_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, exp_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(gspec_test) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, gspec_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, gspec_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

Suite *suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");

  TCase *tc_base = tcase_create("Loops");
  tcase_add_loop_test(tc_base, const_str_test, 0, CSTR_N);
  tcase_add_loop_test(tc_base, char_test, 0, CHAR_N * CHAR_M);
  tcase_add_loop_test(tc_base, wchar_test, 0, WCHAR_N * WCHAR_M);
  tcase_add_loop_test(tc_base, int_test, 0, INT_N * INT_M);
  // tcase_add_loop_test(tc_base, double_test, 0, DOUBLE_N * DOUBLE_M);
  tcase_add_loop_test(tc_base, str_test, 0, STR_N * STR_M);
  tcase_add_loop_test(tc_base, wstr_test, 0, WSTR_N * WSTR_M);
  tcase_add_loop_test(tc_base, uint_test, 0, UINT_N * UINT_M);
  tcase_add_loop_test(tc_base, hex_test, 0, HEX_N * UINT_M);
  tcase_add_loop_test(tc_base, oct_test, 0, OCT_N * UINT_M);
  // tcase_add_loop_test(tc_base, exp_test, 0, EXP_N * DOUBLE_M);
  // tcase_add_loop_test(tc_base, gspec_test, 0, GSPEC_N * DOUBLE_M);
  suite_add_tcase(s, tc_base);

  return s;
}