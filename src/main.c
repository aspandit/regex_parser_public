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

/**
 * https://docs.python.org/3/library/re.html
 */

#include <stdio.h>
#include <stdlib.h>
#include "regex_parser.h"

typedef struct chNode {
    char ch;
    struct chNode *next;
} ChNode;

char *getInput()
{
    ChNode *input = (ChNode *) malloc(sizeof(ChNode));
    input -> ch = '\0';
    input -> next = NULL;
    int cnt = 0;

    char c;
    ChNode *curr = input;

    while((c = getchar()) != '\n') {
        curr -> ch = c;
        curr -> next = (ChNode *) malloc(sizeof(ChNode));
        curr = curr -> next;
        curr -> ch = '\0';
        curr -> next = NULL;
        cnt++;
    }

    if(cnt == 0)
    {
        free(input);
        return NULL;
    }

    char *ret = malloc((cnt+1) * sizeof(char));
    curr = input;

    for(int idx = 0;idx < cnt;idx++)
    {
        ret[idx] = curr -> ch;
        curr = curr -> next;
    }
    ret[cnt] = '\0';

    while(input->next != NULL) {
        for (curr = input;curr->next->next != NULL; curr = curr->next);
        free(curr->next);
        curr->next = NULL;
    }
    free(input);
    input = NULL;

    return ret;
}

int main(int argc,char **argv)
{
    char *regex, *str;

    do {
        printf("Search string(literal): ");
        regex = getInput();
        printf("Test string: ");
        str = getInput();

        if (regex == NULL || str == NULL) {
            if (regex != NULL) {
                free(regex);
            }
            if (str != NULL) {
                free(str);
            }

            return 0;
        }

        printf("Number of occurrences: %d\n", count(regex, str));

        free(regex);
        free(str);
    } while(*regex != '\0' && *str != '\0');

    return 0;
}