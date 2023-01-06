/* File : point.c*/
/* Tanggal : 01 September 2021*/
/* Body ADT Time */
#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    /*Kamus*/
    POINT P;
    /*Algoritma*/
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
{
    /*Kamus*/
    float a,b;
    /*Alforitma*/
    printf("Masukkan absis : ");
    scanf("%f",&a);
    printf("Masukkan ordinat : ");
    scanf("%f",&b);
    *P = MakePOINT(a,b);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
{
    /*Algoritma*/
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    /*Algoritma*/
    return((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    /*Algoritma*/
    return((Absis(P1)!=Absis(P2)) || (Ordinat(P1)!=Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    /*Algoritma*/
    return((Absis(P)==0) && (Ordinat(P)==0));
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    /*Algoritma*/
    return(Ordinat(P)==0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    /*Algoritma*/
    return(Absis(P)==0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    /*Algoritma*/
    if(Absis(P)>0){
        if(Ordinat(P)>0){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        if(Ordinat(P)>0){
            return 2;
        }
        else{
            return 3;
        }
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */    
{
    /*Algoritma*/
    return MakePOINT(Absis(P)+1,Ordinat(P));
}         

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    /*Algoritma*/
    return MakePOINT(Absis(P),Ordinat(P)+1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    /*Algoritma*/
    return MakePOINT(Absis(P)+deltaX,Ordinat(P)+deltaY);
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    /*Algoritma*/
    if(SbX){
        return MakePOINT(Absis(P),-Ordinat(P));
    }
    else{
        return MakePOINT(-Absis(P),Ordinat(P));
    }
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    /*Algoritma*/
    return sqrt(pow(Absis(P),2) + pow(Ordinat(P),2));
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
{
    /*Algoritma*/
    return sqrt(pow(Absis(P1)-Absis(P2),2) + pow(Ordinat(P1)-Ordinat(P2),2));
}

void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    /*Algoritma*/
    Absis(*P)+=deltaX;
    Ordinat(*P)+=deltaY;
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
{
    /*Algoritma*/
    Ordinat(*P)=0;
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
{
    /*Algoritma*/
    Absis(*P)=0;
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    if(SbX){
        Ordinat(*P)*=(-1);
    }
    else{
        Absis(*P)*=(-1);
    }
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    /*Kamus*/
    double rad;
    /*Algoritma*/
    rad = M_PI/180;
    Absis(*P) = cos(Sudut*rad)*Absis(*P) + sin(Sudut*rad)*Ordinat(*P);
    Ordinat(*P) = cos(Sudut*rad)*Ordinat(*P) - sin(Sudut*rad)*Absis(*P);
}