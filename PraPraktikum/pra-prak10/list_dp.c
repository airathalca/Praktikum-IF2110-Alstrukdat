#include <stdio.h>
#include <stdlib.h>
#include "list_dp.h"

boolean isEmpty(List l){
    return (FIRST(l)==NULL && LAST(l)==NULL);
}

void CreateList(List *l){
    FIRST(*l)=NULL;
    LAST(*l)=NULL;
}

Address allocate(ElType val){
    Address ret;
    ret = (Address) malloc (sizeof(Node));
    if(ret!=NULL){
        NEXT(ret)=NULL;
        PREV(ret)=NULL;
        INFO(ret)=val;
    }
    return ret;
}

void deallocate (Address p){
    free(p);
}

Address search(List l, ElType val){
    Address now = FIRST(l);
    while(now != NULL && INFO(now)!=val){
        now = NEXT(now);
    }
    return now;
}

void insertFirst(List *l, ElType val){
    Address x = allocate(val);
    if(x!=NULL){
        NEXT(x) = FIRST(*l);
        if(isEmpty(*l)){
            LAST(*l)=x;
        }
        else{
            PREV(FIRST(*l))=x;
        }
        FIRST(*l)=x;
    }
}

void insertLast(List *l, ElType val){
    Address x = allocate(val);
    if(x!=NULL){
        PREV(x) = LAST(*l);
        if(isEmpty(*l)){
            FIRST(*l)=x;
        }
        else{
            NEXT(LAST(*l))=x;
        }
        LAST(*l)=x;
    }
}

void insertAfter(List *L, Address p, Address pRec){
    if(pRec!=LAST(*L)){
        NEXT(p) = NEXT(pRec);
        PREV(NEXT(pRec)) = p;
        PREV(p) = pRec;
        NEXT(pRec) = p;
    }
    else{
        insertLast(L,INFO(p));
    }
}

void deleteFirst(List *l, ElType *val){
    Address deleted = FIRST(*l);
    *val = INFO(deleted);
    if(FIRST(*l) == LAST(*l)){
        LAST(*l)=NULL;
    }
    else{
        PREV(NEXT(FIRST(*l))) = NULL;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    deallocate(deleted);
}

void deleteLast(List *l, ElType *val){
    Address deleted = LAST(*l);
    *val = INFO(deleted);
    if(FIRST(*l) == LAST(*l)){
        FIRST(*l)=NULL;
    }
    else{
        NEXT(PREV(LAST(*l))) = NULL;
    }
    LAST(*l) = PREV(LAST(*l));
    deallocate(deleted);
}

void deleteAfter(List *l, Address *pDel, Address pRec){
    int val;
    *pDel = NEXT(pRec);
    if((*pDel)==LAST(*l)){
        if(FIRST(*l)==LAST(*l)){
            FIRST(*l) = NULL;
        }
        else{
            NEXT(PREV(LAST(*l))) = NULL;
        }
        LAST(*l) = PREV(LAST(*l));
    }
    else{
        PREV(NEXT(*pDel))=pRec;
        NEXT(pRec)=NEXT(*pDel);
    }
}

void displayList(List l){
    printf("[");
    if (!(isEmpty(l))){
        Address now = FIRST(l);
        while (now != NULL){
            printf("%d", INFO(now));
            now = NEXT(now);
            if (now != NULL){
                printf(",");
            }
        }
    }
    printf("]");
}

void displayListBackwards(List l){
    printf("[");
    if (!(isEmpty(l))){
        Address now = LAST(l);
        while (now != NULL){
            printf("%d", INFO(now));
            now = PREV(now);
            if (now != NULL){
                printf(",");
            }
        }
    }
    printf("]");
}