#include <stdio.h>
#include "time.h"

int main(){
  TIME t1;
  printf("Masukan waktu\n");
  BacaTIME(&t1);
  printf("Waktu yang dibaca adalah : ");
  TulisTIME(t1);
  printf("\n");

  //Mengubah TIME menjadi detik
  long a = TIMEToDetik(t1);
  printf("Saat diubah ke detik menjadi : %li\n", a);
  printf("\n");

  //Inisialisasi time baru
  long detik;
  printf("Masukan detik: ");
  scanf("%d", &detik);
  TIME t2 = DetikToTIME(detik);
  printf("Jika diubah ke bentuk time menjadi: ");
  TulisTIME(t2);
  printf("\n");

  //Mengecek fungsi relasi
  if(TEQ(t1,t2)){
    printf("Waktu pertama dan kedua bernilai sama.\n");
  }
  if(TNEQ(t1,t2)){
    printf("Waktu pertama dan kedua bernilai beda.\n");
  }
  if(TLT(t1,t2)){
    printf("Waktu kedua bernilai lebih besar.\n");
  }
  if(TGT(t1,t2)){
    printf("Waktu pertama bernilai lebih besar.\n");
  }

  //Mengecek fungsi detik
  TIME c;
  c = NextDetik(t2);
  printf("1 detik selanjutnya adalah: ");
  TulisTIME(c);
  printf("\n");

  c = PrevDetik(t2);
  printf("1 detik sebelumnya adalah: ");
  TulisTIME(c);
  printf("\n");

  int N;
  printf("Masukan N: ");
  scanf("%d", &N);

  c = NextNDetik(t2, N);
  printf("N detik selanjutnya adalah: ");
  TulisTIME(c);
  printf("\n");

  c = PrevNDetik(t2, N);
  printf("N detik sebelumnya adalah: ");
  TulisTIME(c);
  printf("\n");

  //Mengecek fungsi durasi
  long d = Durasi(t1, t2);
  printf("\nJarak nya dalam detik ialah %li detik", d);
}