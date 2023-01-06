//Nama = Aira Thalca Avila Putra
//Nim = 13520101

#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s){
    IDX_TOP(*s) = IDX_UNDEF;
}

boolean isEmpty(Stack s){
    return (IDX_TOP(s)==IDX_UNDEF);
}

boolean isFull(Stack s){
    return (IDX_TOP(s)==CAPACITY-1);
}

void push(Stack *s, ElType val){
    if(isEmpty(*s)){
        IDX_TOP(*s)=0;
    }
    else{
        IDX_TOP(*s)++;
    }
    TOP(*s)=val;
}

void pop(Stack *s, ElType *val){
    if(IDX_TOP(*s)==0){
        *val = TOP(*s);
        IDX_TOP(*s)=IDX_UNDEF;
    }
    else{
        *val = TOP(*s);
        IDX_TOP(*s)--;
    }
}