/*Nama : Aira Thalca Avila Putra*/
/*NIM  : 13520101*/

#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int *) malloc(capacity*sizeof(int));
    for (int i=0;i<CAPACITY(*l);i++){
        ELMT(*l,i) = VAL_UNDEF;
    }
}

void dealocate(ListDin *l){
    CAPACITY(*l)=0;
    free(BUFFER(*l));
}

int length(ListDin l){
    int count = 0;
    for (int i=0;i<CAPACITY(l);i++){
        if (ELMT(l,i)!=VAL_UNDEF){
            count++;
        }
        else{
            break;
        }
    }
    return count; 
}

IdxType getLastIdx(ListDin l){
    return length(l)-1;
}

boolean isIdxValid(ListDin l, IdxType i){
    return ((0<=i) && (i<CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i){
    return ((0<=i) && (i<=getLastIdx(l)));
}

boolean isEmpty(ListDin l){
    return (length(l)==0);
}

boolean isFull(ListDin l){
    return (length(l)==CAPACITY(l));
}

void readList(ListDin *l){
    int N;
    while (true){
        scanf("%d", &N);
        if (N >= 0 && N <= CAPACITY(*l)){
            break;
        }
    }
    if (N>0){
        for(int i=0; i<N; i++){
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void displayList(ListDin l){
    printf("[");
    for (int i=0; i<length(l);i++){
        printf("%d", ELMT(l,i));
        if (i != length(l)-1){
            printf(",");
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin answer;
    CreateListDin(&answer,CAPACITY(l1));
    for (int i=0;i<=getLastIdx(l1);i++){
        if(plus){
            ELMT(answer,i) = ELMT(l1,i) + ELMT(l2,i);
        }
        else{
            ELMT(answer,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return answer;
}

boolean isListEqual(ListDin l1, ListDin l2){
    if(length(l1)!=length(l2)){
        return false;
    }
    else{
    	boolean answer = true;
    	int i = 0;
		while ((answer) && (i<=getLastIdx(l1))){
			if(ELMT(l1,i) != ELMT(l2,i)){
                answer = false;
            }
            else{
                i++;
            }
		}
        return answer;
    }
}

IdxType indexOf(ListDin l, ElType val){
    if(isEmpty(l)){
        return VAL_UNDEF;
    }
    for (int i=0;i<=getLastIdx(l);i++){
        if(val==ELMT(l,i)){
            return i;
        }
    }
    return VAL_UNDEF;
}

void extremes(ListDin l, ElType *max, ElType *min){
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for(int i=0;i<=getLastIdx(l);i++){
        if(ELMT(l,i)>(*max)){
            *max=ELMT(l,i);
        }
        if(ELMT(l,i)<(*min)){
            *min=ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    ListDin temp;
    CreateListDin(&temp,CAPACITY(lIn));
    for (int i=0;i<=getLastIdx(temp);i++){
        ELMT(temp,i) = ELMT(lIn,i);
    }
    *lOut = temp;
}

ElType sumList(ListDin l){
    ElType ans=0;
    if(isEmpty(l)){
        return ans;
    }
    else{
        for (int i=0;i<=getLastIdx(l);i++){
            ans+=ELMT(l,i);
        }
    }
    return ans;
}

int countVal(ListDin l, ElType val){
    ElType ans=0;
    if(isEmpty(l)){
        return ans;
    }
    else{
        for (int i=0;i<=getLastIdx(l);i++){
            if(val==ELMT(l,i)){
                ans+=1;
            }
        }
    }
    return ans;
}

boolean isAllEven(ListDin l){
    for(int i=0;i<=getLastIdx(l);i++){
        if(ELMT(l,i)%2==1){
            return false;
        }
    }
    return true;
}

void sort(ListDin *l, boolean asc){
    if(asc){
        for (int i = 0; i < length(*l)-1; i++){
            for (int j = 0; j < length(*l)-i-1; j++){
                if (ELMT(*l,j) > ELMT(*l,j+1)){
                    int temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }    
        }  
    }
    else{
        for (int i = 0; i < length(*l)-1; i++){
            for (int j = 0; j < length(*l)-i-1; j++){
                if (ELMT(*l,j) < ELMT(*l,j+1)){
                    int temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }    
        }  
    }      
}

void insertLast(ListDin *l, ElType val){
    if(isFull(*l)){
        return;
    }
    ELMT(*l,getLastIdx(*l)+1) = val;
}

void deleteLast(ListDin *l, ElType *val){
        *val = ELMT(*l,getLastIdx(*l));
        ELMT(*l,getLastIdx(*l))==VAL_UNDEF;
}

void growList(ListDin *l, int num){
    int prevCapacity, prevLength;
    IdxType i;
    ListDin temp;
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevLength = length(*l);
    dealocate(l);

    CreateListDin(l, prevCapacity + num);

    for (i = 0; i < prevLength; i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList(ListDin *l, int num){
    ListDin result;
    int Length = length(*l);
    CreateListDin(&result, CAPACITY(*l)-num);
    if(length(*l)<CAPACITY(*l)-num){
        for(int i=0; i<Length; i++){
            ELMT(result, i) = ELMT((*l), i);
        }
        dealocate(l);
        *l = result;
    }
    else{
        for(int i=0; i<CAPACITY(*l)-num; i++){
            ELMT(result, i) = ELMT((*l), i);
        }
        dealocate(l);
        *l = result;
    }
    
}

void compactList(ListDin *l){
    ListDin temp;
    int Length;
    Length = length(*l);
    copyList(*l, &temp);
    dealocate(l);
    CreateListDin(l, Length);
    for (int i = 0; i < Length; i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}
