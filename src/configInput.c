#include <stdio.h>
#include "ADT/Matrix/matrix.c"
#include "ADT/MesinKata/tokenmachine.c"
#include "ADT/MesinKata/charmachine.c"

void StringToMatrix(char temp[100]);


void configInput(char fileName[100]){
    FILE *file;
    char temp[255];
    printf("Nama file: %s\n\n", fileName);
    file = fopen(".//config/dummyConfig.txt", "r"); // hardcoded dulu sementara, buat ngetes
    if (file != NULL){ //pake algo mesin kata
        fscanf(file, "%[^\n]", temp);
        StringToMatrix(temp);
    } else {
        printf("File tidak ditemukan. Kembali ke menu utama....\n");
        mainMenu();
    }
}

void StringToMatrix(char temp[100]){
    int rows;
    int cols;
    startToken(); 
    printf("%d", currentToken.val);
}