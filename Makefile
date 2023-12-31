#   Copyright 2023 Ambareesh Pandit
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

INCLUDE_DIR=./include
LIB_DIR=./lib
SRC_DIR=./src
TEST_DIR=./test
DEBUG_ARGS=-g

PYTHON_CMD=python3
UPDATE_PYTHON_CMD_MESSAGE=ERROR: Error occurred. Please check PYTHON_CMD setting in Makefile.

all: run

run: compile
	./out/main_release.o

test: compile_test $(TEST_DIR)/regex_parser/*.py $(TEST_DIR)/files/input.txt
	$(PYTHON_CMD) $(TEST_DIR)/regex_parser/test.py || (echo "${UPDATE_PYTHON_CMD_MESSAGE}"; exit 1)

debug: do_debug
	gdb out/main_debug.o

do_debug: $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h
	mkdir -p out
	gcc $(DEBUG_ARGS) -o out/main_debug.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/main.c $(SRC_DIR)/regex_parser.c

compile: $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h
	mkdir -p out
	gcc -o out/main_release.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/main.c $(SRC_DIR)/regex_parser.c

compile_test: $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h
	mkdir -p out
	gcc -o out/test.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/test.c $(SRC_DIR)/regex_parser.c

#to_lib: $(INCLUDE_DIR) $(SRC_DIR)/*.c
#	mkdir -p out
#	gcc -c -o out/regex_parser.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/regex_parser.c
#	ar rcs $(LIB_DIR)/libout.a out/regex_parser.o

clean: clean_test
# bash construct: delete "out" if it exists
	! [ -e out ] || rm -rf out

clean_test:
	(! [ -e test/files/expected.txt ] || rm test/files/expected.txt) \
	; (! [ -e test/files/actual.txt ] || rm test/files/actual.txt)
