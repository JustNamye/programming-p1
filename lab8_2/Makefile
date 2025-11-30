CC = gcc

# Unity использует unity.h из Unity/src
CFLAGS = -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage -lm

DEBUG_CFLAGS = -Wall -g -O0 -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage
DEBUG_LDFLAGS = -L. -fprofile-arcs -ftest-coverage -lm

SRC_DIR = src
TEST_DIR = test

UNITY_SRC = Unity/src/unity.c

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_tests

.PHONY: all clean test debug

all: $(EXECUTABLE)

$(EXECUTABLE): main.o libproject.a
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

libproject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libproject.a
	$(CC) $(CFLAGS) -o $@ $(UNITY_SRC) $^ $(LDFLAGS)

debug: CFLAGS=$(DEBUG_CFLAGS)
debug: LDFLAGS=$(DEBUG_LDFLAGS)
debug: clean $(EXECUTABLE)
	@echo "Debug build completed. Run with:"
	@echo "  gdb ./$(EXECUTABLE)"

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) main.o libproject.a
	rm -f *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report
