//
// Created by stasc on 20.03.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#ifndef DECOMPRESSFILE_FUNCTIONS_H
#define DECOMPRESSFILE_FUNCTIONS_H

void readWordsFromFile(FILE*, char***, char***, int*);
void printCompressedFile(FILE*,FILE*,char**,char**,int);
int printWordLengths(char**, int);


#endif //DECOMPRESSFILE_FUNCTIONS_H
