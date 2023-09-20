//    Copyright 2023 Ambareesh Pandit
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//            http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include "regex_parser.h"

int count(char *literal,char *target)
{
    int cnt = 0;
    for(int idx = 0;target[idx];idx++)
    {
        if(isAt(target, idx, literal))
            cnt++;
    }
    return cnt;
}

bool isAt(char *target,int startIdx,char *literal)
{
    for (int idx = 0;literal[idx];idx++)
    {
        if(target[idx+startIdx] != literal[idx])
        {
            return false;
        }
    }

    return true;
}