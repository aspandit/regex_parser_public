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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/regex_parser.h"

#define STRING_MAX 255

char *getInput(int size)
{
    char * buff;
    char str[STRING_MAX+1];
    char c;
    int idx;

    for(idx = 0;idx < STRING_MAX && ((c = getchar()) != EOF && c != '\n');idx++)
    {
        str[idx] = c;
    }
    str[idx] = '\0';
    buff = str;

    return buff;
}

int main(int argc, char **argv)
{
    if(argc == 1) // if no options are specified on the command line
    {
        printf("Must specify a test option for this test run.\n");
        printf("Currently supported options are: \"--counts\"\n");
        exit(-1);
    }

    char *regex_buffer, *str_buffer, *buff;
    bool done;
    int size;

    do {
        buff = getInput(size);
        regex_buffer = malloc(size*sizeof(char));
        strcpy(regex_buffer,buff);

        buff = getInput(size);
        str_buffer = malloc(size*sizeof(char));
        strcpy(str_buffer,buff);

        // if either buffer is empty, we are done
        done = (*regex_buffer == '\0' || *str_buffer == '\0');
        if(!done)
        {
            printf("%d\n", count(regex_buffer, str_buffer));
        }
        free(regex_buffer); // free regex_buffer after every use
        free(str_buffer); // free str_buffer after every use
    } while(!done);

    return 0;
}