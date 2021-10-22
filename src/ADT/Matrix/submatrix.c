#include <stdio.h>
#include "matrix.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 23 September 2021
    Topik: ADT Matriks
    Deskripsi: Implementasi submatrix
*/

int main(){
    int tc = 0;
    int i = 0;
    int m = 0;
    int n = 0;
    int j = 0; 
    int k = 0; 
    int l = 0;
    int o = 0;
    int localMax = 0;
    int val = 0;
    Matrix mak;
    scanf("%d", &tc);
    for(i = 0; i < tc; i++){
        localMax = 0;
        scanf("%d", &n);
        readMatrix(&mak, n, n);
        scanf("%d", &m);

        for(j = 0; j < m; j++){
            for(k = 0; k < m; k++){
                localMax = localMax + ELMT(mak, j, k);
            }
        }
        for(j = 0; j <= n - m; j++){
            for(k = 0; k <= n - m; k++){
                val = 0;
                for(l = j; l < j + m; l++){
                    for(o = k; o < k + m; o++){
                        val = val + ELMT(mak, l, o); /* gaming */
                    }
                }
                if (val > localMax){
                    localMax = val;
                }
            }
        }
        printf("%d\n", localMax);
    }
}