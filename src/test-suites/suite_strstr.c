// #include "../s21_string_tests.h"

// Suite *suite_strstr() {
//   Suite *s = suite_create("s21_strstr");

//   TCase *tc_core = tcase_create("");
//   suite_add_tcase(s, tc_core);

//   return s;
// }

#include "../s21_string_tests.h"

START_TEST(test_strstr_1) {
  char example1[256] = "I like Linux";
  char needle[256] = "Linux";
  ck_assert_str_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

START_TEST(test_strstr_2) {
  char example1[256] = "sdfefff\n";
  char needle[256] = "\n";
  ck_assert_str_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

START_TEST(test_strstr_3)  //!!!!!!!!!!!!!!!!!!!!
{
  char example1[256] = "''''\0''''";
  char needle[256] = "\0";
  ck_assert_str_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

START_TEST(test_strstr_4) {
  char example1[256] = "''''\0''''";
  char needle[256] = "pd";
  ck_assert_ptr_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

START_TEST(test_strstr_5) {
  char example1[256] = "this is a test string";
  char needle[256] = "a test 2";
  ck_assert_ptr_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

START_TEST(test_strstr_6) {
  char example1[256] = "this is a test string";
  char needle[256] = "string and";
  ck_assert_ptr_eq(strstr(example1, needle), s21_strstr(example1, needle));
}
END_TEST

Suite *suite_strstr() {
  Suite *s = suite_create("s21_strstr");

  TCase *tc_core = tcase_create("t_case_strstr");

  tcase_add_test(tc_core, test_strstr_1);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);
  tcase_add_test(tc_core, test_strstr_6);

  suite_add_tcase(s, tc_core);

  return s;
}
