#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <check.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"

Suite *suite_memchr();
Suite *suite_memcmp();
Suite *suite_memcpy();
Suite *suite_memset();
Suite *suite_strncat();

Suite *suite_strchr();
Suite *suite_strncmp();
Suite *suite_strncpy();
Suite *suite_strcspn();
Suite *suite_strerror();

Suite *suite_strlen();
Suite *suite_strpbrk();
Suite *suite_strrchr();
Suite *suite_strstr();
Suite *suite_strtok();

Suite *suite_to_upper();
Suite *suite_to_lower();
Suite *suite_insert();
Suite *suite_trim();

Suite *suite_sscanf();
Suite *suite_sprintf();

void run_suite(Suite *s);

#endif  // S21_STRING_TESTS_H