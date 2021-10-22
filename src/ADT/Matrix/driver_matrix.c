#include <stdio.h>
#include "matrixop.c"
#define endl printf("\n");
#define print(n) displayMatrix(n);endl;

void yesnt(boolean bool){
    bool ? printf("yes") : printf("no"); endl;
}

int main(){
    Matrix m;
    readMatrix(&m, 3, 4);
    displayMatrix(m);endl;
    printf("%f %f\n", rowMean(m, 1), colMean(m, 0));
    ElType max, min;
    displayMatrix(m);endl;
    rowExtremes(m, 0, &max, 
    &min);
    printf("%d %d\n", max, min);
    colExtremes(m, 0, &max, &min);
    printf("%d %d\n", max, min);
    printf("%d %d", countValOnCol(m, 0, 2), countValOnRow(m, 0, 2));

    





    /*
    Matrix m2;
    readMatrix(&m2, 3, 3);
    displayMatrix(m2);endl;
     yesnt(isEqual(m, m2));
    Matrix mCopy;
    copyMatrix(m, &mCopy);
    print(mCopy);
    print(addMatrix(m, mCopy));
    print(subtractMatrix(m, mCopy));
    print(multiplyConst(m, 2));
    print(multiplyMatrix(m, m2));
   
    pMultiplyConst(&mCopy, 2);
    displayMatrix(mCopy);endl;
    yesnt(isSymmetric(m));
    yesnt(isIdentity(m));
    yesnt(isIdentity(m2));
    yesnt(isSparse(m));
    print(inverse1(m));
    pInverse1(&m);
    print(m);
    transpose(&m);

    */
}
