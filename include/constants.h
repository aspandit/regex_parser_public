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

#ifndef REGEX_PARSER_CONSTANTS_H
#define REGEX_PARSER_CONSTANTS_H

    typedef struct {
        char *regex;
        char *expression;
    } CharacterClass;

    typedef struct {
        char expression;
        int min;
        int max;
    } Quantifier;

    typedef struct {
        char *expression;
        char minMaxSeparator;
    } QuantifierRegex;

    // character classes
    const CharacterClass CHARACTER_CLASSES[] = {
    {"[a-zA-Z0-9_]","\\w"},
    {"[^a-zA-Z0-9_]","\\W"}
    };

    // quantifiers
    const Quantifier QUANTIFIERS[] = {
    {'?',0,1},
    {'+',1,-1},
    {'*',0,-1}
    };

    const QuantifierRegex QUANTIFIER_REGULAR_EXPRESSIONS[] = {
    {"{n}",'\0'},
    {"{n,}",','},
    {"{n,m}",','}
    };
#endif //REGEX_PARSER_CONSTANTS_H
