# Copyright 2023 Ambareesh Pandit
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import subprocess
import sys
from pathlib import Path
import filecmp

from io import open

test_dir_path = Path(__file__).parent.parent
test_files_dir_path = Path(test_dir_path, "files")

proc = subprocess.call(["./out/test.o", "--counts"], stdout=open(Path(test_files_dir_path, "actual.txt"), "w", encoding="utf-8"),
                       stdin=open(Path(test_files_dir_path, "input.txt"), "r", encoding="utf-8"), stderr=sys.stderr)

# generate expected output using Python constructs
with open(Path(test_files_dir_path, "input.txt"), "r", encoding="utf-8") as inp_file, \
        open(Path(test_files_dir_path, "expected.txt"), "w", encoding="utf-8") as exp_file:
    pairs = [iter(inp_file.readline, '')]*2
    for [search_string, test_string] in zip(*pairs):  # last line in "input.txt" file should be empty line
        [search_string, test_string] = [search_string.strip(), test_string.strip()]
        exp_file.write(f"{str(test_string.count(search_string))}\n")

# compare the expected and actual outputs
if not filecmp.cmp(Path(test_files_dir_path, "expected.txt").as_posix(), Path(test_files_dir_path, "actual.txt").as_posix(), shallow=False):
    print("FAIL")
else:
    print("PASS")
