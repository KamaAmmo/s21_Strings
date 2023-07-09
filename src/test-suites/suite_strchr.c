#include "../s21_string_tests.h"

START_TEST(test_strchr_1) {
  char example1[256] = "sdf FFF UWEuw 0";
  int c = '0';
  ck_assert_ptr_eq(strchr(example1, c), s21_strchr(example1, c));
}
END_TEST

START_TEST(test_strchr_2)  // !!!!!!!!!!!!!!!!!!!!!
{
  char example1[256] = "JJ sv'av w \0 ds s";
  int c = '\0';
  ck_assert_ptr_eq(strchr(example1, c), s21_strchr(example1, c));
}
END_TEST

START_TEST(test_strchr_3) {
  char example1[256] = "JJ sv'av w \0 ds s";
  int c = 'r';
  ck_assert_ptr_eq(strchr(example1, c), s21_strchr(example1, c));
}
END_TEST

Suite *suite_strchr() {
  Suite *s = suite_create("s21_strchr");

  TCase *tc_core = tcase_create("t_case_strchr");

  tcase_add_test(tc_core, test_strchr_1);
  tcase_add_test(tc_core, test_strchr_2);
  tcase_add_test(tc_core, test_strchr_3);
  suite_add_tcase(s, tc_core);

  return s;
}