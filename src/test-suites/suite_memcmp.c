// #include "../s21_string_tests.h"

// Suite *suite_memcmp() {
//   Suite *s = suite_create("s21_memcmp");

//   TCase *tc_core = tcase_create("");
//   suite_add_tcase(s, tc_core);

//   return s;
// }

#include "../s21_string_tests.h"

START_TEST(test_memcmp_1) {
  char example1[256] = "/////ddd///dfg/";
  char example2[256] = "/////ddd///dfg/";
  size_t n = 14;
  ck_assert_uint_eq(memcmp(example1, example2, n),
                    s21_memcmp(example1, example2, n));
}
END_TEST

START_TEST(test_memcmp_2) {
  char example1[256] = "It was \0(";
  char example2[256] = "\0(";
  size_t n = 14;
  ck_assert_uint_eq(memcmp(example1, example2, n),
                    s21_memcmp(example1, example2, n));
}
END_TEST

START_TEST(test_memcmp_3) {
  char example1[256] = "\n\n\n\n\n";
  char example2[256] = "fssrgn";
  size_t n = 14;
  ck_assert_uint_eq(memcmp(example1, example2, n),
                    s21_memcmp(example1, example2, n));
}
END_TEST

START_TEST(test_memcmp_4) {
  char example1[256] = "";
  char example2[256] = "";
  size_t n = 14;
  ck_assert_uint_eq(memcmp(example1, example2, n),
                    s21_memcmp(example1, example2, n));
}
END_TEST

Suite *suite_memcmp() {
  Suite *s = suite_create("s21_memcmp");

  TCase *tc_core = tcase_create("t_case_memcmp");

  tcase_add_test(tc_core, test_memcmp_1);
  tcase_add_test(tc_core, test_memcmp_2);
  tcase_add_test(tc_core, test_memcmp_3);
  tcase_add_test(tc_core, test_memcmp_4);
  suite_add_tcase(s, tc_core);

  return s;
}