#include "s21_string_tests.h"

#include "s21_string.h"

int main(void) {
  Suite *test_suites[21];

  test_suites[0] = suite_memchr();
  test_suites[1] = suite_memcmp();
  test_suites[2] = suite_memcpy();
  test_suites[3] = suite_memset();
  test_suites[4] = suite_strncat();

  test_suites[5] = suite_strchr();
  test_suites[6] = suite_strncmp();
  test_suites[7] = suite_strncpy();
  test_suites[8] = suite_strcspn();
  test_suites[9] = suite_strerror();

  test_suites[10] = suite_strlen();
  test_suites[11] = suite_strpbrk();
  test_suites[12] = suite_strrchr();
  test_suites[13] = suite_strstr();
  test_suites[14] = suite_strtok();

  test_suites[15] = suite_to_upper();
  test_suites[16] = suite_to_lower();
  test_suites[17] = suite_insert();
  test_suites[18] = suite_trim();

  test_suites[19] = suite_sscanf();
  test_suites[20] = suite_sprintf();

  for (int i = 0; i < 21; i++) run_suite(test_suites[i]);
  return 0;
}

void run_suite(Suite *s) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}