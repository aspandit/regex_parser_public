[//]: # (Copyright 2023 Ambareesh Pandit)

[//]: # ()
[//]: # (Licensed under the Apache License, Version 2.0 &#40;the "License"&#41;;)

[//]: # (you may not use this file except in compliance with the License.)

[//]: # (You may obtain a copy of the License at)

[//]: # ()
[//]: # (       http://www.apache.org/licenses/LICENSE-2.0)

[//]: # ()
[//]: # (Unless required by applicable law or agreed to in writing, software)

[//]: # (distributed under the License is distributed on an "AS IS" BASIS,)

[//]: # (WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.)

[//]: # (See the License for the specific language governing permissions and)

[//]: # (limitations under the License.)

# regex_parser
Regular expression parser library

# Quickstart
See the "Build" section under the "Overview and Approach" section of this document for *quickstart* **make** commands.

# Status
THIS PROJECT IS NOT CURRENTLY A TRUE REGEX PARSER.

It counts the number of occurrences of a string literal within a test string.

# Overview and Approach
This project displays and leverages features of the **C programming language**, **Python**,
and **GNU Make**. First and foremost, it is intended to serve as a learning and teaching tool
and, secondarily, as a functional library.

The project files are primarily split along four dimensions: build, code, test, and documentation.

## Build
**GNU Make** is the build tool used in this project. As is the case with the **make** utility, any target can be
run with the `make <target>` command, where `<target>` is the target listed in ***Makefile***. Executing `make`
on the command line is equivalent to running `make run_release` since `run_release` is the default target.

### Available targets:
The *executable* **make** targets are of the format `run_*` and can be run using the optional, but recommended,
`-s`(shorthand for `--silent`) switch to suppress output from `make`.
+ `make -s run_release`
+ `make -s run_debug`
+ `make -s run_test`

The *housekeeping* **make** targets are of the format `clean*` and can be run as shown below.
+ `make clean`
+ `make clean_test`

The *compilation* **make** targets come in two flavors: `compile*` and `debug`.
+ `make compile`
+ `make compile_test`
+ `make debug`

## Code
The code for this project is written in **C**.

The **C** code uses dynamic memory allocation, pointers, structs, and linked lists.

## Test
The test code for this project is primarily written in **Python**; see ***test.py***. It is custom code that is built-from-scratch,
that is, no test framework/library has been used.
1. Tests utilize the `subprocess.call(...)` **Python** call to run the executable produced by **gcc**.
2. This call also assigns a file stream of ***input.txt*** to stdin to produce the **C** output as ***actual.txt***.
3. **Python** code in ***test.py*** subsequently produces the expected output ***expected.txt*** using the same ***input.txt***.
4. Finally, the ***expected.txt*** and ***actual.txt*** files are compared to ascertain a pass/fail outcome. 

## Documentation
The documentation for this project consists of this ***README.md*** file.

# Conventions
Below are the conventions used in this ***README.md*** file.

- **tool, technology, or programming language** - refer to external documentation, such as man pages, for further information
- *emphasis* - text where emphasis is desired
- `command` - can be run as-is on the command line, e.g., `make -s run_release`
- `command fragment` - part of a full cli command, e.g., the `-s` switch
- `command format` - a cli command that needs substitution or an update before it can be
run on the command line, e.g., `make <target>`
- "document section" - a section contained within this document
- ***filename*** - a file from this project

# TODOs
## Build
- Create shared and/or static libraries as a result of **C** compilation instead of executable
## Code
- Work on converting project to true regex parser - this is a long term task that will be done incrementally
## Test
- Add test vectors to ***input.txt***
- Add error-checking for ***input.txt***
- Change ***test.c*** and ***test.py*** to allow for specifying unit testing for library functions
- Create output report for test code
- Create **Python** and command line entry methods/points for ***test.c***
## Documentation
- Supplement documentation with project-specific **GDB** walkthrough(s)
- Write setup instructions for **Ubuntu** and for **Windows**(using **WSL2**)