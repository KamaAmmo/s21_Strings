#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

// +: always show sign
// -: left-justified
//  : leave space for sign
// n.m width and precision as integeres
// %c int                            %lc wint_t       |
// %d int          %hd short         %ld long         |
// %f double                         %lf double       | %Lf long double
// %s char*                          %ls wchar_t*     |
// %u unsigned int %hu unsignd short %lu unsigned long|
// ---------------------------------------------------|
// #: alternative form
// 0: leading zeroes for padding
// *.* width and precision as additional arguments
// %xX unsigned int as hex
// %o  unsigned int as oct
// %eE double as [-]d.dddE±dd
// %gG double as %f or %eE

typedef struct flags_struct {
  bool show_plus;
  bool left_just;
  bool plus_space;
  bool alt;
  bool zero_padding;
  bool caps;
  int width;
  int precision;
  short size;
} flags_t;

const char *parse_flags(const char *format, flags_t *res) {
  const char *f;
  bool cont = true;
  for (f = format; cont; ++f) {
    switch (*f) {
      case '+':
        res->show_plus = true;
        break;
      case '-':
        res->left_just = true;
        break;
      case ' ':
        res->plus_space = true;
        break;
      case '#':
        res->alt = true;
        break;
      case '0':
        res->zero_padding = true;
        break;
      default:
        cont = false;
        --f;
    }
  }
  return f;
}

const char *parse_format_num(const char *format, int *dst, va_list *args) {
  if (*format == '*') {
    *dst = va_arg(*args, int);
    ++format;
  } else {
    if (*format >= '0' && *format <= '9') {
      int len = 0;
      for (const char *p = format; *p >= '0' && *p <= '9'; ++p) ++len;

      if (dst != NULL) *dst = 0;
      for (int i = len - 1; i >= 0; --i) {
        if (dst != NULL) *dst += (*format - '0') * pow(10, i);
        ++format;
      }
    }
  }
  return format;
}

int pad(char *str, int num, bool zero_padding) {
  int i;
  for (i = 0; i < num; ++i) str[i] = zero_padding ? '0' : ' ';
  return i;
}

const char *parse_size(const char *format, flags_t *flags) {
  switch (*format) {
    case 'h':
      flags->size = 1;
      break;
    case 'l':
      flags->size = 2;
      break;
    case 'L':
      flags->size = 3;
      break;
    default:
      --format;
  }
  return ++format;
}

