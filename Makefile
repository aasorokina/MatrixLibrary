SHELL = /bin/sh

CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic -g -std=c++17
LFLAGS = -lpthread -lm -lgtest -pthread 
GFLAGS = -fprofile-arcs -ftest-coverage

EXE_NAME = tests
LIB_NAME = s21_matrix_oop.a

LIB_SRC = $(wildcard lib/*.cpp)
TEST_SRC = $(wildcard test/*.cpp)

LIB_O = $(LIB_SRC:.cpp=.o)
TEST_O = $(TEST_SRC:.cpp=.o)

GCOV_NAME = gcov_tests.info

.PHONY: all clean s21_matrix_oop.a style_check style_fix test gcov_report rebuild valgrind_test cppcheck_test

all: clean s21_matrix_oop.a

s21_matrix_oop.a: $(LIB_O)
	@ar rc $(LIB_NAME) $(LIB_O)
	@ranlib $(LIB_NAME)
	@rm -rf lib/*.o

test: $(TEST_O) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(TEST_O) -o $(EXE_NAME) -L. -l:$(LIB_NAME) $(LFLAGS)
	@rm -rf $(TEST_O)
	@./$(EXE_NAME)
	@rm $(LIB_NAME)

gcov_report: clean
	$(CC) $(CFLAGS) -c $(LIB_SRC) --coverage
	$(CC) $(CFLAGS) -c $(TEST_SRC)
	$(CC) *.o -o $(EXE_NAME) $(LFLAGS) $(GFLAGS)
	./$(EXE_NAME)
	lcov -t "gcov_tests" -o $(GCOV_NAME) -c -d .
	genhtml -o report $(GCOV_NAME)
	@rm -rf *.gcno *.gcda *.gcov $(GCOV_NAME) *.o

clean:
	@rm -f $(LIB_NAME) $(EXE_NAME) ./lib/*.o *.o
	@rm -rf ./lib/*.o ./test/*.o *.gcno *.gcda ./report
	@rm -rf $(EXE_NAME)

style_check:
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -n test/*.cpp test/*.h lib/*.cpp *.h
	@rm -rf .clang-format

style_fix:
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -i test/*.cpp test/*.h lib/*.cpp *.h
	@rm -rf .clang-format

rebuild: clean $(LIB_NAME) test

valgrind_test: rebuild
	valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes -s ./$(EXE_NAME)

cppcheck_test: 
	cppcheck --enable=all --suppress=missingIncludeSystem $(LIB_SRC)