#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;
#define F_LEFT 1
#define F_SIGN 2
#define F_SPACE 4
#define F_HESHTAG 8
#define F_NULL 16
#define F_DOUBLE 1
#define F_LONG_DOUBLE 2
#define F_Float 1024
#define F_SHORT_SHORT_INT 2048
#define F_SHORT_INT 4
#define F_INT 8
#define F_LONG_INT 16
#define F_LONG_LONG_INT 32
#define F_STR 64
#define F_CHAR 128
#define F_PTR 256
#define F_N 512
#define CHAR_PTR char *

typedef struct t_S21SscanfArgs {
  int not_fill;
  int width;
  int length;
  char format;
  int count_fill_sym;
} S21SscanfArgs;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sscanf(const char *str, const char *format, ...);
int s21_sprintf(char *str, const char *format, ...);

#endif  // S21_STRING_H
