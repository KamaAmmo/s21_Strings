#include <check.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#define BUF_SIZE 256

// 1////////////////----------memchr---------//////////////////

START_TEST(memchr_1) {
  char string[] = "void* s21_memchr(const void* str, int c, s21_size_t n) {";
  int ch = ' ';
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  char string[] = "void* s21_memchr(const void* str, int c, s21_size_t n) {";
  int ch = 109;
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  char string[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  char string[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  char string[] = "void* s21_memchr(const void* str, int c, s21_size_t n) {";
  int ch = 's';
  s21_size_t len = 6;
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  char string[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  char string[] = "12457896";
  int ch = '3';
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  char string[] = "354897524";
  int ch = '3';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_9) {
  char string[] = "mvrjvoierjvniw";
  int ch = 'a';
  s21_size_t len = strlen(string);
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

START_TEST(memchr_10) {
  char string[] = "qwertyuiop";
  int ch = '\0';
  s21_size_t len = 11;
  ck_assert_ptr_eq(memchr(string, ch, len), s21_memchr(string, ch, len));
}
END_TEST

// 2////////////////----------memcmp---------//////////////////

START_TEST(memcmp_1) {
  char s1[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  char s2[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  s21_size_t n = 10;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_2) {
  char s1[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  char s2[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_3) {
  char s1[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  char s2[] = "int memcmp(const void *str1, const void *str2, size_t n)";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_5) {
  char s1[] = "qwertyuiop";
  char s2[] = "qwertyuiop";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_6) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_7) {
  char s1[] = "127";
  char s2[] = "698";
  s21_size_t n = 2;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_8) {
  char s1[] = "111111111";
  char s2[] = "222222222";
  s21_size_t n = 6;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_10) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_11) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 4;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_13) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_14) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

// 3////////////////----------memcpy---------//////////////////

START_TEST(memcpy_1) {
  char s1[] = "char *memcpy(void *dest, const void *src, size_t n)";
  char s2[] = "char *memcpy(void *dest, const void *src, size_t n)";
  char s3[] = "void";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "qwertyuiop";
  char s2[] = "qwertyuiop";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_5) {
  char s1[] = "  hool 21";
  char s2[] = "  hool 21";
  char s3[] = "sc";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "memcpy";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[] = "123456789111(void *dest, const void *src, size_t n)";
  char s2[] = "123456789111(void *dest, const void *src, size_t n)";
  char s3[] = "void *memcpy";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

// 4////////////////----------memset---------//////////////////

START_TEST(memset_1) {
  s21_size_t n1 = 6;
  int c1 = '2';
  char b1[1024] = "void *memset(void *str, int c, size_t n)";
  char b11[1024] = "void *memset(void *str, int c, size_t n)";
  ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n2 = 4;
  int c2 = '5';
  char b2[1024] = "s21_memset";
  char b22[1024] = "s21_memset";
  ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n3 = 6;
  int c3 = '7';
  char b3[1024] = "irilethjirilethj";
  char b33[1024] = "irilethjirilethj";
  ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST

START_TEST(memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

// 5////////////////----------strncat---------//////////////////

START_TEST(strncat_2) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_3) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_6) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "qwertyuiopa\0 sdfghj.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_7) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_8) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_10) {
  char s1[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s2[100] = "char *strncat(char *dest, const char *src, size_t n)";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_11) {
  char s1[100] = "Hello, school 21\0\0\0";
  char s2[100] = "Hello, school 21\0\0\0";
  char s3[] = "good";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

// 6////////////////----------strchr---------//////////////////

START_TEST(strchr_1) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = '*';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 'c';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 111;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 'a';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 'i';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 'y';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "char *strchr(const char *str, int c)";
  int ch = 'z';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

////////////////----------strncmp---------//////////////////

START_TEST(strncmp_1) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 13;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_2) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 7;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_3) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_4) {
  char s1[] = "strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_5) {
  char s1[] = "int strncmp(const char *str1, const char *str2, size_t n)";
  char s2[] = "const char *str1, const char *str2, size_t n)";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_6) {
  char s1[] = "qwertyuiop";
  char s2[] = "qwertyuiop";
  s21_size_t n = 9;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_7) {
  char s1[] = "9876543210";
  char s2[] = "9876543210";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_8) {
  char s1[] = "\0asdfghj";
  char s2[] = "asdfghj";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "     ";
  char s2[] = " ";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

// 8////////////////----------strncpy---------//////////////////

START_TEST(strncpy_1) {
  char dest[100] = " *strncpy(char *dest, const char *src, size_t n)";
  char dest2[100] = " *strncpy(char *dest, const char *src, size_t n)";
  char src[] = "char";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char dest[100] = "char *strncpy(char *dest, const char *src, size_t n)";
  char dest2[100] = "char *strncpy(char *dest, const char *src, size_t n)";
  char src[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest2, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  char dest[5] = "";
  char dest2[5] = "";
  char src[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest2, src, n));
}
END_TEST

// 9////////////////----------strcspn---------//////////////////

START_TEST(strcspn_1) {
  char s1[] = "size_t strcspn(const char *str1, const char *str2)";
  char sym[] = "strcspn";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] = "size_t strcspn(const char *str1, const char *str2)";
  char sym[] = "const";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "qwertyuiop";
  char sym[] = "q";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "";
  char sym[] = "qwer";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "123456789";
  char sym[] = "";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "6";
  char sym[] = "67";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "size_t strcspn(const char *str1, const char *str2)";
  char sym[] = "size_t strcspn(const char *str1, const char *str2)";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "17020";
  char sym[] = "7020";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "9";
  char sym[] = "69917020";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "0000000";
  char sym[] = "10";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "       ";
  char sym[] = "\0";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] = "sym     12345";
  char sym[] = "3";
  ck_assert_int_eq(strcspn(s1, sym), s21_strcspn(s1, sym));
}
END_TEST

// 10////////////////----------strerror---------//////////////////

START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

// 11////////////////----------strlen---------//////////////////

START_TEST(strlen_1) {
  char string[] = "size_t strlen(const char *str)!";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_2) {
  char string[] = "         1234567899    \0    rtgrgerg \0";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_3) {
  char string[] = "Hello, world!";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_4) {
  char string[] = "\0";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_5) {
  char string[] = "qwertyuiop";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_6) {
  char string[] = "";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_7) {
  char string[] = "\\\\\\\\";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_8) {
  char string[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_9) {
  char string[] = "\n\n\n\n\n\n\n\n\n1234567890\n\n\n\n\n";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_10) {
  char string[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_11) {
  char string[] = "";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_12) {
  char string[] = "\t\t";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_13) {
  char string[] = "\0test";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_14) {
  char string[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

// 12////////////////----------strpbrk---------//////////////////

START_TEST(strpbrk_1) {
  char s1[] = "char *strpbrk(const char *str1, const char *str2)";
  char s2[] = "*";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "char *strpbrk(const char *str1, const char *str2)";
  char s2[] = ")";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "char *strpbrk(const char *str1, const char *str2)";
  char s2[] = "n";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// 13////////////////----------strrchr---------//////////////////

START_TEST(strrchr_1) {
  char s[] = "char *strrchr(const char *str, int c)";
  int ch = 'c';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char s[] = "char *strrchr(const char *str, int c)";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char s[] = "char *strrchr(const char *str, int c)";
  int ch = 'i';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char s[] = "qwertyuiop";
  int ch = 'p';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char s[] = "11111111112222222222221";
  int ch = '1';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char s[] = "Hello\0, world!";
  int ch = 'd';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char s[] = "char *strrchr(const char *str, int c)";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

// 14////////////////----------strstr---------//////////////////

START_TEST(strstr_1) {
  char haystack[] = "char *strstr(const char *haystack, const char *needle)";
  char needle[] = "char *strstr(const char *haystack, const char *needle)";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  char haystack[] = "char *strstr(const char *haystack, const char *needle)";
  char needle[] = "char";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  char haystack[] = "char *strstr(const char *haystack, const char *needle)";
  char needle[] = "ar *hay";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  char haystack[] = "char *strstr(const char *haystack, const char *needle)";
  char needle[] = "*st";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_6) {
  char haystack[] = "qweeertyuiop";
  char needle[] = "";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_7) {
  char haystack[] = "";
  char needle[] = "1234567890";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_8) {
  char haystack[] = "69917020";
  char needle[] = "0";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_9) {
  char haystack[] = "147852369";
  char needle[] = "\0";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_10) {
  char haystack[] = "000000000000000000";
  char needle[] = " 00000000";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_11) {
  char haystack[] = "cfvbhdjkmcdbifyuvwbcikmsdvnbuniacjkmonvebhsujnidc";
  char needle[] = "regbtnhbgvd";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_12) {
  char haystack[] =
      "ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, "
      "needle));";
  char needle[] = "_a";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_13) {
  char haystack[] = "irilethl";
  char needle[] = "\0";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

// 15////////////////----------strtok---------//////////////////

START_TEST(strtok_1) {
  char s1[] = "char *strtok(char *str, const char *delim)";
  char s2[] = "char *strtok(char *str, const char *delim)";
  char delim[] = "char";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char delim[] = "";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "char *strtok(char *str, const char *delim)";
  char s2[] = "char *strtok(char *str, const char *delim)";
  char delim[] = "\0";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "char *strtok(char *str, const char *delim)";
  char s2[] = "char *strtok(char *str, const char *delim)";
  char delim[] = "(";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "char *strtok(char *str, const char *delim)";
  char s2[] = "char *strtok(char *str, const char *delim)";
  char delim[] = "char *strtok(char *str, const char *delim)";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_6) {
  char s1[] =
      "12345/76876/97898/fgbfd/thtyj/fewfwe/ergergberg/ergergergh/jyujyuth/"
      "rtge/rfefw/grgreg/gr";
  char s2[] =
      "12345/76876/97898/fgbfd/thtyj/fewfwe/ergergberg/ergergergh/jyujyuth/"
      "rtge/rfefw/grgreg/gr";
  char delim[] = "/";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char delim[] = "B";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char delim[] = "A";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char delim[] = "\0";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST

START_TEST(strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char delim[] = "";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}
END_TEST


START_TEST(strtok_12) {
  char s1[] = "1kcjscjosdicjk1iojdweoicjwio1weiojdiowejc1dwejoicjw1icdoi";
  char s2[] = "1kcjscjosdicjk1iojdweoicjwio1weiojdiowejc1dwejoicjw1icdoi";
  char delim[] = "1";
  ck_assert_pstr_eq(strtok(s1, delim), s21_strtok(s2, delim));
}

// 16////////////////----------to_upper---------//////////////////

START_TEST(test_to_upper_1) {
  char s1[30] = "qwertyuiop";
  char *s2 = s21_to_upper(s1);
  char s3[] = "QWERTYUIOP";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char s1[30] = "\nf\t\\a123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nF\t\\A123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char s1[30] = "IRILETHJ";
  char *s2 = s21_to_upper(s1);
  char s3[] = "IRILETHJ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *s1 = S21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = S21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

// 17////////////////----------to_lower---------//////////////////

START_TEST(test_to_lower_1) {
  char s1[30] = "qwerty";
  char s3[] = "QWErty";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "irilethj";
  char s3[] = "irilethj";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

// 18////////////////----------insert---------//////////////////

START_TEST(test_insert_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = S21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = S21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_9) {
  char s1[] = "wtf";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_10) {
  char s1[] = "";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

// 19////////////////----------trim---------//////////////////

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

/////////////// ---------sprintf-----------/////////////////////
////////////////////-----sprintf_cpec_c-----///////////////////

// START_TEST(sprintf_1_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%c format_c %c format_c %c format_c %c format_c %c";
//   int a = 6;
//   int b = 7;
//   int c = 8;
//   int d = 55;
//   int e = 94;
//   ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
//                    s21_sprintf(str2, format, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%c format_c %c format_c %c format_c %c format_c %c";
//   int a = -5;
//   int b = -7;
//   int c = -15;
//   int d = -55;
//   int e = -94;
//   ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
//                    s21_sprintf(str2, format, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%c format_c %c format_c %c format_c %c format_c %c";
//   int a = 40;
//   int b = 55;
//   int c = 1855;
//   int d = 245;
//   int e = 142;
//   ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
//                    s21_sprintf(str2, format, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%c format_c %c format_c %c format_c %c format_c %c";
//   int a = 40;
//   int b = 55;
//   int c = 1855;
//   int d = 245;
//   int e = 142;
//   ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
//                    s21_sprintf(str2, format, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%c format_c %c format_c %c format_c %c format_c %c";
//   char a = 0;
//   ck_assert_int_eq(sprintf(str1, format, a, a, a, a, a),
//                    s21_sprintf(str2, format, a, a, a, a, a));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%05c format_c % 5c format_c %lc format_c";
//   int a = 45;
//   unsigned long int b = 45;
//   ck_assert_int_eq(sprintf(str1, format, a, a, b),
//                    s21_sprintf(str2, format, a, a, b));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_c) {
//   char str1[100];
//   char str2[100];
//   char *format = "%-010c format_c % -10c format_c %-lc";
//   int a = 98;
//   unsigned long int b = 98;
//   ck_assert_int_eq(sprintf(str1, format, a, a, b),
//                    s21_sprintf(str2, format, a, a, b));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_c) {
//   char str1[100];
//   char str2[100];
//   char *format =
//       "%+010.5c format_c % +10.5c format_c %-10lc format_c %-10lc format_c "
//       "%+10lc";
//   char a = 12;
//   unsigned long int b = 12;
//   unsigned long int c = 12;
//   ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
//                    s21_sprintf(str2, format, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_c) {
//   char str1[100];
//   char str2[100];
//   char *format =
//       "%6.4c format_c %-6.4c format_c %4.10lc format_c %-4.10lc format_c %-0lc";
//   int a = 30;
//   unsigned long int b = 30;
//   unsigned long int c = 30;
//   ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
//                    s21_sprintf(str2, format, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_c) {
//   char str1[100];
//   char str2[100];
//   char *format =
//       "%10c format_c %-6.4c format_c %10.10lc format_c %-4.10lc format_c %-0lc";
//   int a = 30;
//   unsigned long int b = 30;
//   unsigned long int c = 30;
//   ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
//                    s21_sprintf(str2, format, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_d-----///////////////////

// START_TEST(sprintf_1_signed) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format d %d format d";
//   int val = -54;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_signed) {
//   char str1[100];
//   char str2[100];
//   char *format = "%d format d %d format d %d";
//   int val = 784;
//   int val2 = -154;
//   int val3 = 598;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_signed) {
//   char str1[100];
//   char str2[100];
//   char *format = "%d format d %d format d %d";
//   int val = 875;
//   int val2 = 87;
//   int val3 = 63;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_signed) {
//   char str1[100];
//   char str2[100];
//   char *format = "%ld format d %ld format d %hd GOD %hd";
//   long int val = 72;
//   long val2 = 732578278272;
//   short int val3 = 36;
//   short val4 = -287;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_signed) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3d format d %5d format d %10d";
//   int val = -6752;
//   int val2 = -6987;
//   int val3 = -57;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_signed) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5d format d %.23d format d %3.d format d %.d %.6d";
//   int val = -58875;
//   int val2 = -58;
//   int val3 = -75;
//   int val4 = -69;
//   int val5 = -7;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_signed) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5d format d %-.8d format d %-7d format d %-.d";
//   int val = -86;
//   int val2 = -58;
//   int val3 = -78;
//   int val4 = -85;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_signed) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0d format d %0.d format d %0.0d format d %0d GOD %.d";
//   int val = -8;
//   int val2 = -58;
//   int val3 = -7;
//   int val4 = -58;
//   int val5 = -75;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_signed) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+d format d %+3.d format d %+5.7d format d %+10d";
//   int val = -69;
//   int val2 = -785;
//   int val3 = -6;
//   int val4 = -785;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_signed) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-d format d %+3.d format d %+5.7d format d %10d";
//   int val = -69;
//   int val2 = -785;
//   int val3 = -6;
//   int val4 = -785;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_g-----///////////////////

// START_TEST(sprintf_1_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%g format g %.g format g %3g format g %2.g format g %4.20g!";
//   double num = 41.464;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// // START_TEST(sprintf_2_g) {
// //   char str1[200];
// //   char str2[200];
// //   char *format = "%g format g %.g format g %2g format g %2.g format g
// //   %2.50g!"; double num = -1478.59595; ck_assert_int_eq(sprintf(str1, format,
// //   num, num, num, num, num),
// //                    s21_sprintf(str2, format, num, num, num, num, num));
// //   ck_assert_pstr_eq(str1, str2);
// // }
// // END_TEST

// START_TEST(sprintf_3_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%14.21g format g\n%.8g format g\n";
//   double num = 78.46255;
//   double num1 = 155.87874;
//   ck_assert_int_eq(sprintf(str1, format, num, num1),
//                    s21_sprintf(str2, format, num, num1));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%.2g format g\n%.5g format g\n";
//   double num = 784.466881;
//   double num1 = 744.745;
//   ck_assert_int_eq(sprintf(str1, format, num, num1),
//                    s21_sprintf(str2, format, num, num1));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%g format g %.g format g %4g format g %4.g format g %#5.10g!";
//   double num = 2.48465684468;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%g format g %.g format g %4g format g %4.g format g %#5.10g!";
//   double num = -0.0000756589367;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%g format g %.g format g %4g format g %4.g format g %5.10g!";
//   double num = 573429.56589367;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_g) {
//   char str1[200];
//   char str2[200];
//   char *format =
//       "%g format g %.0g format g %2.2g format g %4.g format g %6.10g!";
//   double num = -486.7984846544;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "format g: %15.1g\nformat g: %16.2g\nformat g: %18.3g!";
//   double num = -4788744.798556484684;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// ///////////////////-----sprintf_cpec_e-----///////////////////

// START_TEST(sprintf_1_e) {
//   char str1[100];
//   char str2[100];
//   char *format = "%e format e %5e format e %5.e";
//   double num = -5656856565.;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_e) {
//   char str1[100];
//   char str2[100];
//   char *format = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
//   double num = -8998848488.;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_e) {
//   char str1[100];
//   char str2[100];
//   char *format = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
//   double num = -6115454568.;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %020e\n format e: %020.e!";
//   double num = -9879849846484.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %010e\n format e: %010.e!";
//   double num = -488948459548589.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %0.0e!";
//   double num = -79844848484848.;
//   ck_assert_int_eq(sprintf(str1, format, num), s21_sprintf(str2, format, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %020e\nformat e: %020.e!";
//   double num = -4655645484787887888888887878874848484848488484858585858959.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %010e\n format e: %010.e\nformat e: %0.0e!";
//   double num = -744848484845853444444444477777.;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %020e format e: %020.5e!";
//   double num = -78787888888888888999999999555.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %0+10.7e format e: %- 10.7e";
//   double num = -78787888888888888999999999555.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_11_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %0+1.7e format e: %- 5.7e";
//   double num = -78787888888888888999999999555.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_12_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %0+20.5e format e: %- 020.5e!";
//   double num = -78787888888888888999999999555.;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_13_e) {
//   char str1[300];
//   char str2[300];
//   char *format = "format e: %-0+20.5e format e: % 020.5e!";
//   double num = -8999999555.415214521;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ///////////////////-----sprintf_cpec_f-----///////////////////

// START_TEST(sprintf_1_f) {
//   char str1[200];
//   char str2[200];
//   char *format = "%f format f %.f format f %4f format f %4.f format f %5.10f!";
//   double num = 8785.464651564541;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_f) {
//   char str1[200];
//   char str2[200];
//   char *format = "%f format f %.f format f %3f format f %4.f format f %5.10f!";
//   double num = -87.4668948948498;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "%Lf\n%.Lf!";
//   long double num_long = -45454.388282828;
//   ck_assert_int_eq(sprintf(str1, format, num_long, num_long),
//                    s21_sprintf(str2, format, num_long, num_long));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "%20.10f\n%20.15f\n%-20.5f!";
//   double num = -654.485;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
//   long double num = 7895.589598;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %5f\nformat f: %6.1f\nformat f: %8.2f!";
//   double num = 545.65856;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %10.5f\nformat f: %12.4f!";
//   double num = 98956.5959;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %15.1f\nformat f: %16.2f\nformat f: %18.3f!";
//   double num = -5958656.396959;
//   ck_assert_int_eq(sprintf(str1, format, num, num, num),
//                    s21_sprintf(str2, format, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %10.4f\nformat f: %25.5f!";
//   double num = -989598.154854;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %f\nformat f: %f!";
//   float num = 1.15485744;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_11_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %f\nformat f: %f!";
//   float num = 2.1544004;
//   ck_assert_int_eq(sprintf(str1, format, num, num),
//                    s21_sprintf(str2, format, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_12_f) {
//   char str1[400];
//   char str2[400];
//   char *format = "format f: %*f\nformat f: %*.*f";
//   int width1 = 5;
//   int width2 = 7;
//   int accuracy = 5;
//   double num1 = -989598.154854, num2 = 38748383;
//   ck_assert_int_eq(
//       sprintf(str1, format, width1, num1, width2, accuracy, num2),
//       s21_sprintf(str2, format, width1, num1, width2, accuracy, num2));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_x-----///////////////////

// START_TEST(sprintf_1_hex) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format x %x format x";
//   int val = 0x54;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_hex) {
//   char str1[100];
//   char str2[100];
//   char *format = "%x format x %x format x %x";
//   int val = 0x784;
//   int val2 = 0xab5f;
//   int val3 = 0x3a5f1;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_hex) {
//   char str1[100];
//   char str2[100];
//   char *format = "%x format x %x format x %x";
//   int val = 0x3a5f;
//   int val2 = 0x71982;
//   int val3 = 0x93a9;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_hex) {
//   char str1[100];
//   char str2[100];
//   char *format = "%lx format x %lx format x %hx GOD %hx";
//   long int val = 56565848428;
//   long val2 = 8748448485;
//   unsigned short int val3 = 2959;
//   unsigned short val4 = 989;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_hex) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3x format x %5x format x %10x";
//   int val = 4841;
//   int val2 = 595;
//   int val3 = 895499;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_hex) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5x format x %.23x format x %3.x format x %.x";
//   int val = 11265;
//   int val2 = 5959;
//   int val3 = 575;
//   int val4 = 58757;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_hex) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5x format x %-.8x format x %-7x format x %-.x";
//   int val = 587;
//   int val2 = 757;
//   int val3 = 747;
//   int val4 = 29358589;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_hex) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0x format x %0.x format x %0.0x format x %0x GOD %.x";
//   int val = 747;
//   int val2 = 58;
//   int val3 = 747;
//   int val4 = 47;
//   int val5 = 58;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_hex) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+x format x %+3.x format x %+5.7x format x %+10x";
//   int val = 47417;
//   int val2 = 588;
//   int val3 = 747;
//   int val4 = 588;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_hex) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+x format x %+3.x format x %+5.7x format x %+10x";
//   int val = 0xabc;
//   int val2 = 0xfab;
//   int val3 = 0xabc;
//   int val4 = 0xfab;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_X-----////////////////

// START_TEST(sprintf_1_HEX) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format X %X format X";
//   int val = 0X124;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_HEX) {
//   char str1[100];
//   char str2[100];
//   char *format = "%X format X %X format X %X";
//   int val = 0Xa85;
//   int val2 = 0X4aff;
//   int val3 = 0X356f45;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_HEX) {
//   char str1[100];
//   char str2[100];
//   char *format = "%X format X %X format X %X";
//   int val = 0X78fd;
//   int val2 = 0Xabcd;
//   int val3 = 0Xabcd;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_HEX) {
//   char str1[100];
//   char str2[100];
//   char *format = "%lX format X %lX format X %hX GOD %hX";
//   unsigned long int val = 948949848949848;
//   unsigned long int val2 = 5959595;
//   unsigned short int val3 = 878;
//   unsigned short val4 = 45;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_HEX) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3X format X %5X format X %10X";
//   int val = 8899798;
//   int val2 = 654884848;
//   int val3 = 895929595;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_HEX) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5X format X %.23X format X %3.X format X %.X";
//   int val = 122215;
//   int val2 = 98998;
//   int val3 = 8998;
//   int val4 = 7788;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_HEX) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5X format X %-.8X format X %-7X format X %-.X";
//   int val = 2872;
//   int val2 = 47887;
//   int val3 = 585;
//   int val4 = 29757839;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_HEX) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0X format X %0.X format X %0.0X format X %0X GOD %.X";
//   int val = 2828;
//   int val2 = 28727;
//   int val3 = 77887;
//   int val4 = 44455;
//   int val5 = 78798783;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_HEX) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+X format X %+3.X format X %+5.7X format X %+10X";
//   int val = 78;
//   int val2 = 85585;
//   int val3 = 788;
//   int val4 = 454;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_10_HEX) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+X format X %+3.X format X %+5.7X format X %+10X";
//   int val = 0Xabc;
//   int val2 = 0xfab;
//   int val3 = 0xfab;
//   int val4 = 0xfab;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_i-----////////////////

// START_TEST(sprintf_1_signed_i) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format i %d format i";
//   int val = -1727722;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_signed_i) {
//   char str1[100];
//   char str2[100];
//   char *format = "%d format i %d format i %d";
//   int val = 01123;
//   int val2 = -07217;
//   int val3 = 077242764;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_signed_i) {
//   char str1[100];
//   char str2[100];
//   char *format = "%i format i %i format i %i";
//   int val = 112121;
//   int val2 = 1313;
//   int val3 = 1211541;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_signed_i) {
//   char str1[100];
//   char str2[100];
//   char *format = "%li format i %li format i %hi GOD %hi";
//   long int val = 121313213211;
//   signed long val2 = -13121;
//   short int val3 = -798;
//   short val4 = 46546;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_signed_i) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3i format i %5i format i %10i";
//   int val = -12123;
//   int val2 = -464658;
//   int val3 = -7987897;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_signed_i) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5i format i %.23i format i %3.i format i %.i";
//   int val = -15468;
//   int val2 = -1564848;
//   int val3 = -145;
//   int val4 = -55656;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_signed_i) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5i format i %-.8i format i %-7i format i %-.i";
//   int val = -46445;
//   int val2 = -78798;
//   int val3 = -13215;
//   int val4 = -8978;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_signed_i) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0i format i %0.i format i %0.0i format i %0i GOD %.i";
//   int val = -123134;
//   int val2 = -7987;
//   int val3 = -98784;
//   int val4 = -155;
//   int val5 = -0000155;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_signed_i) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+i format i %+3.i format i %+5.7i format i %+10i";
//   int val = -54564;
//   int val2 = -4774;
//   int val3 = -858;
//   int val4 = -7587;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_n-----////////////////

// START_TEST(sprintf_1_n) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format n %n format n";
//   int valn1 = 0, valn2 = 0;
//   ck_assert_int_eq(sprintf(str1, format, &valn1),
//                    s21_sprintf(str2, format, &valn2));
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(valn1, valn2);
// }
// END_TEST

// START_TEST(sprintf_2_n) {
//   char str1[100];
//   char str2[100];
//   char *format = "format n %o %n format n %o%n";
//   int val = 524;
//   int val2 = 2524;
//   int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
//   ck_assert_int_eq(sprintf(str1, format, val, &valn1, val2, &valn3),
//                    s21_sprintf(str2, format, val, &valn2, val2, &valn4));
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(valn1, valn2);
//   ck_assert_int_eq(valn3, valn4);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_o-----////////////////

// START_TEST(sprintf_1_octal) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format o %o format o";
//   int val = 224;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_octal) {
//   char str1[100];
//   char str2[100];
//   char *format = "%o format o %o format o %o";
//   int val = 42;
//   int val2 = 572;
//   int val3 = 07277425464;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_octal) {
//   char str1[100];
//   char str2[100];
//   char *format = "%o format o %o format o %o";
//   int val = 72;
//   int val2 = 274;
//   int val3 = 727;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_octal) {
//   char str1[100];
//   char str2[100];
//   char *format = "%lo format o %lo format o %ho GOD %ho";
//   long int val = 272727272;
//   unsigned long int val2 = 757;
//   unsigned short int val3 = 872;
//   unsigned short val4 = 752;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_octal) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3o format o %5o format o %10o";
//   int val = 5875;
//   int val2 = 785;
//   int val3 = 7578;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_octal) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5o format o %.23o format o %3.o format o %.o";
//   int val = 785;
//   int val2 = 78;
//   int val3 = 87;
//   int val4 = 785;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_octal) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5o format o %-.8o format o %-7o format o %-.o";
//   int val = 3015;
//   int val2 = 712;
//   int val3 = 99;
//   int val4 = 2939;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_octal) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0o format o %0.o format o %0.0o format o %0o GOD %.o";
//   int val = 42;
//   int val2 = 782;
//   int val3 = 382;
//   int val4 = 29727839;
//   int val5 = 782;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_octal) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+o format o %+3.o format o %+5.7o format o %+10o";
//   int val = 7825;
//   int val2 = 387;
//   int val3 = 788;
//   int val4 = 782;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_percent-----////////////////

// START_TEST(sprintf_1_percent) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "%%format per %o format per";
//   int val = 452;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_percent) {
//   char str1[100];
//   char str2[100];
//   char *format = "format per %o per%%%%per %o";
//   int val = 53;
//   int val2 = 5254;
//   ck_assert_int_eq(sprintf(str1, format, val, val2),
//                    s21_sprintf(str2, format, val, val2));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_percent) {
//   char str1[100];
//   char str2[100];
//   char *format = "%o per%%per %o format per %o";
//   int val = 452;
//   int val2 = 42;
//   int val3 = 36;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_p-----////////////////

// START_TEST(sprintf_1_pointer) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format p %p format p";
//   char *val = "25";
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_pointer) {
//   char str1[100];
//   char str2[100];
//   char *format = "%p format p %p format p %p";
//   char *val = "42";
//   char *val2 = "45245";
//   char *val3 = "0p31224523";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_pointer) {
//   char str1[100];
//   char str2[100];
//   char *format = "%p format p %p format p %p";
//   char *val = "425";
//   char *val2 = "452";
//   char *val3 = "452";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_pointer) {
//   char str1[100];
//   char str2[100];
//   char *format = "%p format p %p format p %p  %p";
//   long int *val = (void *)3088675747373646;
//   long long int *val2 = (void *)33030030303;
//   unsigned short int *val3 = (void *)22600;
//   unsigned char *val4 = (void *)120;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_pointer) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3p format p %5p format p %12p";
//   char *val = "17174";
//   char *val2 = "2572";
//   char *val3 = "36838";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_pointer) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5p format p %.23p format p %3.p format p %.p";
//   char *val = "72178";
//   char *val2 = "8725";
//   char *val3 = "857";
//   char *val4 = "7858";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_pointer) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5p format p %-.4p format p %-16p format p %-.5p";
//   char *val = "3015";
//   char *val2 = "712";
//   char *val3 = "99";
//   char *val4 = "2939";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_pointer) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0p format p %0.p format p %0.0p format p %0p  %.p";
//   char *val = "78578";
//   char *val2 = "278287";
//   char *val3 = "785";
//   char *val4 = "78528";
//   char *val5 = "24";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_pointer) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+p format p %+3.p format p %+5.7p format p %+10p";
//   char *val = "785";
//   char *val2 = "785";
//   char *val3 = "99785";
//   char *val4 = "757";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_s-----////////////////

// START_TEST(sprintf_1_string) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format s %s format s";
//   char *val = "ck_assert_pstr_eq(str1, str2);";
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%s %s %s";
//   char *val = " in this language i";
//   char *val2 = "equence of actions";
//   char *val3 = " described in this langua";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_string) {
//   char str1[100];
//   char str2[100];
//   char *format = "%s %s %s";
//   char *val = "you said to the ";
//   char *val2 = "you said to the thoughtful";
//   char *val3 = "you said to the ";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%3s s %5s s %10s";
//   char *val = "WHAT IS THIS";
//   char *val2 = "i don't care anymore";
//   char *val3 = "PPAP";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5s s %.23s  s %3.s s %.s";
//   char *val =
//       "After a few seconds, Turing came to a logical conclusion to entrust the "
//       "job to you";
//   char *val2 = " logical conclusion to entrust the job to you";
//   char *val3 = " the job to you";
//   char *val4 = " good";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5s  s %-.8s  s %-7s  s %-.s";
//   char *val =
//       "In this project you will develop your own implementation of the "
//       "string.h";
//   char *val2 = " your own implementation of the string.hy";
//   char *val3 = " of the string.h";
//   char *val4 = "In this project you will develop you";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0s  s %0.s  s %0.0s  s %0s  %.s";
//   char *val =
//       "In this project you will develop your own implementation of the "
//       "string.h";
//   char *val2 = "i don't care anymore, really";
//   char *val3 =
//       "InIn this project you will develop your own implementatmplementation of "
//       "the string.h";
//   char *val4 =
//       "vIn this project you will develop your own implementation of the "
//       "string.h";
//   char *val5 = "v!";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_string) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+s  s %+3.s  s %5.7s  s %10s";
//   char *val =
//       "The C programming language has a set of functions implementing "
//       "operations on strings";
//   char *val2 = " a set of functions implementing operations on strings";
//   char *val3 =
//       " language has a set of functions implementing operations on strings";
//   char *val4 = " operations on strings";
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// ////////////////////-----sprintf_cpec_u-----////////////////

// START_TEST(sprintf_1_unsigned) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *format = "format u %u format u";
//   unsigned int val = 012;
//   ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_2_unsigned) {
//   char str1[100];
//   char str2[100];
//   char *format = "%u format u %u format u %u";
//   unsigned int val = 5857;
//   unsigned int val2 = 05000;
//   unsigned int val3 = 07464;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_3_unsigned) {
//   char str1[100];
//   char str2[100];
//   char *format = "%u format u %u format u %u";
//   unsigned int val = 785;
//   unsigned int val2 = 75587;
//   unsigned int val3 = 7587;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_4_unsigned) {
//   char str1[100];
//   char str2[100];
//   char *format = "%lu format u %lu format u %hu GOD %hu";
//   long unsigned int val = 96969;
//   long unsigned val2 = 5885;
//   unsigned short val3 = 8657;
//   unsigned short val4 = 699;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_5_unsigned) {
//   char str1[100];
//   char str2[100];
//   char *format = "%3u format u %5u format u %10u";
//   unsigned int val = 58757;
//   unsigned int val2 = 69685;
//   unsigned int val3 = 785857;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
//                    s21_sprintf(str2, format, val, val2, val3));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_6_unsigned) {
//   char str1[200];
//   char str2[200];
//   char *format = "%6.5u format u %.23u format u %3.u format u %.u";
//   unsigned int val = 69858;
//   unsigned int val2 = 78578;
//   unsigned int val3 = 69875;
//   unsigned int val4 = 9867;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_7_unsigned) {
//   char str1[200];
//   char str2[200];
//   char *format = "%-10.5u format u %-.8u format u %-7u format u %-.u";
//   unsigned int val = 698685;
//   unsigned int val2 = 7578;
//   unsigned int val3 = 687985;
//   unsigned int val4 = 987;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_8_unsigned) {
//   char str1[200];
//   char str2[200];
//   char *format = "%0u format u %0.u format u %0.0u format u %0u qwe %.u";
//   unsigned int val = 5785;
//   unsigned int val2 = 6987;
//   unsigned int val3 = 6978;
//   unsigned int val4 = 6978;
//   unsigned int val5 = 96878;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
//                    s21_sprintf(str2, format, val, val2, val3, val4, val5));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_9_unsigned) {
//   char str1[200];
//   char str2[200];
//   char *format = "%+u format u %+3.u format u %+5.7u format u %+10u";
//   unsigned int val = 697;
//   unsigned int val2 = 9678;
//   unsigned int val3 = 6987;
//   unsigned int val4 = 785878;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

////////////////////////// ----- sscanf ------ /////////////////////

//////////////////---------sscanf_spec_c----------//////////////////

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_c_9) {
  char format[] = "%1c";
  char str[] = " Ulustbeger\n  \t";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_10) {
  char format[] = "%1c";
  char str[] = "ACFZJAAgergzdrgr";
  char c1 = 'x', c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

//////////////////---------sscanf_spec_d----------//////////////////

START_TEST(sscanf_spec_hhd) {
  char formats[][1024] = {"%hhd",  "%1hhd",  "%2hhd",  "%3hhd",
                          "%4hhd", "%10hhd", "%12hhd", "%*hhd"};
  char str[][1024] = {"123",
                      "-521",
                      "+213",
                      "4532569",
                      "+85448",
                      "-58574366417",
                      "9532135230155035",
                      "-96520142145056056500",
                      "+87485216589225898286"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      signed char d1, d2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_hd) {
  char formats[][1024] = {"%hd",  "%1hd",  "%2hd",  "%3hd",
                          "%4hd", "%10hd", "%12hd", "%*hd"};
  char str[][1024] = {"123",
                      "-521",
                      "+213",
                      "4532569",
                      "+85448",
                      "-58574366417",
                      "9532135230155035",
                      "-96520142145056056500",
                      "+87485216589225898286"};

  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      short d1, d2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_d) {
  char formats[][1024] = {"%d",  "%1d",  "%2d",  "%3d",
                          "%4d", "%10d", "%12d", "%*d"};
  char str[][1024] = {"123",
                      "-521",
                      "+213",
                      "4532569",
                      "+85448",
                      "-58574366417",
                      "9532135230155035",
                      "-96520142145056056500",
                      "+87485216589225898286"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      int d1, d2;
      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_ld) {
  char formats[][1024] = {"%ld",  "%1ld",  "%2ld",  "%3ld",
                          "%4ld", "%10ld", "%12ld", "%*ld"};
  char str[][1024] = {"123",
                      "-521",
                      "+213",
                      "4532569",
                      "+85448",
                      "-58574366417",
                      "9532135230155035",
                      "-96520142145056056500",
                      "+87485216589225898286"};

  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      long int d1, d2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_lld) {
  char formats[][1024] = {"%lld",  "%1lld",  "%2lld",  "%3lld",
                          "%4lld", "%10lld", "%12lld", "%*lld"};
  char str[][1024] = {"123",
                      "-521",
                      "+213",
                      "4532569",
                      "+85448",
                      "-58574366417",
                      "9532135230155035",
                      "-96520142145056056500",
                      "+87485216589225898286"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      long long int d1, d2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_2d) {
  char formats[][1024] = {"%*d %d", "%*d %5d", "%2d %*d", "%*d %9d",
                          "%*d%2d", "%10d%*d", "%12d%*d", "%*d%d"};
  char str[][1024] = {"123 \n \t 98654",
                      "-521 8456",
                      "+213\n\t+8474",
                      "4532569 466",
                      "+85448\n\t   \t51\t",
                      "-58574366417  hng\n",
                      "\n\t9532135230155035  15",
                      "\t-96520142145056056500  \n 85",
                      "\t\n+87485216589225898286 674"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      int d1, d2;
      int16_t res1 = s21_sscanf(str[j], formats[i], &d1);
      int16_t res2 = sscanf(str[j], formats[i], &d2);
      ck_assert_int_eq(res1, res2);
      ck_assert_int_eq(d1, d2);
    }
  }
}
END_TEST

//////////////////---------sscanf_spec_empty----------//////////////////

START_TEST(sscanf_empty) {
  char formats[][1024] = {"%d", "", "\t%d"};
  char str[][1024] = {"",         "     ",    "\t",        "\n", "   \t\n\\n\t",
                      "\t\n\t\n", "\\\n    ", "\n  \t \t", " "};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      int p1, p2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &p1);
      int16_t res2 = sscanf(str[j], formats[i], &p2);
      ck_assert_int_eq(res1, res2);
    }
  }
}
END_TEST

//////////////////---------sscanf_spec_i----------//////////////////

START_TEST(sscanf_spec_hhi_3parametra) {
  char formats[][1024] = {"%hhi%hhi%hhi",       "%hhi %hhi %hhi",
                          "%1hhi %3hhi %15hhi", "%hhi %4hhi %9hhi",
                          "%12hhi %7hhi %3hhi", "%2hhi %2hhi %1hhi",
                          "%3hhi %1hhi %4hhi",  "%80hhi %19hhi %21hhi"};
  char str[][1024] = {"123 +198 -87",    "15 8 9",
                      "+5 +40 +80",      "-4 -351 -800",
                      "29 -857 +495",    "0123 +0198 -087",
                      "013 +0137 -08",   "0x11 +0x1357 -0x5",
                      "0x12 +0x1a -0x8f"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned char d1, d2;
      unsigned char q1, q2;
      unsigned char z1, z2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_hhi_4parametra) {
  char formats[][1024] = {
      "%hhi %hhi %hhi %hhi",
      "%hhi%hhi%hhi%hhi",
      "%1hhi %1hhi %1hhi %1hhi",
      "%2hhi %3hhi %9hhi %1hhi",
  };
  char str[][1024] = {
      "2147483647 +2147483648 -2147483648 -2147483649",
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809",
      "037777755557 +0400000500000 -040000000000 -040000000001",
      "017775555555777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001",
      "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa",
      "0xFFFFFFFFFFFfffffFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328",
      "74523568412ffff 5845a 4745243affa 475fd77d75"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned char d1, d2;
      unsigned char q1, q2;
      unsigned char z1, z2;
      unsigned char w1, w2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1, &w1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2, &w2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
      ck_assert_uint_eq(w1, w2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_hi_4parametra) {
  char formats[][1024] = {
      "%hhi %hhi %hhi %hhi",
      "%hhi%hhi%hhi%hhi",
      "%1hhi %1hhi %1hhi %1hhi",
      "%2hhi %3hhi %9hhi %1hhi",
  };
  char str[][1024] = {
      "2147483647 +2147483648 -2147483648 -2147483649",
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809",
      "037777755557 +0400000500000 -040000000000 -040000000001",
      "017775555555777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001",
      "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa",
      "0xFFFFFFFFFFFfffffFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328",
      "74523568412ffff 5845a 4745243affa 475fd77d75"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned short d1, d2;
      unsigned short q1, q2;
      unsigned short z1, z2;
      unsigned short w1, w2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1, &w1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2, &w2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
      ck_assert_uint_eq(w1, w2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_i_3parametra) {
  char formats[][1024] = {"%i%i%i",        "%i %i %i",    "%1i %1i %1i",
                          "%21i %15i %7i", "%2i %3i %4i", "%18i %3i %2i",
                          "%19i %46i %i",  "%9i %17i %5i"};
  char str[][1024] = {"123 +198 -87",    "15 8 9",
                      "+5 +40 +80",      "-4 -351 -800",
                      "29 -857 +495",    "0123 +0198 -087",
                      "013 +0137 -08",   "0x11 +0x1357 -0x5",
                      "0x12 +0x1a -0x8f"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned int d1, d2;
      unsigned int q1, q2;
      unsigned int z1, z2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_i_4parametra) {
  char formats[][1024] = {"%i%i%i%i",         "%i %i %3i %i",
                          "%1i %1i %1i %1i",  "%21i %15i %7i",
                          "%2i %3i %4i %1i",  "%18i %1i %3i %2i",
                          "%19i %1i %46i %i", "%9i %17i %5i %1i"};
  char str[][1024] = {
      "2147483647 +2147483648 -2147483648 -2147483649",
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809",
      "037777755557 +0400000500000 -040000000000 -040000000001",
      "017775555555777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001",
      "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa",
      "0xFFFFFFFFFFFfffffFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328",
      "74523568412ffff 5845a 4745243affa 475fd77d75"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned int d1, d2;
      unsigned int q1, q2;
      unsigned int z1, z2;
      unsigned int w1, w2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1, &w1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2, &w2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
      ck_assert_uint_eq(w1, w2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_li_3parametra) {
  char formats[][1024] = {"%li%li%li",       "%li %li %li",
                          "%1li %1li %1li",  "%21li %15li %7li",
                          "%2li %3li %4li",  "%18li %3li %2li",
                          "%19li %46li %li", "%9li %17li %5li"};
  char str[][1024] = {"123 +198 -87",    "15 8 9",
                      "+5 +40 +80",      "-4 -351 -800",
                      "29 -857 +495",    "0123 +0198 -087",
                      "013 +0137 -08",   "0x11 +0x1357 -0x5",
                      "0x12 +0x1a -0x8f"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned long int d1, d2;
      unsigned long int q1, q2;
      unsigned long int z1, z2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_lli_3parametra) {
  char formats[][1024] = {"%lli%lli%lli",       "%lli %lli %lli",
                          "%1lli %1lli %1lli",  "%21lli %15lli %7lli",
                          "%2lli %3lli %4lli",  "%18lli %3lli %2lli",
                          "%19lli %46lli %lli", "%9lli %17lli %5lli"};
  char str[][1024] = {"123 +198 -87",    "15 8 9",
                      "+5 +40 +80",      "-4 -351 -800",
                      "29 -857 +495",    "0123 +0198 -087",
                      "013 +0137 -08",   "0x11 +0x1357 -0x5",
                      "0x12 +0x1a -0x8f"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned long long int d1, d2;
      unsigned long long int q1, q2;
      unsigned long long int z1, z2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_lli_4parametra) {
  char formats[][1024] = {"%li%li%li%li",         "%li %li %3li %li",
                          "%1li %1li %1li %1li",  "%21li %15li %7li",
                          "%2li %3li %4li %1li",  "%18li %1li %3li %2li",
                          "%19li %1li %46li %li", "%9li %17li %5li %1li"};
  char str[][1024] = {
      "2147483647 +2147483648 -2147483648 -2147483649",
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809",
      "037777755557 +0400000500000 -040000000000 -040000000001",
      "017775555555777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001",
      "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa",
      "0xFFFFFFFFFFFfffffFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328",
      "74523568412ffff 5845a 4745243affa 475fd77d75"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned long long int d1, d2;
      unsigned long long int q1, q2;
      unsigned long long int z1, z2;
      unsigned long long int w1, w2;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1, &w1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2, &w2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
      ck_assert_uint_eq(w1, w2);
    }
  }
}
END_TEST

//////////////////---------sscanf_spec_n----------//////////////////

START_TEST(sscanf_n_1) {
  char format[] = "%n";
  char str[] = "qwertyuiop";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_2) {
  char format[] = "%d %n";
  char str[] = "irilethj";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_4) {
  char format[] = "Hello %n ";
  char str[] = "Hello";
  int *n1 = 0, *n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_5) {
  char format[] = "%d %hn %d %hhn %d %d %hhn %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  short hn1 = 0, hn2 = 0;
  unsigned char hhn1 = 0, hhn2 = 0;
  unsigned char n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_n_6) {
  char format[] = "%d %ln %d %lln %d %d %lln %d";
  char str[] = "3263 225 724 38 482";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  long int hn1 = 0, hn2 = 0;
  long long int hhn1 = 0, hhn2 = 0;
  long long int n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_n_7) {
  char format[] = "%%%c";
  char str[] = "%p";
  char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_n_8) {
  char format[] = "%lf %lf %lf %lf %n %lf";
  char str[] = ".0 66.34 9877.66 1.99 0.999";
  long double d1 = 0, d2 = 0;
  long double dd1 = 0, dd2 = 0;
  long double f1 = 0, f2 = 0;
  long double ff1 = 0, ff2 = 0;
  long double k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &n1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &n2, &k2);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_ldouble_eq(dd1, dd2);
  ck_assert_ldouble_eq(f1, f2);
  ck_assert_ldouble_eq(ff1, ff2);
  ck_assert_ldouble_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n_9) {
  char format[] = "%s %s";
  char str[] = "hi \t\n";
  char s1[20], s2[20] = {0}, s3[20], s4[20] = {0};

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

//////////////////---------sscanf_spec_o----------//////////////////

START_TEST(sscanf_spec_hho) {
  char formats[][1024] = {"%hho%hho%hho", "%1hho %1hho %1hho",
                          "%2hho %2hho %2hho", "%*hho %*hho %*hho",
                          "%*hho %3hho %5hho"};
  char str[][1024] = {"123 +198 -87", "15 8 9",       "+5 +40 +80",
                      "-4 -351 -800", "29 -857 +495", "0123 +0198 -087",
                      "013 +0137 -08"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned char d1, d2;
      unsigned char q1, q2;
      unsigned char z1 = 0, z2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_ho) {
  char formats[][1024] = {"%ho%ho%ho", "%1ho %1ho %1ho", "%2ho %2ho %2ho",
                          "%*ho %*ho %*ho", "%*ho %3ho %5ho"};
  char str[][1024] = {"123 +198 -87", "15 8 9",       "+5 +40 +80",
                      "-4 -351 -800", "29 -857 +495", "0123 +0198 -087",
                      "013 +0137 -08"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned short d1, d2;
      unsigned short q1, q2;
      unsigned short z1 = 0, z2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_o) {
  char formats[][1024] = {"%o%o%o", "%1o %1o %1o", "%2o %2o %2o", "%*o %*o %*o",
                          "%*o %3o %5o"};
  char str[][1024] = {"123 +198 -87", "15 8 9",       "+5 +40 +80",
                      "-4 -351 -800", "29 -857 +495", "0123 +0198 -087",
                      "013 +0137 -08"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned int d1, q1, d2, q2;
      unsigned int z1 = 0;
      unsigned int z2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_lo) {
  char formats[][1024] = {"%lo%lo%lo", "%1lo %1lo %1lo", "%2lo %2lo %2lo",
                          "%*lo %*lo %*lo", "%*lo %3lo %5lo"};
  char str[][1024] = {"123 +198 -87", "15 8 9",       "+5 +40 +80",
                      "-4 -351 -800", "29 -857 +495", "0123 +0198 -087",
                      "013 +0137 -08"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned long int d1 = 0, d2 = 0;
      unsigned long int q1 = 0, q2 = 0;
      unsigned long int z1 = 0, z2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

START_TEST(sscanf_spec_llo) {
  char formats[][1024] = {"%llo%llo%llo", "%1llo %1llo %1llo",
                          "%2llo %2llo %2llo", "%*llo %*llo %*llo",
                          "%*llo %3llo %5llo"};
  char str[][1024] = {"123 +198 -87", "15 8 9",       "+5 +40 +80",
                      "-4 -351 -800", "29 -857 +495", "0123 +0198 -087",
                      "013 +0137 -08"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      unsigned long long int d1, d2;
      unsigned long long int q1, q2;
      unsigned long long int z1 = 0, z2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &d1, &q1, &z1);
      int16_t res2 = sscanf(str[j], formats[i], &d2, &q2, &z2);
      ck_assert_int_eq(res1, res2);
      ck_assert_uint_eq(d1, d2);
      ck_assert_uint_eq(q1, q2);
      ck_assert_uint_eq(z1, z2);
    }
  }
}
END_TEST

//////////////////---------sscanf_spec_p----------//////////////////

START_TEST(sscanf_spec_p) {
  char formats[][1024] = {"%p", "%5p", "%10p", "%7p"};
  char str[][1024] = {"0x0000",        "0xAAAA",           "0xA2361598",
                      "0x34567hjk678", "1234567890ABCDEF", "0x343267hjk678",
                      "0x345ggfhjk348"};
  for (size_t i = 0; i < (sizeof(formats) / sizeof(*formats)); i++) {
    for (size_t j = 0; j < (sizeof(str) / sizeof(*str)); j++) {
      int *p1 = 0, *p2 = 0;

      int16_t res1 = s21_sscanf(str[j], formats[i], &p1);
      int16_t res2 = sscanf(str[j], formats[i], &p2);
      ck_assert_int_eq(res1, res2);
      ck_assert_ptr_eq(p1, p2);
    }
  }
}
END_TEST

//////////////////---------sscanf_real----------//////////////////

START_TEST(sscanf_real_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_real_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_real_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_real_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_real_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_real_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_real_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_real_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

//////////////////---------sscanf_spec_x----------//////////////////

START_TEST(sscanf_x_1) {
  char format[] = "%hhx%hhx%hhx";
  char str[] = "123 +198 -87";
  unsigned char d1, d2;
  unsigned char q1, q2;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_2) {
  char format[] = "%hhx%hhx%hhx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_3) {
  char format[] = "%hhx%hhx";
  char str[] = "0 +0x";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_x_4) {
  char format[] = "%hhx%hhx%hhx";
  char str[] = "0 -0XABC -0X";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_5) {
  char format[] = "%hhx%hhx%hhx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_6) {
  char format[] = "%1hhx %1hhx %1hhx";
  char str[] = "1a +04 -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_7) {
  char format[] = "%1hhx %1hhx %1hhx";
  char str[] = "1a 0x -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_8) {
  char format[] = "%2hhx %2hhx %2hhx";
  char str[] = "1a bc 0x -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_x_9) {
  char format[] = "%2.x %2x %2hhx";
  char str[] = "1a bc 0x -3723";
  unsigned char d1 = 0, d2 = 0;
  unsigned char q1 = 0, q2 = 0;
  unsigned char z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *main_suite(void) {
  Suite *suite = suite_create("String");

  // 1 Добавление тестов в набор
  TCase *tc_memchr = tcase_create("memchr");
  tcase_add_test(tc_memchr, memchr_1);
  tcase_add_test(tc_memchr, memchr_2);
  tcase_add_test(tc_memchr, memchr_3);
  tcase_add_test(tc_memchr, memchr_4);
  tcase_add_test(tc_memchr, memchr_5);
  tcase_add_test(tc_memchr, memchr_6);
  tcase_add_test(tc_memchr, memchr_7);
  tcase_add_test(tc_memchr, memchr_8);
  tcase_add_test(tc_memchr, memchr_9);
  tcase_add_test(tc_memchr, memchr_10);
  suite_add_tcase(suite, tc_memchr);

  // 2 Добавление тестов в набор
  TCase *tc_memcmp = tcase_create("memcmp");
  tcase_add_test(tc_memcmp, memcmp_1);
  tcase_add_test(tc_memcmp, memcmp_2);
  tcase_add_test(tc_memcmp, memcmp_3);
  tcase_add_test(tc_memcmp, memcmp_4);
  tcase_add_test(tc_memcmp, memcmp_5);
  tcase_add_test(tc_memcmp, memcmp_6);
  tcase_add_test(tc_memcmp, memcmp_7);
  tcase_add_test(tc_memcmp, memcmp_8);
  tcase_add_test(tc_memcmp, memcmp_9);
  tcase_add_test(tc_memcmp, memcmp_10);
  tcase_add_test(tc_memcmp, memcmp_11);
  tcase_add_test(tc_memcmp, memcmp_12);
  tcase_add_test(tc_memcmp, memcmp_13);
  tcase_add_test(tc_memcmp, memcmp_14);
  suite_add_tcase(suite, tc_memcmp);

  // 3 Добавление тестов в набор
  TCase *tc_memcpy = tcase_create("memcpy");
  tcase_add_test(tc_memcpy, memcpy_1);
  tcase_add_test(tc_memcpy, memcpy_2);
  tcase_add_test(tc_memcpy, memcpy_3);
  tcase_add_test(tc_memcpy, memcpy_4);
  tcase_add_test(tc_memcpy, memcpy_5);
  tcase_add_test(tc_memcpy, memcpy_6);
  tcase_add_test(tc_memcpy, memcpy_7);
  suite_add_tcase(suite, tc_memcpy);

  // 4 Добавление тестов в набор
  TCase *tc_memset = tcase_create("memset");
  tcase_add_test(tc_memset, memset_1);
  tcase_add_test(tc_memset, memset_2);
  tcase_add_test(tc_memset, memset_3);
  tcase_add_test(tc_memset, memset_4);
  tcase_add_test(tc_memset, memset_5);
  tcase_add_test(tc_memset, memset_6);
  suite_add_tcase(suite, tc_memset);

  // 5 Добавление тестов в набор
  TCase *tc_strncat = tcase_create("strncat");
  tcase_add_test(tc_strncat, strncat_2);
  tcase_add_test(tc_strncat, strncat_3);
  tcase_add_test(tc_strncat, strncat_4);
  tcase_add_test(tc_strncat, strncat_5);
  tcase_add_test(tc_strncat, strncat_6);
  tcase_add_test(tc_strncat, strncat_7);
  tcase_add_test(tc_strncat, strncat_8);
  tcase_add_test(tc_strncat, strncat_9);
  tcase_add_test(tc_strncat, strncat_10);
  tcase_add_test(tc_strncat, strncat_11);
  suite_add_tcase(suite, tc_strncat);

  // 6 Добавление тестов в набор
  TCase *tc_strchr = tcase_create("strchr");
  tcase_add_test(tc_strchr, strchr_1);
  tcase_add_test(tc_strchr, strchr_2);
  tcase_add_test(tc_strchr, strchr_3);
  tcase_add_test(tc_strchr, strchr_4);
  tcase_add_test(tc_strchr, strchr_5);
  tcase_add_test(tc_strchr, strchr_6);
  tcase_add_test(tc_strchr, strchr_7);
  tcase_add_test(tc_strchr, strchr_8);
  suite_add_tcase(suite, tc_strchr);

  // 7 Добавление тестов в набор
  TCase *tc_strncmp = tcase_create("strncmp");
  tcase_add_test(tc_strncmp, strncmp_1);
  tcase_add_test(tc_strncmp, strncmp_2);
  tcase_add_test(tc_strncmp, strncmp_3);
  tcase_add_test(tc_strncmp, strncmp_4);
  tcase_add_test(tc_strncmp, strncmp_5);
  tcase_add_test(tc_strncmp, strncmp_6);
  tcase_add_test(tc_strncmp, strncmp_7);
  tcase_add_test(tc_strncmp, strncmp_8);
  tcase_add_test(tc_strncmp, strncmp_9);
  suite_add_tcase(suite, tc_strncmp);

  // 8 Добавление тестов в набор
  TCase *tc_strncpy = tcase_create("strncpy");
  tcase_add_test(tc_strncpy, strncpy_1);
  tcase_add_test(tc_strncpy, strncpy_2);
  tcase_add_test(tc_strncpy, strncpy_6);
  suite_add_tcase(suite, tc_strncpy);

  // 9 Добавление тестов в набор
  TCase *tc_strcspn = tcase_create("strcspn");
  tcase_add_test(tc_strcspn, strcspn_1);
  tcase_add_test(tc_strcspn, strcspn_2);
  tcase_add_test(tc_strcspn, strcspn_3);
  tcase_add_test(tc_strcspn, strcspn_4);
  tcase_add_test(tc_strcspn, strcspn_5);
  tcase_add_test(tc_strcspn, strcspn_6);
  tcase_add_test(tc_strcspn, strcspn_7);
  tcase_add_test(tc_strcspn, strcspn_8);
  tcase_add_test(tc_strcspn, strcspn_9);
  tcase_add_test(tc_strcspn, strcspn_10);
  tcase_add_test(tc_strcspn, strcspn_11);
  tcase_add_test(tc_strcspn, strcspn_12);
  suite_add_tcase(suite, tc_strcspn);

  // 10 Добавление тестов в набор
  TCase *tc_strerror = tcase_create("strerror");
  tcase_add_test(tc_strerror, strerror_1);
  tcase_add_test(tc_strerror, strerror_2);
  suite_add_tcase(suite, tc_strerror);

  // 11 Добавление тестов в набор
  TCase *tc_strlen = tcase_create("strlen");
  tcase_add_test(tc_strlen, strlen_1);
  tcase_add_test(tc_strlen, strlen_2);
  tcase_add_test(tc_strlen, strlen_3);
  tcase_add_test(tc_strlen, strlen_4);
  tcase_add_test(tc_strlen, strlen_5);
  tcase_add_test(tc_strlen, strlen_6);
  tcase_add_test(tc_strlen, strlen_7);
  tcase_add_test(tc_strlen, strlen_8);
  tcase_add_test(tc_strlen, strlen_9);
  tcase_add_test(tc_strlen, strlen_10);
  tcase_add_test(tc_strlen, strlen_11);
  tcase_add_test(tc_strlen, strlen_12);
  tcase_add_test(tc_strlen, strlen_13);
  tcase_add_test(tc_strlen, strlen_14);
  suite_add_tcase(suite, tc_strlen);

  // 12 Добавление тестов в набор
  TCase *tc_strpbrk = tcase_create("strpbrk");
  tcase_add_test(tc_strpbrk, strpbrk_1);
  tcase_add_test(tc_strpbrk, strpbrk_2);
  tcase_add_test(tc_strpbrk, strpbrk_3);
  tcase_add_test(tc_strpbrk, strpbrk_4);
  tcase_add_test(tc_strpbrk, strpbrk_5);
  tcase_add_test(tc_strpbrk, strpbrk_6);
  suite_add_tcase(suite, tc_strpbrk);

  // 13 Добавление тестов в набор
  TCase *tc_strrchr = tcase_create("strrchr");
  tcase_add_test(tc_strrchr, strrchr_1);
  tcase_add_test(tc_strrchr, strrchr_2);
  tcase_add_test(tc_strrchr, strrchr_3);
  tcase_add_test(tc_strrchr, strrchr_4);
  tcase_add_test(tc_strrchr, strrchr_5);
  tcase_add_test(tc_strrchr, strrchr_6);
  tcase_add_test(tc_strrchr, strrchr_7);
  tcase_add_test(tc_strrchr, strrchr_8);
  suite_add_tcase(suite, tc_strrchr);

  // 14 Добавление тестов в набор
  TCase *tc_strstr = tcase_create("strstr");
  tcase_add_test(tc_strstr, strstr_1);
  tcase_add_test(tc_strstr, strstr_2);
  tcase_add_test(tc_strstr, strstr_3);
  tcase_add_test(tc_strstr, strstr_4);
  tcase_add_test(tc_strstr, strstr_5);
  tcase_add_test(tc_strstr, strstr_6);
  tcase_add_test(tc_strstr, strstr_7);
  tcase_add_test(tc_strstr, strstr_8);
  tcase_add_test(tc_strstr, strstr_9);
  tcase_add_test(tc_strstr, strstr_10);
  tcase_add_test(tc_strstr, strstr_11);
  tcase_add_test(tc_strstr, strstr_12);
  tcase_add_test(tc_strstr, strstr_13);
  suite_add_tcase(suite, tc_strstr);

  // 15 Добавление тестов в набор
  TCase *tc_strtok = tcase_create("strtok");
  tcase_add_test(tc_strtok, strtok_1);
  tcase_add_test(tc_strtok, strtok_2);
  tcase_add_test(tc_strtok, strtok_3);
  tcase_add_test(tc_strtok, strtok_4);
  tcase_add_test(tc_strtok, strtok_5);
  tcase_add_test(tc_strtok, strtok_6);
  tcase_add_test(tc_strtok, strtok_7);
  tcase_add_test(tc_strtok, strtok_8);
  tcase_add_test(tc_strtok, strtok_9);
  tcase_add_test(tc_strtok, strtok_10);
  tcase_add_test(tc_strtok, strtok_12);
  suite_add_tcase(suite, tc_strtok);

  // 16 Добавление тестов в набор
  TCase *tc_to_upper = tcase_create("to_upper");
  tcase_add_test(tc_to_upper, test_to_upper_1);
  tcase_add_test(tc_to_upper, test_to_upper_2);
  tcase_add_test(tc_to_upper, test_to_upper_3);
  tcase_add_test(tc_to_upper, test_to_upper_4);
  tcase_add_test(tc_to_upper, test_to_upper_5);
  tcase_add_test(tc_to_upper, test_to_upper_6);
  tcase_add_test(tc_to_upper, test_to_upper_7);
  suite_add_tcase(suite, tc_to_upper);

  // 17 Добавление тестов в набор
  TCase *tc_to_lower = tcase_create("to_lower");
  tcase_add_test(tc_to_lower, test_to_lower_1);
  tcase_add_test(tc_to_lower, test_to_lower_2);
  tcase_add_test(tc_to_lower, test_to_lower_3);
  tcase_add_test(tc_to_lower, test_to_lower_4);
  tcase_add_test(tc_to_lower, test_to_lower_5);
  tcase_add_test(tc_to_lower, test_to_lower_6);
  tcase_add_test(tc_to_lower, test_to_lower_7);
  suite_add_tcase(suite, tc_to_lower);

  // 18 Добавление тестов в набор
  TCase *tc_insert = tcase_create("insert");
  tcase_add_test(tc_insert, test_insert_1);
  tcase_add_test(tc_insert, test_insert_2);
  tcase_add_test(tc_insert, test_insert_3);
  tcase_add_test(tc_insert, test_insert_4);
  tcase_add_test(tc_insert, test_insert_5);
  tcase_add_test(tc_insert, test_insert_6);
  tcase_add_test(tc_insert, test_insert_7);
  tcase_add_test(tc_insert, test_insert_8);
  tcase_add_test(tc_insert, test_insert_9);
  tcase_add_test(tc_insert, test_insert_10);
  suite_add_tcase(suite, tc_insert);

  // 19 Добавление тестов в набор
  TCase *tc_trim = tcase_create("trim");
  tcase_add_test(tc_trim, test_trim_1);
  tcase_add_test(tc_trim, test_trim_2);
  tcase_add_test(tc_trim, test_trim_3);
  tcase_add_test(tc_trim, test_trim_4);
  tcase_add_test(tc_trim, test_trim_5);
  tcase_add_test(tc_trim, test_trim_6);
  tcase_add_test(tc_trim, test_trim_7);
  tcase_add_test(tc_trim, test_trim_8);
  tcase_add_test(tc_trim, test_trim_9);
  tcase_add_test(tc_trim, test_trim_10);
  suite_add_tcase(suite, tc_trim);
  ///////////////////////

  // // Добавление тестов в набор
  // TCase *tc_cpec_c = tcase_create("cpec_c");
  // tcase_add_test(tc_cpec_c, sprintf_1_c);
  // tcase_add_test(tc_cpec_c, sprintf_2_c);
  // tcase_add_test(tc_cpec_c, sprintf_3_c);
  // tcase_add_test(tc_cpec_c, sprintf_4_c);
  // tcase_add_test(tc_cpec_c, sprintf_5_c);
  // tcase_add_test(tc_cpec_c, sprintf_6_c);
  // tcase_add_test(tc_cpec_c, sprintf_7_c);
  // tcase_add_test(tc_cpec_c, sprintf_8_c);
  // tcase_add_test(tc_cpec_c, sprintf_9_c);
  // tcase_add_test(tc_cpec_c, sprintf_10_c);

  // suite_add_tcase(suite, tc_cpec_c);

  // // Добавление тестов в набор
  // TCase *tc_cpec_d = tcase_create("cpec_d");
  // tcase_add_test(tc_cpec_d, sprintf_1_signed);
  // tcase_add_test(tc_cpec_d, sprintf_2_signed);
  // tcase_add_test(tc_cpec_d, sprintf_3_signed);
  // tcase_add_test(tc_cpec_d, sprintf_4_signed);
  // tcase_add_test(tc_cpec_d, sprintf_5_signed);
  // tcase_add_test(tc_cpec_d, sprintf_6_signed);
  // tcase_add_test(tc_cpec_d, sprintf_7_signed);
  // tcase_add_test(tc_cpec_d, sprintf_8_signed);
  // tcase_add_test(tc_cpec_d, sprintf_9_signed);
  // tcase_add_test(tc_cpec_d, sprintf_10_signed);
  // suite_add_tcase(suite, tc_cpec_d);

  // // Добавление тестов в набор
  // TCase *tc_cpec_g = tcase_create("cpec_g");
  // tcase_add_test(tc_cpec_g, sprintf_1_g);
  // tcase_add_test(tc_cpec_g, sprintf_3_g);
  // tcase_add_test(tc_cpec_g, sprintf_4_g);
  // tcase_add_test(tc_cpec_g, sprintf_5_g);
  // tcase_add_test(tc_cpec_g, sprintf_6_g);
  // tcase_add_test(tc_cpec_g, sprintf_7_g);
  // tcase_add_test(tc_cpec_g, sprintf_8_g);
  // tcase_add_test(tc_cpec_g, sprintf_9_g);
  // suite_add_tcase(suite, tc_cpec_g);

  // // Добавление тестов в набор
  // TCase *tc_cpec_e = tcase_create("cpec_e");
  // tcase_add_test(tc_cpec_e, sprintf_1_e);
  // tcase_add_test(tc_cpec_e, sprintf_2_e);
  // tcase_add_test(tc_cpec_e, sprintf_3_e);
  // tcase_add_test(tc_cpec_e, sprintf_4_e);
  // tcase_add_test(tc_cpec_e, sprintf_5_e);
  // tcase_add_test(tc_cpec_e, sprintf_6_e);
  // tcase_add_test(tc_cpec_e, sprintf_7_e);
  // tcase_add_test(tc_cpec_e, sprintf_8_e);
  // tcase_add_test(tc_cpec_e, sprintf_9_e);
  // tcase_add_test(tc_cpec_e, sprintf_10_e);
  // tcase_add_test(tc_cpec_e, sprintf_11_e);
  // tcase_add_test(tc_cpec_e, sprintf_12_e);
  // tcase_add_test(tc_cpec_e, sprintf_13_e);
  // suite_add_tcase(suite, tc_cpec_e);

  // // Добавление тестов в набор
  // TCase *tc_cpec_f = tcase_create("cpec_f");
  // tcase_add_test(tc_cpec_f, sprintf_1_f);
  // tcase_add_test(tc_cpec_f, sprintf_2_f);
  // tcase_add_test(tc_cpec_f, sprintf_3_f);
  // tcase_add_test(tc_cpec_f, sprintf_4_f);
  // tcase_add_test(tc_cpec_f, sprintf_5_f);
  // tcase_add_test(tc_cpec_f, sprintf_6_f);
  // tcase_add_test(tc_cpec_f, sprintf_7_f);
  // tcase_add_test(tc_cpec_f, sprintf_8_f);
  // tcase_add_test(tc_cpec_f, sprintf_9_f);
  // tcase_add_test(tc_cpec_f, sprintf_10_f);
  // tcase_add_test(tc_cpec_f, sprintf_11_f);
  // tcase_add_test(tc_cpec_f, sprintf_12_f);

  // suite_add_tcase(suite, tc_cpec_f);

  // // Добавление тестов в набор
  // TCase *tc_cpec_x = tcase_create("cpec_x");
  // tcase_add_test(tc_cpec_x, sprintf_1_hex);
  // tcase_add_test(tc_cpec_x, sprintf_2_hex);
  // tcase_add_test(tc_cpec_x, sprintf_3_hex);
  // tcase_add_test(tc_cpec_x, sprintf_4_hex);
  // tcase_add_test(tc_cpec_x, sprintf_5_hex);
  // tcase_add_test(tc_cpec_x, sprintf_6_hex);
  // tcase_add_test(tc_cpec_x, sprintf_7_hex);
  // tcase_add_test(tc_cpec_x, sprintf_8_hex);
  // tcase_add_test(tc_cpec_x, sprintf_9_hex);
  // tcase_add_test(tc_cpec_x, sprintf_10_hex);
  // suite_add_tcase(suite, tc_cpec_x);

  // // Добавление тестов в набор
  // TCase *tc_cpec_X = tcase_create("cpec_X");
  // tcase_add_test(tc_cpec_X, sprintf_1_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_2_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_3_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_4_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_5_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_6_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_7_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_8_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_9_HEX);
  // tcase_add_test(tc_cpec_X, sprintf_10_HEX);
  // suite_add_tcase(suite, tc_cpec_X);

  // // Добавление тестов в набор
  // TCase *tc_cpec_i = tcase_create("cpec_i");
  // tcase_add_test(tc_cpec_i, sprintf_1_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_2_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_3_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_4_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_5_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_6_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_7_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_8_signed_i);
  // tcase_add_test(tc_cpec_i, sprintf_9_signed_i);
  // suite_add_tcase(suite, tc_cpec_i);

  // // Добавление тестов в набор
  // TCase *tc_cpec_n = tcase_create("cpec_n");
  // tcase_add_test(tc_cpec_n, sprintf_1_n);
  // tcase_add_test(tc_cpec_n, sprintf_2_n);
  // suite_add_tcase(suite, tc_cpec_n);

  // // Добавление тестов в набор
  // TCase *tc_cpec_o = tcase_create("cpec_o");
  // tcase_add_test(tc_cpec_o, sprintf_1_octal);
  // tcase_add_test(tc_cpec_o, sprintf_2_octal);
  // tcase_add_test(tc_cpec_o, sprintf_3_octal);
  // tcase_add_test(tc_cpec_o, sprintf_4_octal);
  // tcase_add_test(tc_cpec_o, sprintf_5_octal);
  // tcase_add_test(tc_cpec_o, sprintf_6_octal);
  // tcase_add_test(tc_cpec_o, sprintf_7_octal);
  // tcase_add_test(tc_cpec_o, sprintf_8_octal);
  // tcase_add_test(tc_cpec_o, sprintf_9_octal);
  // suite_add_tcase(suite, tc_cpec_o);

  // // Добавление тестов в набор
  // TCase *tc_percent = tcase_create("percent");
  // tcase_add_test(tc_percent, sprintf_1_percent);
  // tcase_add_test(tc_percent, sprintf_2_percent);
  // tcase_add_test(tc_percent, sprintf_3_percent);
  // suite_add_tcase(suite, tc_percent);

  // // Добавление тестов в набор
  // TCase *tc_cpec_p = tcase_create("cpec_p");
  // tcase_add_test(tc_cpec_p, sprintf_1_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_2_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_3_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_4_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_5_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_6_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_7_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_8_pointer);
  // tcase_add_test(tc_cpec_p, sprintf_9_pointer);
  // suite_add_tcase(suite, tc_cpec_p);

  // // Добавление тестов в набор
  // TCase *tc_cpec_s = tcase_create("cpec_s");
  // tcase_add_test(tc_cpec_s, sprintf_1_string);
  // tcase_add_test(tc_cpec_s, sprintf_2_string);
  // tcase_add_test(tc_cpec_s, sprintf_3_string);
  // tcase_add_test(tc_cpec_s, sprintf_5_string);
  // tcase_add_test(tc_cpec_s, sprintf_6_string);
  // tcase_add_test(tc_cpec_s, sprintf_7_string);
  // tcase_add_test(tc_cpec_s, sprintf_8_string);
  // tcase_add_test(tc_cpec_s, sprintf_9_string);
  // suite_add_tcase(suite, tc_cpec_s);

  // // Добавление тестов в набор
  // TCase *tc_cpec_u = tcase_create("cpec_u");
  // tcase_add_test(tc_cpec_u, sprintf_1_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_2_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_3_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_4_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_5_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_6_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_7_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_8_unsigned);
  // tcase_add_test(tc_cpec_u, sprintf_9_unsigned);
  // suite_add_tcase(suite, tc_cpec_u);

  //////////////------sscanf-------//////////////////

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_c = tcase_create("sscanf_spec_c");
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_2);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_4);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_5);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_6);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_7);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_8);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_9);
  tcase_add_test(tc_sscanf_spec_c, sscanf_spec_c_10);
  suite_add_tcase(suite, tc_sscanf_spec_c);

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_d = tcase_create("sscanf_spec_d");
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_hhd);
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_hd);
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_d);
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_ld);
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_lld);
  tcase_add_test(tc_sscanf_spec_d, sscanf_spec_2d);
  suite_add_tcase(suite, tc_sscanf_spec_d);

  //  Добавление тестов в набор
  TCase *tc_sscanf_empty = tcase_create("sscanf_empty");
  tcase_add_test(tc_sscanf_empty, sscanf_empty);
  suite_add_tcase(suite, tc_sscanf_empty);

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_i = tcase_create("sscanf_spec_i");
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_i_3parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_i_4parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_hhi_3parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_hhi_4parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_hi_4parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_li_3parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_lli_3parametra);
  tcase_add_test(tc_sscanf_spec_i, sscanf_spec_lli_4parametra);
  suite_add_tcase(suite, tc_sscanf_spec_i);

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_n = tcase_create("sscanf_spec_n");
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_1);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_2);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_3);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_4);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_5);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_6);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_7);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_8);
  tcase_add_test(tc_sscanf_spec_n, sscanf_n_9);
  tcase_add_test(tc_sscanf_spec_n, sscanf_floats1);
  suite_add_tcase(suite, tc_sscanf_spec_n);

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_o = tcase_create("sscanf_spec_o");
  tcase_add_test(tc_sscanf_spec_o, sscanf_spec_hho);
  tcase_add_test(tc_sscanf_spec_o, sscanf_spec_ho);
  tcase_add_test(tc_sscanf_spec_o, sscanf_spec_o);
  tcase_add_test(tc_sscanf_spec_o, sscanf_spec_lo);
  tcase_add_test(tc_sscanf_spec_o, sscanf_spec_llo);
  suite_add_tcase(suite, tc_sscanf_spec_o);

  //  Добавление тестов в набор
  TCase *tc_sscanf_spec_p = tcase_create("sscanf_spec_p");
  tcase_add_test(tc_sscanf_spec_p, sscanf_spec_p);
  suite_add_tcase(suite, tc_sscanf_spec_p);

  //  Добавление тестов в набор
  TCase *tc_sscanf_real = tcase_create("sscanf_real");
  tcase_add_test(tc_sscanf_real, sscanf_real_1);
  tcase_add_test(tc_sscanf_real, sscanf_real_2);
  tcase_add_test(tc_sscanf_real, sscanf_real_3);
  tcase_add_test(tc_sscanf_real, sscanf_real_4);
  tcase_add_test(tc_sscanf_real, sscanf_real_5);
  tcase_add_test(tc_sscanf_real, sscanf_real_6);
  tcase_add_test(tc_sscanf_real, sscanf_real_7);
  tcase_add_test(tc_sscanf_real, sscanf_real_8);
  suite_add_tcase(suite, tc_sscanf_real);

  // //  Добавление тестов в набор
  TCase *tc_sscanf_spec_x = tcase_create("sscanf_spec_x");
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_1);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_2);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_3);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_4);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_5);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_6);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_7);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_8);
  tcase_add_test(tc_sscanf_spec_x, sscanf_x_9);
  suite_add_tcase(suite, tc_sscanf_spec_x);

  return suite;
}

int main() {
  // Создание тестового набора
  Suite *suite = main_suite();

  // Создание раннера тестов
  SRunner *runner = srunner_create(suite);

  // Запуск всех тестов
  srunner_run_all(runner, CK_NORMAL);

  // Получение количества неуспешных тестов
  int failed = srunner_ntests_failed(runner);

  // Освобождение памяти
  srunner_free(runner);

  // Возврат кода ошибки, если есть неуспешные тесты
  return 0;
}
