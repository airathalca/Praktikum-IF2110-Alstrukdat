// Nama = Aira Thalca Avila Putra
// NIM = 13520101
// Topik = Linked Queue

#include <stdio.h>
#include "queue_linked.h"

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q){
    return (ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL);
}

int length(Queue q){
    if(isEmpty(q)){
        return 0;
    }
    else{
        Address now = ADDR_HEAD(q);
        int ctr = 0;
        while(now != NULL){
            now = NEXT(now);
            ctr++;
        }
        return ctr;
    }
}

void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void enqueue(Queue *q, ElType x){
    Address new = newNode(x);
    if(new!=NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q)=new;
        }
        else{
            NEXT(ADDR_TAIL(*q))=new;
        }
        ADDR_TAIL(*q)=new;
    }
}

void dequeue(Queue *q, ElType *x){
    Address deleted = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q)=NEXT(ADDR_HEAD(*q));
    if(ADDR_HEAD(*q)==NULL){
        ADDR_HEAD(*q)==NULL;
    }
    NEXT(deleted) = NULL;
    free(deleted);
}