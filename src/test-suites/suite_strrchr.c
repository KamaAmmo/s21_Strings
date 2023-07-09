// #include "../s21_string_tests.h"

// Suite *suite_strrchr() {
//   Suite *s = suite_create("s21_strrchr");

//   TCase *tc_core = tcase_create("");
//   suite_add_tcase(s, tc_core);

//   return s;
// }

#include "../s21_string_tests.h"

START_TEST(test_strrchr_1) {
  char example1[256] = "I like Linux";
  int c = 'L';
  ck_assert_str_eq(strrchr(example1, c), s21_strrchr(example1, c));
}
END_TEST

START_TEST(test_strrchr_2) {
  char example1[256] = "\n  jfdww \t";
  int c = '\\';
  ck_assert_ptr_eq(strrchr(example1, c), s21_strrchr(example1, c));
}
END_TEST

START_TEST(test_strrchr_3) {
  char example1[256] = "";
  int c = 'L';
  ck_assert_ptr_eq(strrchr(example1, c), s21_strrchr(example1, c));
}
END_TEST

START_TEST(test_strrchr_4)  //!!!!!!!!!!!!!!!!!
{
  char example1[256] = "dssewbwcwv";
  int c = '\0';
  ck_assert_str_eq(strrchr(example1, c), s21_strrchr(example1, c));
}
END_TEST

Suite *suite_strrchr() {
  Suite *s = suite_create("s21_strrchr");

  TCase *tc_core = tcase_create("t_case_strrchr");

  tcase_add_test(tc_core, test_strrchr_1);
  tcase_add_test(tc_core, test_strrchr_2);
  tcase_add_test(tc_core, test_strrchr_3);
  tcase_add_test(tc_core, test_strrchr_4);

  suite_add_tcase(s, tc_core);

  return s;
}