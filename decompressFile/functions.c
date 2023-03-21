//
// Created by stasc on 20.03.2023.
//

#include "functions.h"


int findPositions(FILE* compressFile)
{
    fseek(compressFile, 0, SEEK_END);
    int count = 0;
    int pos = 0;
    while (count<2) {
        fseek(compressFile, -1 - pos, SEEK_END);
        int c = fgetc(compressFile);
        if (c == '$'){
            count++;
        }
        pos++;
    }
    printf("%d\n", pos);
    return pos;
}

void printCompressedFile(FILE* file, FILE* compressedFile, char* wordA, char* wordB) {
    char* word = (char*)calloc(16,sizeof(char));
    printf("\nWordA::%s, WordB::%s", wordA, wordB);
    while (fscanf(file, "%16s", word) == 1) {

        if (strstr(word, "$") != NULL) {
            break;
        }

        int len = (int)strlen(word);
        if (ispunct(word[len - 1])) {
            char lastChar = word[len - 1];
            word[len - 1] = '\0'; // жестко убирает знак препинания
            if (strcmp(word, wordA) == 0) {
                fprintf(compressedFile, "%s%c ", wordB, lastChar);
            } else if (strcmp(word, wordB) == 0) {
                fprintf(compressedFile, "%s%c ", wordA, lastChar);
            } else {
                fprintf(compressedFile, "%s%c ", word, lastChar);
            }
        } else {
            if (strcmp(word, wordA) == 0) {
                fprintf(compressedFile, "%s ", wordB);
            } else if (strcmp(word, wordB) == 0) {
                fprintf(compressedFile, "%s ", wordA);
            } else {
                fprintf(compressedFile, "%s ", word);
            }
        }
    }
    free(word);
    fseek(compressedFile,0,SEEK_END);
    ftruncate(fileno(compressedFile), ftell(compressedFile) - 1);
}
