/*Nama : Aira Thalca Avila Putra*/
/*NIM  : 13520101*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void CreateMatrix(int nRow, int nCol, Matrix *m){
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

boolean isIdxValid(int i, int j){
    return ((i>=0 && i<ROW_CAP) && (j>=0 && j<COL_CAP));
}

Index getLastIdxRow(Matrix m){
    return ROWS(m)-1;
}

Index getLastIdxCol(Matrix m){
    return COLS(m)-1;
}

boolean isIdxEff(Matrix m, Index i, Index j){
    return ((i>=0 && i<=getLastIdxRow(m)) && (j>=0 && j<=getLastIdxCol(m)));
}

ElType getElmtDiagonal(Matrix m, Index i){
    return (ELMT(m,i,i));
}

void copyMatrix(Matrix mIn, Matrix *mRes){
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (int i=0;i<=getLastIdxRow(mIn);i++){
        for (int j=0;j<=getLastIdxCol(mIn);j++){
            ELMT(*mRes,i,j) = ELMT(mIn,i,j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol){
    CreateMatrix(nRow, nCol,m);
    for (int i=0;i<=getLastIdxRow(*m);i++){
        for (int j=0;j<=getLastIdxCol(*m);j++){
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}

void displayMatrix(Matrix m){
    for (int i=0;i<=getLastIdxRow(m);i++){
        for (int j=0;j<=getLastIdxCol(m);j++){
            if(j==getLastIdxCol(m)){
                printf("%d",ELMT(m,i,j));
            }
            else{
                printf("%d ", ELMT(m,i,j));
            }
            if ((i < getLastIdxRow(m)) && (j==getLastIdxCol(m))){
                printf("\n");
            }
        }
    }
}

Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix answer;
    CreateMatrix(ROWS(m1),COLS(m1),&answer);
    for (int i=0;i<=getLastIdxRow(m1);i++){
        for (int j=0;j<=getLastIdxCol(m1);j++){
            ELMT(answer,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return answer;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix answer;
    CreateMatrix(ROWS(m1),COLS(m1),&answer);
    for (int i=0;i<=getLastIdxRow(m1);i++){
        for (int j=0;j<=getLastIdxCol(m1);j++){
            ELMT(answer,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return answer;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix answer;
    CreateMatrix(ROWS(m1),COLS(m2),&answer);
    for (int i=0;i<=getLastIdxRow(m1);i++){
        for (int j=0;j<=getLastIdxCol(m2);j++){
            ELMT(answer,i,j) = 0;
            for (int k = 0; k < COLS(m1); k++) {
                ELMT(answer,i,j) += ELMT(m1,i,k)*ELMT(m2,k,j);
            }
        }
    }
    return answer;
}

Matrix multiplyConst(Matrix m, ElType x){
    Matrix answer;
    CreateMatrix(ROWS(m),COLS(m),&answer);
    for (int i=0;i<=getLastIdxRow(m);i++){
        for (int j=0;j<=getLastIdxCol(m);j++){
            ELMT(answer,i,j) = ELMT(m,i,j)*x;
        }
    }
    return answer;
}

void pMultiplyConst(Matrix *m, ElType k){
    copyMatrix(multiplyConst(*m, k), m);
}

boolean isEqual(Matrix m1, Matrix m2){
    if(!isSizeEqual(m1,m2)){
        return false;
    }
    else{
        int i=0;
        boolean same = true;
        while ((i <= getLastIdxRow(m1)) && same){
            int j = 0;
            while ((j<=getLastIdxCol(m1)) && same){
                if (ELMT(m1,i,j)!=ELMT(m2,i,j)){
                    same = false;
                }
                j++;
            }
            i++;
        }
        return same;
    }
}

boolean isNotEqual(Matrix m1, Matrix m2){
    if (isEqual(m1,m2)){
        return false;
    }
    else{
        return true;
    }
}

boolean isSizeEqual(Matrix m1, Matrix m2){
    return((ROWS(m1)==ROWS(m2)) && (COLS(m1)==COLS(m2)));
}

int count(Matrix m){
    return (ROWS(m)*COLS(m));
}

boolean isSquare(Matrix m){
    return (ROWS(m)==COLS(m));
}

boolean isSymmetric(Matrix m){
    if(!isSquare(m)){
        return false;
    }
    else{
        int i=0;
        boolean same = true;
        while ((i <= getLastIdxRow(m)) && same){
            int j = 0;
            while ((j<=getLastIdxCol(m)) && same){
                if (ELMT(m,i,j)!=ELMT(m,j,i)){
                    same = false;
                }
                j++;
            }
            i++;
        }
        return same;
    }
}

boolean isIdentity(Matrix m){
    if(!isSquare(m)){
        return false;
    }
    else{
        int i=0;
        boolean same = true;
        while ((i <= getLastIdxRow(m)) && same){
            int j = 0;
            while ((j<=getLastIdxCol(m)) && same){
                if ((i==j)&&(ELMT(m,i,j)!=1)){
                    same = false;
                }
                if((i!=j)&&(ELMT(m,i,j)!=0)){
                    same = false;
                }
                j++;
            }
            i++;
        }
        return same;
    }
}

boolean isSparse(Matrix m){
    int nonzero = 0;
    for (int i = 0; i <= getLastIdxRow(m); i++){
        for (int j = 0; j <= getLastIdxCol(m); j++){
            if(ELMT(m,i,j)!=0){
                nonzero+=1;
            }
            if(20*nonzero > count(m)){
                break;
            }
        }
        if(20*nonzero > count(m)){
            break;
        }
    }
    return (count(m) >= 20*nonzero);
}

Matrix inverse1(Matrix m){
    return multiplyConst(m, -1);
}

void pInverse1(Matrix *m){
    pMultiplyConst(m, -1);
}

float cofactor(Matrix m, Index a, Index b){
    Index i, j, iHasil, jHasil;
    Matrix mHasil;
    float hasil;
    hasil = 0;
    CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &mHasil);

    iHasil = 0;
    for (i = 0; i <= getLastIdxRow(m); i++) {
        jHasil = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            if (i == a) {
                iHasil = i - 1;
            } else if (j == b) {
                jHasil = j - 1;
            } else {
                ELMT(mHasil, iHasil, jHasil) = ELMT(m, i, j);
            }
            jHasil++;
        }
        iHasil++;
    }
    if ((a + b) % 2 == 0) {
        hasil = determinant(mHasil);
    } else {
        hasil = -1 * determinant(mHasil);
    }

    return hasil;
}
float determinant(Matrix m){
    Index i, j;
    float hasil;

    hasil = 0;

    if (count(m) == 1) {
        hasil = (float) ELMT(m, 0, 0);
    } else {
        i = 0;
        for (j = 0; j <= getLastIdxCol(m); j++) {
            hasil += ((float) ELMT(m, i, j)) * cofactor(m, i, j);
        }
    }
    return hasil;
}

void transpose(Matrix *m){
    int temp;

    for (int i=0;i<=getLastIdxRow(*m);i++){
        for (int j=i+1;j<=getLastIdxCol(*m);j++){
            temp = ELMT(*m,i,j);
            ELMT(*m,i,j) = ELMT(*m,j,i);
            ELMT(*m,j,i) = temp;
        }
    }
}

float rowMean (Matrix m, Index i){
    int count = 0;
    for (int j=0;j<=getLastIdxCol(m);j++){
        count += ELMT(m,i,j);
    }
    return count/COLS(m);
}

float colMean (Matrix m, Index j){
    int count = 0;
    for (int i=0;i<=getLastIdxRow(m);i++){
        count += ELMT(m,i,j);
    }
    return count/ROWS(m);
}

void rowExtremes (Matrix m, Index i, ElType * max, ElType * min){
    *max = ELMT(m,i,0);
    *min = ELMT(m,i,0);
    for (int j=0;j<=getLastIdxCol(m);j++){
        if (ELMT(m,i,j)>*max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j)<*min){
            *min = ELMT(m,i,j);
        }
    }
}

void colExtremes (Matrix m, Index j, ElType * max, ElType * min){
    *max = ELMT(m,0,j);
    *min = ELMT(m,0,j);
    for (int i=0;i<=getLastIdxRow(m);i++){
        if (ELMT(m,i,j)>*max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j)<*min){
            *min = ELMT(m,i,j);
        }
    }
}

int countValOnRow (Matrix m, Index i, ElType val){
    int count = 0;
    for (int j=0;j<=getLastIdxCol(m);j++){
        if (ELMT(m,i,j)==val){
            count++;
        }
    }
    return count;
}

int countValOnCol (Matrix m, Index j, ElType val){
    int count = 0;
    for (int i=0;i<=getLastIdxRow(m);i++){
        if (ELMT(m,i,j)==val){
            count++;
        }
    }
    return count;
}

