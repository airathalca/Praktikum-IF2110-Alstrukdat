// Nama = Aira Thalca Avila Putra
// NIM = 13520101
// Topik = Linked Stack

#include <stdio.h>
#include "stack_linked.h"

Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack s){
    return (ADDR_TOP(s)==NULL);
}

void CreateStack(Stack *s){
    ADDR_TOP(*s)=NULL;
}

void push(Stack *s, ElType x){
    Address new = newNode(x);
    if(new!=NULL){
        NEXT(new)=ADDR_TOP(*s);
        ADDR_TOP(*s)=new;
    }
}

void pop(Stack *s, ElType *x){
    Address deleted = ADDR_TOP(*s);
    *x = TOP(*s);
    ADDR_TOP(*s)=NEXT(ADDR_TOP(*s));
    NEXT(deleted) = NULL;
    free(deleted);
}