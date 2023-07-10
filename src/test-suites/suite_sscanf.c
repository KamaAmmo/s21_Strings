#include "../s21_string_tests.h"

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

Suite *suite_sscanf() {
  Suite *suite = suite_create("s21_sscanf");

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
