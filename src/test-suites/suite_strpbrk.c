#include "../s21_string_tests.h"

START_TEST(test_strpbrk_1) {
  char example1[256] = "\0sac";
  char example2[256] = "\0123";

  ck_assert_uint_eq((unsigned long)s21_strpbrk(example1, example2),
                    (unsigned long)strpbrk(example1, example2));
}
END_TEST

START_TEST(test_strpbrk_2) {
  char example1[256] = "123\0sac";
  char example2[256] = "\0123";

  ck_assert_uint_eq((unsigned long)s21_strpbrk(example1, example2),
                    (unsigned long)strpbrk(example1, example2));
}
END_TEST

START_TEST(test_strpbrk_3) {
  char example1[256] = "";
  char example2[256] = "\0123";

  ck_assert_uint_eq((unsigned long)s21_strpbrk(example1, example2),
                    (unsigned long)strpbrk(example1, example2));
}
END_TEST

START_TEST(test_strpbrk_4) {
  char example1[256] = "1234\n";
  char example2[256] = "\t";

  ck_assert_uint_eq((unsigned long)s21_strpbrk(example1, example2),
                    (unsigned long)strpbrk(example1, example2));
}
END_TEST

Suite *suite_strpbrk() {
  Suite *s = suite_create("s21_strpbrk");

  TCase *tc_core = tcase_create("");
  tcase_add_test(tc_core, test_strpbrk_1);
  tcase_add_test(tc_core, test_strpbrk_2);
  tcase_add_test(tc_core, test_strpbrk_3);
  tcase_add_test(tc_core, test_strpbrk_4);
  suite_add_tcase(s, tc_core);

  return s;
}