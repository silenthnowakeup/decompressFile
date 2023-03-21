if (decompressFile!=NULL) {
        fclose(decompressFile);
    }
    else printf("error");
    
    if(compressFile!=NULL) {
        fclose(compressFile);
    }
    else printf("error");
