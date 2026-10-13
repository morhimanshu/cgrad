CFLAGS ?= -std=c99 -Wall -Wextra -I cgrad/include

SRC = cgrad/src/tensor.c
TEST_SRC = tests/test_ops.c
TESTS = build/tests/test_ops

all: $(TEST_BIN)

tests: $(SRC) $(TEST_SRC)
	mkdir -p build/tests/
	cc $(CFLAGS) $(SRC) $(TEST_SRC) -o $(TESTS)

clean:
	rm -rf build

.PHONY: all test clean
