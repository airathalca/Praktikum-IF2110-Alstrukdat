#include "listrec.h"
#include <stdlib.h>

// Nama = Aira Thalca Avila Putra
// Topik = ListRec
// NIM = 13520101

Address newNode(ElType x){
    Address p;
    p= (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(List l){
    return (l == NULL);
}

int isOneElmt(List l){
    if (l!=NULL && NEXT(l)==NULL){
        return 1;
    }
    return 0;
}

ElType head(List l){
    return INFO(l);
}

List tail(List l){
    if (isEmpty(l)){
        return NULL;
    }
    else{
        return NEXT(l);
    }
}

List konso(List l, ElType e){
    Address p = newNode(e);
    if (p!=NULL){
        NEXT(p) = l;
        return p;
    }
    return l;
}

List konsb(List l, ElType e){
    Address p = newNode(e);
    if(isEmpty(l)){
        return p;
    }
    else{
        NEXT(l) = konsb(tail(l),e);
        return l;
    }
}


int length(List l){
    if(isEmpty(l)){
        return 0;
    }
    return 1+length(tail(l));
}

void displayList(List l){
    if(!isEmpty(l)){
        printf("%d\n", INFO(l));
        displayList(NEXT(l));
    }
}

ElType maxList (List l){
    if (isOneElmt(l)){
        return head(l);
    }
    else{
        if (head(l) > maxList(tail(l))){
            return head(l);
        }
        return maxList(tail(l));
    }
}

ElType minList (List l){
    if (isOneElmt(l)){
        return head(l);
    }
    else{
        if (head(l) < minList(tail(l))){
            return head(l);
        }
        return minList(tail(l));
    }
}

ElType sumList (List l){
    if (isOneElmt(l)) {
        return head(l);
    }
    else{
        return head(l) + sumList(tail(l));
    }
}

float averageList (List l){
    return (float) ((float) sumList(l) / (float) length(l));
}

List inverseList (List l){
    if(isEmpty(l)) {
        return NULL;
    }
    else {
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } 
    else{
        splitPosNeg(tail(l), l1, l2);
        if (head(l) >= 0){
            *l1 = konso(*l1, head(l));
        } 
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2){
if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } 
    else{
        splitOnX(tail(l),x, l1, l2);
        if (head(l) < x){
            *l1 = konso(*l1, head(l));
        } 
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}

int compareList (List l1, List l2){
    if (isEmpty(l1) && isEmpty(l2)){
        return 0;
    }
    else if (isEmpty(l1) && !isEmpty(l2)){
        return -1;
    } 
    else if (!isEmpty(l1) && isEmpty(l2)){
        return 1;
    }
    else if (head(l1) < head(l2)){
        return -1;
    }
    else if (head(l1) > head(l2)){
        return 1;
    }
    else{
        return compareList(tail(l1), tail(l2));
    }
}

boolean Search (List l, ElType x){
    if (isEmpty(l)){
        return false;
    } 
    if (INFO(l) == x){
        return true;
    } 
    return Search(NEXT(l), x);
}

boolean isAllExist (List l1, List l2){
    if (isEmpty(l1)) {
        return false;
    } 
    else if (isOneElmt(l1)==1) {
        return Search(l2,INFO(l1));
    } 
    return (isAllExist(tail(l1), l2) && Search(l2,INFO(l1)));
}