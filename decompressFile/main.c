#include "functions.h"


int main() {
    FILE *compressFile;
    if ((compressFile = fopen("D:/Lab2Sem2/cmake-build-debug/compFile.txt", "r")) == NULL)
    {
        printf("Error file\n");
        exit(1);
    }

    char* word1 = (char*)calloc(16,sizeof(char));
    char* word2 = (char*)calloc(4,sizeof(char));

    fseek(compressFile, 0, SEEK_END);

    long int fileSize = ftell(compressFile);

    int pos = findPositions(compressFile);
    fseek(compressFile, fileSize - pos, SEEK_SET);
    if (fscanf(compressFile, "$%s $%s", word1, word2) == 2) {
        printf("read word: %s and %s\n", word1, word2);
    }
    fseek(compressFile,0,SEEK_SET);
    fclose(compressFile);


    FILE* decompressFile = fopen("D:/Lab2Sem2/cmake-build-debug/decompFile.txt", "w");
    compressFile = fopen("D:/Lab2Sem2/cmake-build-debug/compFile.txt", "r");
    printCompressedFile(compressFile,decompressFile,word1,word2);
    free(word1);
    free(word2);
    if (decompressFile!=NULL) {
        fclose(decompressFile);
    }
    else printf("error");

    if(compressFile!=NULL) {
        fclose(compressFile);
    }
    else printf("error");


    return 0;
}
