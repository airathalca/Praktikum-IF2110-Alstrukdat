/*
NIM                 : 13520101
Nama                : Aira Thalca Avila Putra
Topik praktikum     : Queue
Deskripsi           : Program antrian Kereta
*/

#include <stdio.h>
#include "queue.h"

float avgElmt (Queue Q){
    ElType val;
    ElType sum=0;
    float ans;
    int len = length(Q);
    while(length(Q)!=0){
        sum+=HEAD(Q);
        dequeue(&Q,&val);
    }
    ans = (float)sum/(float)len;
    return ans;
}

int main(){
    Queue x;
    CreateQueue(&x);
    while(true){
        int y;
        scanf("%d",&y);
        if(y==0){
            printf("%d\n",length(x));
            if(length(x)==0){
                printf("Tidak bisa dihitung\n");
            }
            else{
                float ans = avgElmt(x);
                printf("%.2f\n",ans);
            }
            break;
        }
        else if(y==1){
            ElType val;
            scanf("%d",&val);
            if(isFull(x)){
                printf("Queue penuh\n");
            }
            else{
                enqueue(&x,val);
            }
        }
        else if(y==2){
            int value;
            if(isEmpty(x)){
                printf("Queue kosong\n");
            }
            else{
                dequeue(&x,&value);
            }
        }
    }
}