#include <stdio.h>
#include "ADT/Matrix/matrix.c"
#include "ADT/MesinKata/tokenmachine.c"
#include "ADT/gameMatrix.h"

//ADT modifikasi matriks untuk return 3 matriks

gameMatrix configInput(char fileName[100]){ //ini nanti sesuaiin sama struct Raden
    startWithPath(".//config/dummyConfig.txt");
    gameMatrix GM; //ini nanti sesuaiin sama struct Raden

    // Pembuatan Matriks Peta
    /* akuisisi ukuran matriks */
    int rows; int cols; Matrix map;
    rows = currentToken.val; advToken();
    cols = currentToken.val; advToken();
    CreateMatrix(rows, cols, &map);

    /* akuisisi koordinat matriks */
    int HQX; int HQY;
    HQX = currentToken.val; advToken();
    HQY = currentToken.val; advToken();
    ELMT(map, HQX - 1, HQY - 1) = '8';

    /* akuisisi jumlah query */
    int query = currentToken.val; advToken();
    int i = 0; int j = 0; int tempX; int tempY; char CharLocation;

   
    for (i = 0; i < query; i++){
        CharLocation = currentToken.tkn; advToken(); 
        tempX = currentToken.val; advToken();
        tempY = currentToken.val; advToken();
        ELMT(map, tempX - 1, tempY - 1) = CharLocation;
    }

    //Matriks adjacency
    Matrix AdjM;
    CreateMatrix(query + 1, query + 1, &AdjM);
    for(i = 0; i < AdjM.rowEff; i++){
        for(j = 0; j < AdjM.rowEff; j++){
            ELMT(AdjM, i, j) = currentToken.val;
            advToken();
        }
    }

    //Matriks pesanan
    Matrix OrderM;
    int order = currentToken.val; advToken();
    CreateMatrix(order, 5, &OrderM);
    for(i = 0; i < order; i++){
        for(j = 0; j < 5; j++){
            if (j == 0){
                ELMT(OrderM, i, j) = currentToken.val;
                advToken();
            } else if (j == 4){
                if (ELMT(OrderM, i, 3) == 'P'){
                    advToken();
                    ELMT(OrderM, i, j) = currentToken.val;
                } else {
                    ELMT(OrderM, i, j) = 0;
                }
                advToken();
            } else if (j == 3){
                ELMT(OrderM, i, j) = currentToken.tkn;
            } else {
                ELMT(OrderM, i, j) = currentToken.tkn;
                advToken();
            }
        }
    }
    //ini nanti sesuaiin sama struct Raden
    GM.map = map;
    GM.AdjM = AdjM;
    GM.OrderM = OrderM;
    return GM;
}
