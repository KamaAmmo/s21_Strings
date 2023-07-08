#include <locale.h>

#include "../s21_string_tests.h"

// One argument tests
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

#define DOUBLE_N 18
#define DOUBLE_M 13
const char *double_f[DOUBLE_N] = {
    "[%f]",   "[%5f]",  "[%-5f]", "[%+f]",  "[% f]",   "[%+ f]",
    "[%+5f]", "[% 5f]", "%.0f",   "[%.5f]", "[%5.0f]", "[%-5.15f]",
    "[%+.f]", "%06f",   "%#f",    "%F",     "%#.0f",   "%.16f"};
const double double_v[DOUBLE_M] = {0.0,
                                   -0.0,
                                   25,
                                   253.505,
                                   1.28887484e-15,
                                   0.3333333333,
                                   25e+10,
                                   0.58778449849444944,
                                   2132164989746516.,
                                   213216498974651.58778449849444944,
                                   INFINITY,
                                   -INFINITY,
                                   NAN};

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
const unsigned int uint_v[INT_M] = {0,     5,          -5,  100000,
                                    12116, UINT32_MAX, 256, 8};

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
const char *exp_f[EXP_N] = {"[%g]",     "[%5e]",   "[%-5e]",  "[%+g]",
                            "[% g]",    "[%+= g]", "[%+5e]",  "[% 5e]",
                            "%.0e",     "[%.5e]",  "[%5.0e]", "[%-5.15e]",
                            "[%+.-5e]", "%06e",    "%#f",     "%F"};
// reuses double_v

#define GSPEC_N 16
const char *gspec_f[GSPEC_N] = {"[%g]",     "[%5g]",  "[%-5g]",  "[%+g]",
                                "[% g]",    "[%+ g]", "[%+5g]",  "[% 5g]",
                                "%.0g",     "[%.5g]", "[%5.0g]", "[%-5.15g]",
                                "[%+.-5g]", "%06g",   "%#g",     "%G"};
// reuses double_v

START_TEST(const_str_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, const_str[_i], NULL);
  int r_val_s21 = s21_sprintf(str_s21, const_str[_i], NULL);
  ck_assert_int_eq(r_val, r_val_s21);
  ck_assert_str_eq(str, str_s21);
}

START_TEST(char_t) {
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

START_TEST(int_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, int_f[_i / INT_M], int_v[_i % INT_M]);
  int r_val_s21 = s21_sprintf(str_s21, int_f[_i / INT_M], int_v[_i % INT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(double_test) {
  char str[1000];
  char str_s21[10000];
  int r_val = sprintf(str, double_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, double_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(str_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, str_f[_i / STR_M], str_v[_i % STR_M]);
  int r_val_s21 = s21_sprintf(str_s21, str_f[_i / STR_M], str_v[_i % STR_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(wstr_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, wstr_f[_i / 5], wstr_v[_i % 5]);
  int r_val_s21 = s21_sprintf(str_s21, wstr_f[_i / 5], wstr_v[_i % 5]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(uint_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, uint_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, uint_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(hex_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, hex_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, hex_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(oct_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, oct_f[_i / UINT_M], int_v[_i % UINT_M]);
  int r_val_s21 = s21_sprintf(str_s21, oct_f[_i / UINT_M], int_v[_i % UINT_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(exp_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, exp_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, exp_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(gspec_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, gspec_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  int r_val_s21 =
      s21_sprintf(str_s21, gspec_f[_i / DOUBLE_M], double_v[_i % DOUBLE_M]);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

// Multi argument tests
START_TEST(star_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, "[%*.*d]", 10, 5, 25);
  int r_val_s21 = s21_sprintf(str_s21, "[%*.*d]", 10, 5, 25);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

START_TEST(combo_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, "[%da%s%o%x]", 10, "Hello!", 256, 256);
  int r_val_s21 = s21_sprintf(str_s21, "[%da%s%o%x]", 10, "Hello!", 256, 256);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

// Crash tests
#define BAD_FORMAT_N 6
const char *bad_format_f[BAD_FORMAT_N] = {"a%-+", "%d%15.15%o", "%d%q %o",
                                          "%.d",  "%5.-5d",     "%.2"};
START_TEST(bad_format_t) {
  char str[100];
  char str_s21[100];
  int r_val = sprintf(str, bad_format_f[_i], 10, "Hello!", 256, 256);
  int r_val_s21 =
      s21_sprintf(str_s21, bad_format_f[_i], 10, "Hello!", 256, 256);
  ck_assert_str_eq(str, str_s21);
  ck_assert_int_eq(r_val, r_val_s21);
}

Suite *suite_sprintf() {
  Suite *s = suite_create("s21_sprintf");

  TCase *tc_one_arg = tcase_create("OneArg");
  tcase_add_loop_test(tc_one_arg, const_str_t, 0, CSTR_N);
  tcase_add_loop_test(tc_one_arg, char_t, 0, CHAR_N * CHAR_M);
  tcase_add_loop_test(tc_one_arg, wchar_test, 0, WCHAR_N * WCHAR_M);
  tcase_add_loop_test(tc_one_arg, int_t, 0, INT_N * INT_M);
  tcase_add_loop_test(tc_one_arg, double_test, 0, DOUBLE_N * DOUBLE_M);
  tcase_add_loop_test(tc_one_arg, str_t, 0, STR_N * STR_M);
  tcase_add_loop_test(tc_one_arg, wstr_t, 0, WSTR_N * WSTR_M);
  tcase_add_loop_test(tc_one_arg, uint_t, 0, UINT_N * UINT_M);
  tcase_add_loop_test(tc_one_arg, hex_t, 0, HEX_N * UINT_M);
  tcase_add_loop_test(tc_one_arg, oct_t, 0, OCT_N * UINT_M);
  // tcase_add_loop_test(tc_one_arg, exp_t, 0, EXP_N * DOUBLE_M);
  // tcase_add_loop_test(tc_one_arg, gspec_t, 0, GSPEC_N * DOUBLE_M);
  suite_add_tcase(s, tc_one_arg);

  TCase *tc_multi_arg = tcase_create("MultiArg");
  tcase_add_test(tc_multi_arg, star_t);
  tcase_add_test(tc_multi_arg, combo_t);
  suite_add_tcase(s, tc_multi_arg);

  TCase *tc_crash_test = tcase_create("CrashTests");
  // tcase_add_loop_test(tc_crash_test, bad_format_t, 0, BAD_FORMAT_N);
  suite_add_tcase(s, tc_crash_test);

  return s;
}