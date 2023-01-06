/*
NIM                 : 13520101
Nama                : Aira Thalca Avila Putra
Topik praktikum     : Priority Queue
Deskripsi           : Program Priority Queue
*/

#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    PrioQueue q;
    CreatePrioQueue(&q);
    int tc;
    scanf("%d",&tc);
    if (tc==0){
        printf("Tidak ada layanan\n");
    }
    else{
        int time = 1;
        int timeFinish = 1;
        boolean layan = false;
        for (int i=0;i<tc;i++){
            ElType x;
            ElType val;
            scanf("%d %d %d %d", &x.tArrival, &x.id, &x.score,&x.dService);
            if(x.tArrival>timeFinish && !isEmpty(q)){
                layan=false;
                while(!layan){
                    time=timeFinish;
                    layan=true;
                    dequeue(&q,&val);
                    printf("%d %d %d\n",time,val.id,time-val.dService);
                    timeFinish=time+val.dService;
                    if(!isEmpty(q) && HEAD(q).tArrival>=timeFinish){
                        layan=false;
                        time+=val.dService;
                    }
                }
            }
            enqueue(&q,x);
            time=x.tArrival;
            if(timeFinish<=time){
                layan=false;
            }
            while(!layan){
                layan=true;
                dequeue(&q,&val);
                printf("%d %d %d\n",time,val.id,time-val.tArrival);
                timeFinish=time+val.dService;
                if(!isEmpty(q) && HEAD(q).tArrival>=timeFinish){
                    layan=false;
                    time+=val.dService;
                }
            }
            if(i==tc-1 && !isEmpty(q)){
                time=timeFinish;
                while(!isEmpty(q)){
                    dequeue(&q,&val);
                    printf("%d %d %d\n",time,val.id,time-val.tArrival);
                    time=time+val.dService;
                }
            }
        }
    }
}