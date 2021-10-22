#include <stdio.h>
#include "matrix.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Jum'at, 17 September 2021
    Topik: ADT Matriks
    Deskripsi: Implementasi ADT Matriks
*/

void CreateMatrix(int nRow, int nCol, Matrix *m){
    /* Membuat matriks baru sesuai ukuran baris - kolom
    yang diinginkan */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

boolean isIdxValid(int i, int j){
    /* Mengembalikan true apabila i dan j di bawah
    nilai kapasitas */
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

Index getLastIdxRow(Matrix m){
    /* Mengembalikan nilai indeks 
    kolom efektif maksimal matriks */
    return (ROWS(m) - 1);
}

Index getLastIdxCol(Matrix m){
    /* Mengembalikan nilai indeks 
    baris efektif maksimal matriks */
    return (COLS(m) - 1);
}

boolean isIdxEff(Matrix m, Index i, Index j){
    /* Mengembalikan true apabila i dan j di bawah
    nilai indeks efektif */
    return ((i >= 0 && i < ROWS(m)) && (j >= 0 && j < COLS(m)));
}

ElType getElmtDiagonal(Matrix m, Index i){
    /* Mengembalikan nilai elemen diagonal i, i*/
    return(ELMT(m, i, i));
}

void copyMatrix(Matrix mIn, Matrix *mRes){
    /* Menyalin matriks mIn ke matriks mRes */

    /* Kamus */
    int i = 0;
    int j = 0;

    /* Algoritma */
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for(i = 0; i < ROWS(mIn); i++){
        for(j = 0; j < COLS(mIn); j++){
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    /* Membaca input angka ke matriks */

    /* Kamus */
    int i = 0;
    int j = 0;
    int element = 0;

    /* Algoritma */
    CreateMatrix(nRow, nCol, m);
    for(i = 0; i < nRow; i++){
        for(j = 0; j < nCol; j++){
            scanf("%d", &element);
            ELMT(*m, i ,j) = element;
        }
    }
}

void displayMatrix(Matrix m){
    /* Memberikan keluaran matriks */

    /* Kamus */
    int i = 0;
    int j = 0;

    /* Algoritma */
    for(i = 0; i < ROWS(m); i++){
        for(j = 0; j < COLS(m); j++){
            printf("%d", ELMT(m, i , j));
            if(j != COLS(m) - 1){
                printf(" ");
            }
        }
        if (i != ROWS(m) - 1){
            printf("\n");
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    /* Mengembalikan matriks hasil penjumlahan dua matriks */

    /* Kamus */
    int i = 0; 
    int j = 0;
    Matrix result;

    /* Algoritma */
    CreateMatrix(ROWS(m1), COLS(m1), &result);
    
    for(i = 0; i < ROWS(result); i++){
        for(j = 0; j < COLS(result); j++){
            ELMT(result, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    /* Mengembalikan matriks hasil pengurangan dua matriks */

    /* Kamus */
    int i = 0; 
    int j = 0;
    Matrix result;

    /* Algoritma */
    CreateMatrix(ROWS(m1), COLS(m1), &result);
    
    for(i = 0; i < ROWS(result); i++){
        for(j = 0; j < COLS(result); j++){
            ELMT(result, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return result;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    /* Mengembalikan matriks hasil perkalian dua matriks */

    /* Kamus */
    int i = 0; 
    int j = 0;
    int k = 0;
    Matrix result;
    
    /* Algoritma */
    CreateMatrix(ROWS(m1), COLS(m2), &result);

    for(i = 0; i < ROWS(m1); i++){
        for(j = 0; j < COLS(m2); j++){
            int res = 0;
            for(k = 0; k < ROWS(m2); k++){
                res = res + ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(result, i, j) = res;
        }
    }
    return result;
}

Matrix multiplyConst(Matrix m, ElType x){
    /* Mengembalikan matriks yang isinya
    perkalian tiap elemen matriks m dengan konstanta x */

    /* Kamus */
    int i = 0;
    int j = 0;
    Matrix result;

    /* Algoritma */
    CreateMatrix(ROWS(m), COLS(m), &result);
    
    for(i = 0; i < ROWS(result); i++){
        for(j = 0; j < COLS(result); j++){
            ELMT(result, i, j) = x * ELMT(m, i, j);
        }
    }
    return result;
}

void pMultiplyConst(Matrix *m, ElType k){
    /* Mengalikan tiap elemen matriks dengan konstanta x */

    /* Kamus */
    int i = 0; 
    int j = 0;

    /* Algoritma */
    for(i = 0; i < ROWS(*m); i++){
        for(j = 0; j < COLS(*m); j++){
            ELMT(*m, i, j) = k * ELMT(*m, i, j);
        }
    }
}

int count(Matrix m){
    /* Menghitung jumlah elemen di matriks */
    return (COLS(m) * ROWS(m));
}

boolean isSizeEqual(Matrix m1, Matrix m2){
    /* Mengembalikan true apabila ukuran m1 dan m2 sama */
    return (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2));
}

boolean isEqual(Matrix m1, Matrix m2){
    /* Mengembalikan true apabila ukuran m1 dan m2 sama,
    apabila setiap m1(i,j) == m2(i, j) */

    /* Kamus */
    int i = 0;
    int j = 0;
    boolean equal = false;

    /* Algoritma */
    if (isSizeEqual){
        equal = true;
        for(i = 0; i < ROWS(m1); i++){
            for(j = 0; j < COLS(m1); j++){
                if(ELMT(m1, i, j) != ELMT(m2, i, j)){
                    equal = false;
                }
            }
        }
    }

    return (equal && isSizeEqual(m1, m2));
}

boolean isNotEqual(Matrix m1, Matrix m2){
    /* Mengembalikan true apabila m1 != m2 */
    return(!isEqual(m1, m2));
}

boolean isSquare(Matrix m){
    /* Mengembalikan true apabila ukuran matriks m kotak */
    return(ROWS(m) == COLS(m));
}

boolean isSymmetric(Matrix m){
    /* Mengembalikan true apabila matriks m simetris */
    
    /* Kamus */
    int i = 0;
    int j = 0;
    boolean symmetric = true;

    /* Algoritma */
    for(i = 0; i < ROWS(m); i++){
        for(j = 0; j < COLS(m); j++){
            if(ELMT(m, i, j) != ELMT(m, j, i)){
                symmetric = false;
            }
        }
    }
    return symmetric;
}
boolean isIdentity(Matrix m){
    /* Mengembalikan true apabila matriks m adalah matriks identitas */
    
    /* Kamus */
    int i = 0;
    int j = 0;
    boolean identity = true;
    boolean others =  true;

    /* Algoritma */
    for(i = 0; i < ROWS(m); i++){
        for(j = 0; j < COLS(m); j++){
            if (ELMT(m, i, j) != 1 && i == j){
                identity = false;
            }
            if (ELMT(m, i, j) != 0 && i != j){
                others = false;
            }
        }
    }
    return(identity && others);
}

boolean isSparse(Matrix m){
    /* Mengembalikan true apabila sparsity matriks m
    di bawah 0.05 */

    /* Kamus */
    int not0 = 0;
    int i = 0;
    int j = 0;
    int sparsity;

    /* Algoritma */
    for (i = 0; i < ROWS(m); i++){
        for(j = 0; j < COLS(m); j++){
            if(ELMT(m, i, j) != 0){
                not0++;
            }
        }
    }
    sparsity = not0 * 100 / count(m);
    return (sparsity < 5);
}

Matrix inverse1 (Matrix m){
    /* Mengembalikan matriks hasil invers matriks m */

    /* Kamus */
    Matrix result;

    /* Algoritma */
    CreateMatrix(ROWS(m), COLS(m), &result);
    int i = 0;
    int j = 0;
    for(i = 0; i < ROWS(m); i++){
        for(j = 0; j < COLS(m); j++){
            ELMT(result, i, j) = -1 * ELMT(m, i, j);
        }
    }
    return result;
}

void pInverse1(Matrix *m){
    /* Mengubah matriks m menjadi matriks inversnya */

    /* Kamus */
    int i = 0;
    int j = 0;

    /* Algoritma */
    for(i = 0; i < ROWS(*m); i++){
        for(j = 0; j < COLS(*m); j++){
            ELMT(*m, i, j) = -1 * ELMT(*m, i, j);
        }
    }
}

float determinant(Matrix m){
    /* Mengembalikan nilai determinan matriks m */
    /* Kamus */
    int i = 0;
    int j = 0;
    int k = 0;
    int colCount = 0;
    int rowCount = 0;
    Matrix temp;
    float det;
    
    /* Algoritma */
    CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &temp);

    if(count(m) == 4){
        return (ELMT(m, 0, 0) * ELMT(m, 1, 1) - (ELMT(m, 1, 0) * ELMT(m, 0, 1)));
    } else {
        det = 0;
        for(i = 0; i < COLS(m); i++){
            if(ELMT(m, 0, i) != 0){
                rowCount = 0;
                for(j = 0; j < ROWS(m); j++){
                    colCount = 0;
                    for(k = 0; k < COLS(m); k++){
                        if (k != i){
                            ELMT(temp, rowCount, colCount) = ELMT(m, j, k);
                            colCount = colCount + 1;
                        }
                    }
                    if(j != 0){
                        rowCount = rowCount + 1;
                    }
                }   
            if (i % 2 == 0){
                det = det + ELMT(m, 0, i) * determinant(temp);
            } else {
                det = det + -1 * ELMT(m, 0, i) * determinant(temp);
            }
            }    
        }
    }
    return det;
}

void transpose (Matrix *m){
    /* Mengubah matriks m menjadi matriks transpose */
    
    /* Kamus */
    int i = 0;
    int j = 0;
    Matrix result;

    /* Algoritma */
    CreateMatrix(COLS(*m), ROWS(*m), &result);
    
    for(i = 0; i < COLS(*m); i++){
        for(j = 0; j < ROWS(*m); j++){
            ELMT(result, i, j) = ELMT(*m, j, i);
        }
    }
    *m = result;
} 

