#include "functions.h"


int main() {
    FILE *compressFile;
    if ((compressFile = fopen("D:/Lab2Sem2/cmake-build-debug/compFile.txt", "r")) == NULL)
    {
        printf("Error file\n");
        exit(1);
    }
    int numReplacements;
    char** wordsA;
    char** wordsB;
    wordsA = (char**)malloc(16*sizeof(char*));
    wordsB = (char**)malloc(16*sizeof(char*));
    readWordsFromFile(compressFile,&wordsA,&wordsB,&numReplacements);
    printf("%d\n",numReplacements);

    int length1 = printWordLengths(wordsA,numReplacements)+ printWordLengths(wordsB,numReplacements) + numReplacements*2;
    printf("%d",length1);
    fseek(compressFile,length1,SEEK_SET);
    FILE* decompressFile = fopen("D:/Lab2Sem2/cmake-build-debug/decompFile.txt", "w");


    printCompressedFile(compressFile, decompressFile,wordsA,wordsB,numReplacements);

    fclose(compressFile);
    fclose(decompressFile);

    return 0;
}