int convert_ws(char *str, flags_t flags, wchar_t *ws) {
  size_t in_sz = wcslen(ws);
  mbstate_t state;
  memset(&state, 0, sizeof state);

  char *arg = malloc(MB_CUR_MAX * in_sz * sizeof(char));
  char *p = arg;
  for (size_t n = 0; n < in_sz; ++n) {
    int rc = wcrtomb(p, ws[n], &state);
    if (rc == -1) break;
    p += rc;
  }

  int len = flags.precision < 0 || flags.precision > strlen(arg)
                ? strlen(arg)
                : flags.precision;
  memcpy(str, arg, len);
  free(arg);
  return len;
}
int convert_c(char *str, flags_t flags, va_list *args) {
  int written = 0;
  if (flags.size != 2) {
    if (flags.zero_padding)
      written += pad(&(str[written]), flags.width - 1, flags.zero_padding);
    str[written] = (unsigned char)va_arg(*args, int);
    written++;
  } else {
    flags.precision = -1;
    wchar_t chr = va_arg(*args, wint_t);
    if (chr != L'\0') {
      wchar_t chr_capsule[2] = {chr, L'\0'};
      written += convert_ws(str, flags, chr_capsule);
    } else {
      *str = '\0';
      ++written;
    }
  }
  return written;
}
int convert_d(char *str, flags_t flags, va_list *args) {
  long num;
  if (flags.size == 2)
    num = va_arg(*args, long);
  else
    num = va_arg(*args, int);

  int written = 0;
  flags.precision = flags.precision < 0 ? 1 : flags.precision;

  if (flags.precision != 0 || num != 0) {
    if (num < 0) {
      str[written] = '-';
      ++written;
      num *= -1;
    } else if (flags.show_plus) {
      str[written] = '+';
      ++written;
    } else if (flags.plus_space) {
      str[written] = ' ';
      ++written;
    }

    int len;
    long tmp = num;
    for (len = 0; tmp; ++len) tmp /= 10;
    len = (flags.precision > len ? flags.precision : len);
    if (flags.zero_padding)
      written +=
          pad(&(str[written]), flags.width - len - written, flags.zero_padding);

    int start = written;
    do {
      str[start + --len] = '0' + num % 10;
      ++written;
      num /= 10;
    } while (len);
    return written;
  }
  return written;
}
int fnan_inf_convert(char *str, flags_t flags, long double num) {
  int written = 0;
  if (fabsl(num) == INFINITY) {
    if (flags.caps)
      strcpy(&(str[written]), "INF");
    else
      strcpy(&(str[written]), "inf");
    flags.zero_padding = false;
    written += 3;
  } else if (isnan(num)) {
    if (flags.caps)
      strcpy(&(str[written]), "NAN");
    else
      strcpy(&(str[written]), "nan");
    flags.zero_padding = false;
    written += 3;
  }
  return written;
}
int fint_part_len(long double integer_part) {
  long double tmp = integer_part;
  int int_len = 0;
  for (int_len = 0; fabsl(tmp) >= 1.; ++int_len) tmp /= 10;
  if (integer_part == 0.) int_len = 1;
  return int_len;
}
int fint_part_convert(char *str, long double num, int len) {
  int written = 0;
  int start = written;
  do {
    str[start + --len] = '0' + (int)fmod(num, 10);
    ++written;
    num /= 10;
  } while (len);
  return written;
}
int fract_partconvert(char *str, long double fractional_part, int fract_len) {
  long double tmp = fractional_part;
  long int fractNum = 0;
  for (int l = fract_len; l > 0; --l) {
    fractional_part *= 10;
    int digit = fmod(fractional_part, 10);
    fractNum += pow(10, l - 1) * digit;
    fractional_part -= digit;
  }
  if (fractional_part >= 0.5) ++fractNum;

  int written = 0;
  do {
    str[--fract_len] = '0' + fractNum % 10;
    ++written;
    fractNum /= 10;
  } while (fract_len);
  return written;
}
int convert_f(char *str, flags_t flags, va_list *args) {
  long double num;
  if (flags.size == 2)
    num = va_arg(*args, long double);
  else
    num = va_arg(*args, double);

  int written = 0;
  if (signbit(num)) {
    str[written] = '-';
    ++written;
    num *= -1;
  } else if (flags.show_plus && !isnan(num)) {
    str[written] = '+';
    ++written;
  } else if (flags.plus_space && !isnan(num)) {
    str[written] = ' ';
    ++written;
  }

  int is_nan_inf = fnan_inf_convert(&(str[written]), flags, num);
  written += is_nan_inf;
  if (is_nan_inf == 0) {
    long double integer_part = flags.precision == 0 ? roundl(num) : floorl(num);
    long double fractional_part = num - integer_part;
    int int_len = fint_part_len(integer_part);
    int fract_len = flags.precision == -1 ? 6 : flags.precision;
    int len = int_len + fract_len;
    if (flags.zero_padding)
      written += pad(&(str[written]), flags.width - len, flags.zero_padding);
    written += fint_part_convert(&(str[written]), integer_part, int_len);

    if (fract_len != 0 || flags.alt) {
      str[written] = '.';
      ++written;
    }
    if (fract_len != 0)
      written += fract_partconvert(&(str[written]), fractional_part, fract_len);
  }
  return written;
}
int convert_s(char *str, flags_t flags, va_list *args) {
  int written = 0;
  if (flags.size != 2) {
    char *arg = va_arg(*args, char *);
    int len = flags.precision < 0 || flags.precision > strlen(arg)
                  ? strlen(arg)
                  : flags.precision;
    memcpy(str, arg, len);
    written += len;
  } else {
    wchar_t *warg = va_arg(*args, wchar_t *);
    written += convert_ws(str, flags, warg);
  }

  return written;
}
int convert_u(char *str, flags_t flags, va_list *args) {
  unsigned long num;
  if (flags.size == 2)
    num = va_arg(*args, unsigned long);
  else
    num = va_arg(*args, unsigned int);

  int written = 0;
  flags.precision = flags.precision < 0 ? 1 : flags.precision;
  if (flags.precision != 0 || num != 0 || flags.alt) {
    int len;
    unsigned long tmp = num;
    for (len = 0; tmp; ++len) tmp /= 10;
    len = flags.precision > len ? flags.precision : len;
    if (flags.zero_padding)
      written += pad(&(str[written]), flags.width - len, flags.zero_padding);

    int start = written;
    do {
      str[start + --len] = '0' + num % 10;
      ++written;
      num /= 10;
    } while (len);
  }
  return written;
}
int convert_x(char *str, flags_t flags, va_list *args) {
  unsigned long num;
  if (flags.size == 2)
    num = va_arg(*args, unsigned long);
  else
    num = va_arg(*args, unsigned int);

  int written = 0, precision = flags.precision < 0 ? 1 : flags.precision;
  if (precision != 0 || num != 0) {
    int offset = flags.caps ? 'A' : 'a';
    if (flags.alt) {
      str[written++] = '0';
      str[written++] = flags.caps ? 'X' : 'x';
    }

    int len;
    unsigned long tmp = num;
    for (len = 0; tmp; ++len) tmp /= 16;
    len = precision > len ? precision : len;
    if (flags.zero_padding)
      written += pad(&(str[written]), flags.width - len, flags.zero_padding);

    int start = written;
    do {
      char ch;
      if (num % 16 > 9)
        ch = offset + num % 16 - 10;
      else
        ch = '0' + num % 16;
      str[start + --len] = ch;
      ++written;
      num /= 16;
    } while (len);
  }
  return written;
}

