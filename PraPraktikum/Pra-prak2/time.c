/* File: time.h */
/* Tanggal: 01 September 2021 */
/* Definisi ADT TIME */
#include <stdio.h>
#include <math.h>
#include "time.h"

/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    /*Algoritma*/
    return ((H>=0 && H<=23) && (M>=0 && M<=59) && (S>=0 && S<=59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME (int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    /*Kamus*/
    TIME T;
    /*Algoritma*/
    Hour(T) = HH;
    Minute(T) = MM;
    Second(T) = SS;
    return T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
{
    /*Kamus*/
    int h,m,s;
    boolean valid = false;
    /*Algoritma*/
    while(!valid){
        printf("Masukkan jam : ");
        scanf("%d",&h);
        printf("Masukkan menit: ");
        scanf("%d",&m);
        printf("Masukkan detik: ");
        scanf("%d",&s);
        if(!IsTIMEValid(h,m,s)){
            printf("Jam Tidak Valid\n");
        }
        else{
            valid = true;
        }
    }
    *T = MakeTIME(h,m,s);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    /*Algoritma*/
    printf("%02d:%02d:%02d",Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
{
    /*Algoritma*/
    return (3600*Hour(T)+60*Minute(T)+Second(T));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    /*Kamus*/
    int h,m,s;
    /*Algoritma*/
    N%=86400;
    h = N/3600;
    m = (N%3600)/60;
    s = N%60;
    return MakeTIME(h,m,s);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    /*Algoritma*/
    return((Hour(T1)==Hour(T2)) && (Minute(T1)==Minute(T2)) && (Second(T1)==Second(T2)));
}

boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    /*Algoritma*/
    return((Hour(T1)!=Hour(T2)) || (Minute(T1)!=Minute(T2)) || (Second(T1)!=Second(T2)));
}

boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    /*Algoritma*/
    return(TIMEToDetik(T1)<TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
    /*Algoritma*/
    return(TIMEToDetik(T1)>TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
    /*Algoritma*/
    return DetikToTIME(TIMEToDetik(T)+1);
}

TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    /*Algoritma*/
    return DetikToTIME(TIMEToDetik(T)+N);
}

TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    /*Algoritma*/
    return DetikToTIME(TIMEToDetik(T)-1);
}

TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
{
    /*Algoritma*/
    return DetikToTIME(TIMEToDetik(T)-N);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    /*Kamus*/
    long ans;
    /*Algoritma*/
    ans = TIMEToDetik(TAw)-TIMEToDetik(TAkh);
    if(ans<0){
        return ans + 86400;
    }
    else{
        return ans;
    }
}