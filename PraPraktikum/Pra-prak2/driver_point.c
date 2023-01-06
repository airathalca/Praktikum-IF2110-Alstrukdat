#include <stdio.h>
#include "point.h"

int main(){
  POINT p1, p2;
  //Membaca point pertama
  printf("Masukan point pertama\n");
  BacaPOINT(&p1);
  printf("Point yang dibaca adalah : ");
  TulisPOINT(p1);
  printf("\n");
  //Membaca point kedua
  printf("Masukan point kedua\n");
  BacaPOINT(&p2);
  printf("Point yang dibaca adalah : ");
  TulisPOINT(p2);
  printf("\n");

  //Mengecek fungsi relasi
  if(EQ(p1,p2)){
    printf("Point 1 dan 2 bernilai sama.\n");
  }
  if(NEQ(p1,p2)){
    printf("Point 1 dan 2 bernilai beda.\n");
  }

  //Menentukan posisi point
  if(IsOrigin(p1)){
      printf("Point 1 berada di titik pusat.\n");
  }
  if(IsOnSbX(p1)){
      printf("Point 1 berada di sumbu x.\n");
  }
  if(IsOnSbY(p2)){
      printf("Point 2 berada di sumbu y.\n");
  }
  if((Absis(p2)!=0) && (Ordinat(p2)!=0)){
      printf("Point 2 berada di kuadran %d\n", Kuadran(p2));
  }

  //Mengecek fungsi posisi Point
  float deltaX, deltaY;
  printf("Masukkan deltaX : ");
  scanf("%f", &deltaX);
  printf("Masukkan deltaY : ");
  scanf("%f", &deltaY);
  printf("Point dengan jarak %f horizontal dan %f vertikal p2 adalah : ", deltaX, deltaY);
  TulisPOINT(PlusDelta(p2,deltaX,deltaY));
  printf("\n");
  printf("Point p2 setelah dicerminkan terhadap sumbu x adalah : ");
  TulisPOINT(MirrorOf(p2,true));
  printf("\n");
  printf("Point satu posisi di sebelah p1 adalah : ");
  TulisPOINT(NextX(p1));
  printf("\n");
  printf("Point satu posisi di atas p1 adalah : ");
  TulisPOINT(NextY(p1));
  printf("\n");

  //Mengecek jarak point
  printf("Jarak p1 ke titik pusat adalah : %.02f\n", Jarak0(p1));
  printf("Jarak p1 dan p2 adalah : %.02f\n", Panjang(p1,p2));

  //Mengubah posisi point
  float geserX,geserY;
  printf("Masukkan geserX : ");
  scanf("%f", &geserX);
  printf("Masukkan geserY : ");
  scanf("%f", &geserY);
  Geser(&p1,geserX,geserY);
  printf("posisi p1 setelah ditranslasi adalah : ");
  TulisPOINT(p1);
  printf("\n"); 

  Mirror(&p1,false);
  printf("posisi p1 setelah dicerminkan terhadap sumbu Y adalah : ");
  TulisPOINT(p1);
  printf("\n");

  float sudut;
  printf("Masukkan sudut : ");
  scanf("%f", &sudut);
  Putar(&p1,sudut);
  printf("posisi p1 setelah dirotasi adalah : ");
  TulisPOINT(p1);
  printf("\n");

  GeserKeSbX(&p2);
  printf("posisi p2 setelah digeser ke sumbu X adalah : ");
  TulisPOINT(p2);
  printf("\n");

  GeserKeSbY(&p2);
  printf("posisi p2 setelah digeser ke sumbu Y adalah : ");
  TulisPOINT(p2);
  printf("\n");

}