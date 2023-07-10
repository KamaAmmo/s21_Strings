#include <stdlib.h>

#include "../s21_string_tests.h"

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = S21_NULL;
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_11) {
  char example1[256] = "//ddd///dfg//";
  char delim[256] = "/";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "ddd///dfg");
  free(test);
}
END_TEST

START_TEST(test_trim_12) {
  char example1[256] = "abcab//ddd///dfg//abccab";
  char delim[256] = "abc";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "//ddd///dfg//");
  free(test);
}
END_TEST

START_TEST(test_trim_13) {
  char example1[256] = "ddddabcab//";
  char delim[256] = "ddddddd";
  char *test = s21_trim(example1, delim);
  ck_assert_str_eq(test, "abcab//");
  free(test);
}
END_TEST

Suite *suite_trim() {
  Suite *s = suite_create("s21_trim");

  TCase *tc_core = tcase_create("");

  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_trim_3);
  tcase_add_test(tc_core, test_trim_4);
  tcase_add_test(tc_core, test_trim_5);
  tcase_add_test(tc_core, test_trim_6);
  tcase_add_test(tc_core, test_trim_7);
  tcase_add_test(tc_core, test_trim_8);
  tcase_add_test(tc_core, test_trim_9);
  tcase_add_test(tc_core, test_trim_10);
  tcase_add_test(tc_core, test_trim_11);
  tcase_add_test(tc_core, test_trim_12);
  tcase_add_test(tc_core, test_trim_13);
  suite_add_tcase(s, tc_core);

  return s;
}