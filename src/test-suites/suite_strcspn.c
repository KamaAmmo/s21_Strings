#include "../s21_string_tests.h"

START_TEST(test_strcspn_1) {
  char example1[256] = "sdf FFF UWEuw 0";
  char example2[256] = "sdf FFF UWEuw 0";
  ck_assert_uint_eq(strcspn(example1, example2),
                    s21_strcspn(example1, example2));
}
END_TEST

START_TEST(test_strcspn_2) {
  char example1[256] = "sdf FFF UWEuw 0";
  char example2[256] = "\n%d";
  ck_assert_uint_eq(strcspn(example1, example2),
                    s21_strcspn(example1, example2));
}
END_TEST

START_TEST(test_strcspn_3) {
  char example1[256] = "sdf FFF UWEuw 0";
  char example2[256] = "";
  ck_assert_uint_eq(strcspn(example1, example2),
                    s21_strcspn(example1, example2));
}
END_TEST

Suite *suite_strcspn() {
  Suite *s = suite_create("s21_strcspn");

  TCase *tc_core = tcase_create("t_case_strcspn");
  tcase_add_test(tc_core, test_strcspn_1);
  tcase_add_test(tc_core, test_strcspn_2);
  tcase_add_test(tc_core, test_strcspn_3);

  suite_add_tcase(s, tc_core);

  return s;
}