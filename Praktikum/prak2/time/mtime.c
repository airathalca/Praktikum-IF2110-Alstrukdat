#include<stdio.h>
#include "time.h"

int main(){
    int tc;
    scanf("%d",&tc);
    TIME T_max,T_min;
    T_max = MakeTIME(00,00,00);
    T_min = MakeTIME(23,59,59);
    while (tc--){
        TIME T1,T2;
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (TLT(T1,T2)){
            printf("%d\n", Durasi(T2,T1));
            if (TLT(T1,T_min)){
                    T_min = T1;
            }
            if (TGT(T2,T_max)){
                    T_max = T2;
            }
        }
        else if(TGT(T1,T2)){
            printf("%d\n", Durasi(T1,T2));
            if (TLT(T2,T_min)){
                    T_min = T2;
            }
            if (TGT(T1,T_max)){
                    T_max = T1;
            }
        }
        else{
            printf("%d\n", 0);
            if (TGT(T1,T_max)){
                    T_max = T1;
            }
            if (TLT(T1,T_min)){
                    T_min = T1;
            }
        }
    }
    TulisTIME(T_min);
    printf("\n");
    TulisTIME(T_max);
}