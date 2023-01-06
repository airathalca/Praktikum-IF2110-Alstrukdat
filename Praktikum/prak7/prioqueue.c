/*
NIM                 : 13520101
Nama                : Aira Thalca Avila Putra
Topik praktikum     : Priority Queue
Deskripsi           : Program Priority Queue
*/

#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

void CreatePrioQueue(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq){
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq){
    return (IDX_TAIL(pq)==CAPACITY-1 && IDX_HEAD(pq)==0);
}

int length(PrioQueue pq){
      if(isEmpty(pq)){
    return 0;
  }
  return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
}

void enqueue(PrioQueue *pq, ElType val){
    if(isEmpty(*pq)){
        IDX_TAIL(*pq)=0;
        IDX_HEAD(*pq)=0;
        TAIL(*pq) = val;
    }
    else{
        if(IDX_TAIL(*pq)==CAPACITY-1){
            for(int i=IDX_HEAD(*pq);i<=IDX_TAIL(*pq);i++){
                pq->buffer[i-IDX_HEAD(*pq)] = pq->buffer[i];
            }
            IDX_TAIL(*pq) = IDX_TAIL(*pq)-IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        IDX_TAIL(*pq)++;
        TAIL(*pq) = val;
        int i = IDX_TAIL(*pq);
        int j = IDX_TAIL(*pq)-1;
        ElType temp;
        while (i!=IDX_HEAD(*pq) && (pq->buffer[i].score > pq->buffer[j].score)){
            temp = pq->buffer[i];
            pq->buffer[i] = pq->buffer[j];
            pq->buffer[j] = temp;
            i = j;
            j = i-1;
        }
    }
}

void dequeue(PrioQueue * pq, ElType *val){
    *val = HEAD(*pq);
    if(length(*pq)==1){
        IDX_HEAD(*pq)=IDX_UNDEF;
        IDX_TAIL(*pq)=IDX_UNDEF;
    }
    else{
        IDX_HEAD(*pq)++;
    }
}
