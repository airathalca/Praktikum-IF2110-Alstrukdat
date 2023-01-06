#include <stdio.h>
#include <math.h>
#include "garis.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
    /*Algoritma*/
    PAwal(*L)=P1;
    PAkhir(*L)=P2;
}

void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
{
    /*Kamus*/
    float a,b,c,d;
    POINT P1,P2;
    /*Alforitma*/
    do{
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    } while (EQ(P1,P2));
    MakeGARIS(P1,P2,L);
}

void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
    /*Algoritma*/
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)),Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : berikan rumusnya */
/*rumus = sqrt(pow(Absis(P1)-Absis(P2),2) + pow(Ordinat(P1)-Ordinat(P2),2))*/
{
    /*Algoritma*/
    return Panjang(PAwal(L),PAkhir(L));
}

float Gradien (GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    /*Algoritma*/
    return (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
    /*Algoritma*/
    Geser(&(PAwal(*L)), deltaX, deltaY);
    Geser(&(PAkhir(*L)), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
    /*Algoritma*/
    return (Gradien(L1)*Gradien(L2)==-1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    /*Algoritma*/
    return (Gradien(L1)==Gradien(L2));
}