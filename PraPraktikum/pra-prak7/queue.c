//Nama = Aira Thalca Avila Putra
//Nim = 13520101

#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    return (IDX_TAIL(q)==CAPACITY-1 && IDX_HEAD(q)==0);
}

int length(Queue q){
  if(isEmpty(q)){
    return 0;
  }
  return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void enqueue(Queue *q, ElType val){
    if(isEmpty(*q)){
        IDX_TAIL(*q)=0;
        IDX_HEAD(*q)=0;
        TAIL(*q) = val;
    }
    else{
        if(IDX_TAIL(*q)==CAPACITY-1){
            for(int i=IDX_HEAD(*q);i<=IDX_TAIL(*q);i++){
                q->buffer[i-IDX_HEAD(*q)] = q->buffer[i];
            }
            IDX_TAIL(*q) = IDX_TAIL(*q)-IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(length(*q)==1){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)++;
    }
}

void displayQueue(Queue q){
    ElType val;
    printf("[");
    while(length(q)!=0){
        if(length(q)==1){
            printf("%d",HEAD(q));
        }
        else{
            printf("%d,",HEAD(q));
        }
        dequeue(&q,&val);
    }
    printf("]");
}