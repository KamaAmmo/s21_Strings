CC := gcc
CFLAGS := -g -Wall -Wextra -std=c11
TEST_FLAGS := -lcheck -lpthread -lm -lgcov 

FUNCS := funcs/s21_insert.o funcs/s21_memchr.o funcs/s21_memcmp.o funcs/s21_memcpy.o funcs/s21_memset.o funcs/s21_sprintf.o funcs/s21_sscanf.o funcs/s21_strchr.o funcs/s21_strcspn.o funcs/s21_strerror.o funcs/s21_strlen.o funcs/s21_strncat.o funcs/s21_strncmp.o funcs/s21_strncpy.o funcs/s21_strpbrk.o funcs/s21_strrchr.o funcs/s21_strstr.o funcs/s21_strtok.o funcs/s21_to_lower.o funcs/s21_to_upper.o funcs/s21_trim.o
TEST_SUITS := test-suites/suite_insert.o test-suites/suite_memchr.o test-suites/suite_memcmp.o test-suites/suite_memcpy.o test-suites/suite_memset.o test-suites/suite_sprintf.o test-suites/suite_sscanf.o test-suites/suite_strchr.o test-suites/suite_strcspn.o test-suites/suite_strerror.o test-suites/suite_strlen.o test-suites/suite_strncat.o test-suites/suite_strncmp.o test-suites/suite_strncpy.o test-suites/suite_strpbrk.o test-suites/suite_strrchr.o  test-suites/suite_strstr.o test-suites/suite_strtok.o test-suites/suite_to_lower.o test-suites/suite_to_upper.o test-suites/suite_trim.o

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: gcov_report

rebuild: clean all

clean:
	rm -rf *.gcno *.gcda *.o *coverage* *.a html_report s21_string_tests funcs/*.o funcs/*.gcda funcs/*.gcno test-suites/*.o test-suites/*.gcno 

s21_string.a: CFLAGS += --coverage
s21_string.a: $(FUNCS)
	ar rcs $@ $^

s21_string_tests: s21_string.a s21_string_tests.o $(TEST_SUITS)
	$(CC) -o s21_string_tests s21_string_tests.o $(TEST_SUITS) $(FUNCS)  $(FLAGS) $(TEST_FLAGS)

test: s21_string_tests
	./s21_string_tests

gcov_report: test
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open ./html_report/index.html

leaks: s21_string_tests
	leaks -atExit -- ./s21_string_tests

vallgrind: s21_string_tests
	valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_string_tests

style_check:
	clang-format -style=Google -n *.c *.h funcs/*.c test-suites/*.c

style_correct: style_check
	clang-format -style=Google -i *.c *.h funcs/*.c test-suites/*.c

