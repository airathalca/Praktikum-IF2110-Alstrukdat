#include "listrec.h"
#include <stdio.h>

// Nama = Aira Thalca Avila Putra
// Topik = ListRec
// NIM = 13520101

List Ganjil(List l){
    if (isEmpty(l)){
        return NULL;
    }
    else if (isOneElmt(l)){
        return l;
    }
    return konso(Ganjil(tail(tail(l))),head(l));
}

List Genap(List l){
    if (isEmpty(l)){
        return NULL;
    }
    else if (isOneElmt(l)){
        return NULL;
    }
    return konso(Genap(tail(tail(l))),head(tail(l)));
}

List Cut(List l,ElType x){
    if (isEmpty(l)){
        return NULL;
    }
    else if (head(l)==x){
        return NULL;
    }
    else{
        return konso(Cut(tail(l),x),head(l));
    }
}

List reverseList(List l){
    if(isEmpty(l)) {
        return NULL;
    }
    else {
        return konsb(reverseList(tail(l)),head(l));
    }
}


int main(){
    char op;
    List l = NULL;
    int x;
    while(true){
        scanf(" %c", &op);
        if(op=='F'){
            scanf("%d",&x);
            l = konso(l,x);
        }
        else if(op=='B'){
            scanf("%d",&x);
            l = konsb(l,x);
        }
        else if(op=='R'){
            l = reverseList(l);
        }
        else if(op=='O'){
            l = Ganjil(l);
        }
        else if(op=='E'){
            l = Genap(l);
        }
        else if(op=='P'){
            scanf("%d",&x);
            l = Cut(l,x);
        }
        else if(op=='X'){
            break;
        }
    }
    if(isEmpty(l)){
        printf("Semua gugur\n");
    }
    else{
        displayList(l);
    }
}