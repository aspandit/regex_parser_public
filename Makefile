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
SRC_DIR=./src
DEBUG_ARGS=-g 

all: compile
	echo "Execute './out/main_release.o' to run"

run_release: compile
	./out/main_release.o

run_debug: debug
	gdb out/main_debug.o

debug: $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h
	mkdir -p out
	gcc $(DEBUG_ARGS) -o out/main_debug.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/*.c

compile: $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h
	mkdir -p out
	gcc -o out/main_release.o --include-directory=$(INCLUDE_DIR) $(SRC_DIR)/*.c

clean:
	rm -rf out
