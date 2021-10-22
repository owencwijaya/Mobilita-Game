#include <stdio.h>
#include "ADT/Matrix/matrix.c"
#include "ADT/MesinKata/wordmachine.c"
#include "ADT/MesinKata/charmachine.c"

/* prototype fungsi */
int mainMenu();
void configInput();
void title();

/* Fungsi utama yang akan di-run */
void main(){
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu(){
    title();
    printf("========MENU========\n");
    printf("1. New Game\n");
    printf("0. Exit Game\n");
    printf("Masukkan pilihan: \n>>> ");

    int option;
    scanf("%d", &option);
    switch(option){
        case 1:
            /*printf("\nMasukkan direktori file konfigurasi:\nmis. .//config/config.txt\n>>>  ");
            char fileName[100];
            scanf("%s", &fileName);
            */
            configInput("placeholder");
        case 0:
            return 0;
    }
}

void configInput(char fileName[100]){
    FILE *file;
    char temp[100];
    printf("Nama file: %s\n\n", fileName);
    file = fopen(".//config/dummyConfig.txt", "r"); // hardcoded dulu sementara, buat ngetes
    if (file != NULL){ //pake algo mesin kata?
        fscanf(file, "%s", temp);
        printf("%s", temp);
    } else {
        printf("File tidak ditemukan. Kembali ke menu utama....\n");
        mainMenu();
    }
}

void title(){
    printf("  __                         \n");
    printf(" /  )  _ _ _ _      (   //   \n");
    printf("/(_/()/ (-(///)()/) |/|//)(/ \n");
    printf("                          /  \n");
}