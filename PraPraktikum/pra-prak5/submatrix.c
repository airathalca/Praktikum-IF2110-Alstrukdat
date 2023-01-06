/*Nama : Aira Thalca Avila Putra*/
/*NIM  : 13520101*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    int tc,n,x,max,curi;
    Matrix m,sum;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        readMatrix(&m,n,n);
        CreateMatrix(n,n,&sum);
        ELMT(sum,0,0)=ELMT(m,0,0);
        for (int i=1;i<n;i++){
            ELMT(sum,i,0) = ELMT(sum,i-1,0)+ELMT(m,i,0);
        }
        for (int j=1;j<n;j++){
            ELMT(sum,0,j) = ELMT(sum,0,j-1)+ELMT(m,0,j);
        }
        for (int i=1; i<n;i++){
            for (int j=1; j<n;j++){
                ELMT(sum,i,j) = ELMT(m,i,j) + ELMT(sum,i-1,j) + ELMT(sum,i,j-1) - ELMT(sum,i-1,j-1);
            }
        }
        scanf("%d",&x);
        max = 0;
        for (int i=x-1;i<n;i++){
            for (int j=x-1;j<n;j++){
                curi = ELMT(sum,i,j);
                if (i - x>=0){
                    curi -= ELMT(sum,i-x,j);
                }
                if (j - x>=0){
                    curi -= ELMT(sum,i,j-x);
                }
                if ((i-x>=0)&&(j-x>=0)){
                    curi += ELMT(sum,i-x,j-x);
                }
                if (curi>max){
                    max = curi;
                }
            }
        }
        printf("%d\n", max);
    }
}