int convert_o(char *str, flags_t flags, va_list *args) {
  unsigned long num;
  if (flags.size == 2)
    num = va_arg(*args, unsigned long);
  else
    num = va_arg(*args, unsigned int);

  int written = 0, precision = flags.precision < 0 ? 1 : flags.precision;
  if (precision != 0 || num != 0 || flags.alt) {
    int len;
    unsigned long tmp = num;
    for (len = 0; tmp; ++len) tmp /= 8;
    len = precision > len ? precision : len;
    if (num != 0 && flags.alt) ++len;
    if (flags.zero_padding)
      written += pad(&(str[written]), flags.width - len, flags.zero_padding);

    int start = written;
    len = len <= 0 ? 1 : len;
    do {
      str[start + --len] = '0' + num % 8;
      ++written;
      num /= 8;
    } while (len > 0);
  }
  return written;
}
int convert_e(char *str, flags_t flags, va_list *args) { return 0; }
int convert_g(char *str, flags_t flags, va_list *args) { return 0; }

int perform_conversion(char *str, char specifier, flags_t flags,
                       va_list *args) {
  int (*converters[26])(char *, flags_t, va_list *) = {NULL};
  converters['c' - 'a'] = convert_c;
  converters['d' - 'a'] = convert_d;
  converters['f' - 'a'] = convert_f;
  converters['s' - 'a'] = convert_s;
  converters['u' - 'a'] = convert_u;
  converters['x' - 'a'] = convert_x;
  converters['o' - 'a'] = convert_o;
  converters['e' - 'a'] = convert_e;
  converters['g' - 'a'] = convert_g;

  if (isupper(specifier)) flags.caps = true;

  int written = 0;
  if (converters[tolower(specifier) - 'a'] != NULL) {
    written = converters[tolower(specifier) - 'a'](str, flags, args);
  } else if (specifier == '%') {
    str[written] = specifier;
    ++written;
  }
  return written;
}

bool is_zero_padding_applicable(flags_t flags, char specifier) {
  return flags.zero_padding && !flags.left_just &&
         ((strchr("feEgGc", specifier) != NULL) ||
          ((strchr("duxXo", specifier) != NULL) && flags.precision < 0));
}

int parse_specifier(char *str, int written, const char **format,
                    va_list *args) {
  const char *f = *format;
  flags_t flags = {false, false, false, false, false, false, -1, -1, 0};
  f = parse_flags(f, &flags);
  f = parse_format_num(f, &(flags.width), args);
  if (*f == '.') {
    ++f;
    if (*f == '-') {
      f = parse_format_num(++f, NULL, args);
    } else {
      f = parse_format_num(f, &(flags.precision), args);
      if (flags.precision == -1) flags.precision = 0;
    }
  }
  f = parse_size(f, &flags);
  if (!flags.left_just) {
    flags.zero_padding = is_zero_padding_applicable(flags, *f);
    va_list tmp;
    va_copy(tmp, *args);
    int len = perform_conversion(&(str[written]), *f, flags, &tmp);
    va_end(tmp);
    written += pad(&(str[written]), flags.width - len, false);
    written += perform_conversion(&(str[written]), *f, flags, args);
  } else {
    int length = perform_conversion(&(str[written]), *f, flags, args);
    written += length;
    written += pad(&(str[written]), flags.width - length, false);
  }
  *format = f;
  return written;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int written = 0;
  for (const char *f = format; *f != '\0'; ++f) {
    if (*f == '%') {
      ++f;
      written = parse_specifier(str, written, &f, &args);
      if (*f == '\0') --f;
    } else {
      str[written] = *f;
      ++written;
    }
  }
  str[written] = '\0';

  va_end(args);
  return written;
}
