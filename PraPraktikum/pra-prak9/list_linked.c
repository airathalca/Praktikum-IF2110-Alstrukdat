//Nama = Aira Thalca Avila Putra
//NIM = 13520101
//Problem = ADT linked list
#include <stdio.h>
#include "list_linked.h"

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx){
    Address now = FIRST(l);
    int i = 0;
    while(i<idx){
        i++;
        now = NEXT(now);
    }
    return INFO(now);
}

void setElmt(List *l, int idx, ElType val){
    Address now = FIRST(*l);
    int i = 0;
    while(i<idx){
        i++;
        now = NEXT(now);
    }
    INFO(now) = val;
}

int indexOf(List l, ElType val){
    Address now = FIRST(l);
    boolean found = false;
    int i = 0;
    while(now!=NULL && (!found)){
        if(INFO(now)==val){
            found = true;
        }
        else{
            i++;
            now = NEXT(now);
        }
    }
    if (found){
        return i;
    }
    else{
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val){
    Address now = newNode(val);
    if(now!=NULL){
        NEXT(now) = FIRST(*l);
        FIRST(*l)=now;
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l,val);
    }
    else{
        Address new = newNode(val);
        if(new!=NULL){
            Address now = FIRST(*l);
            while(NEXT(now)!=NULL){
                now=NEXT(now);
            }
            NEXT(now)=new;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx==0){
        insertFirst(l,val);
    }
    else{
        Address new = newNode(val);
        if(new!=NULL){
            int i=0;
            Address now = FIRST(*l);
            while(i<idx-1){
                i++;
                now=NEXT(now);
            }
            NEXT(new)=NEXT(now);
            NEXT(now)=new;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address now = FIRST(*l);
    *val = INFO(now);
    FIRST(*l) = NEXT(now);
    free(now);
}

void deleteLast(List *l, ElType *val){
    Address deleted = FIRST(*l);
    Address loc = NULL;
    while(NEXT(deleted)!=NULL){
        loc = deleted;
        deleted = NEXT(deleted);
    }
    if(loc==NULL){
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(deleted);
    free(deleted);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx==0){
        deleteFirst(l,val);
    }
    else{
        int i=0;
        Address now = FIRST(*l);
        while(i<idx-1){
            i++;
            now = NEXT(now);
        }
        Address deleted = NEXT(now);
        *val = INFO(deleted);
        NEXT(now) = NEXT(deleted);
        free(deleted);
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

int length(List l){
    if(isEmpty(l)){
        return 0;
    }
    else{
        int len = 0;
        Address now = FIRST(l);
        while(now!=NULL){
            len++;
            now = NEXT(now);
        }
        return len;
    }
}

List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address now = FIRST(l1);
    while(now!=NULL){
        insertLast(&l3,INFO(now));
        now=NEXT(now);
    }
    now = FIRST(l2);
    while(now!=NULL){
        insertLast(&l3,INFO(now));
        now=NEXT(now);
    }
    return l3;
}

boolean fSearch(List L, Address P){
    Address now = FIRST(L);
    while(now!=NULL){
        if(P==now){
            return true;
        }
        now = NEXT(now);
    }
    return false;
}

Address searchPrec(List L, ElType X){
    if(isEmpty(L)){
        return NULL;
    }
    Address now = FIRST(L);
    if(INFO(now)==X){
        return NULL;
    }
    while(now!=NULL && INFO(now)!=X){
        now = NEXT(now);
    }
    if(now!=NULL){
        Address ans = FIRST(L);
        while(ans!=NULL){
            if (NEXT(ans) == now){
                return ans;
            }
            ans = NEXT(ans);
        }
    }
    return now;
}

ElType max(List l){
    Address now = FIRST(l);
    int maks = INFO(now);
    while (now!=NULL){
        if(INFO(now)>maks){
            maks = INFO(now);
        }
        now = NEXT(now);
    }
    return maks;
}
Address adrMax(List l){
    Address now = FIRST(l);
    Address maks = now;
    while (now!=NULL){
        if(INFO(now)>INFO(maks)){
            maks = now;
        }
        now = NEXT(now);
    }
    return maks;
}
ElType min(List l){
    Address now = FIRST(l);
    int mins = INFO(now);
    while (now!=NULL){
        if(INFO(now)<mins){
            mins = INFO(now);
        }
        now = NEXT(now);
    }
    return mins;
}
Address adrMin(List l){
    Address now = FIRST(l);
    Address mins = now;
    while (now!=NULL){
        if(INFO(now)<INFO(mins)){
            mins = now;
        }
        now = NEXT(now);
    }
    return mins;
}

float average(List l){
    Address now = FIRST(l);
    float sum = 0;
    while(now!=NULL){
        sum+=INFO(now);
        now = NEXT(now);
    }
    sum/=length(l);
    return sum;
}


void delAll(List *l){
    Address now = FIRST(*l);
    int deleted;
    while(now!=NULL){
        deleteFirst(l,&deleted);
        now = NEXT(now);
    }
    FIRST(*l) = NULL;
}

void inverseList(List *l){
    if(!isEmpty(*l)){
        Address now = FIRST(*l);
        while(NEXT(now)!=NULL){
            now = NEXT(now);
        }
        Address first = now;
        Address a;
        while(now!=FIRST(*l)){
            a = FIRST(*l);
			while (NEXT(a)!=now){
				a = NEXT(a);
			}
            NEXT(now) = a;
            now = NEXT(now);
        }
        NEXT(now) = NULL;
        FIRST(*l) = first;
    }
}

List fInverseList(List l){
    List ans = fCopyList(l);
    inverseList(&ans);
    return ans;
}

void copyList(List *l1, List *l2){
    FIRST(*l2) = FIRST(*l1);
}

List fCopyList(List l){
    List ans;
    CreateList(&ans);
    boolean copied = true;
    Address now = FIRST(l);
    while(copied && now!=NULL){
        Address a = newNode(INFO(now));
        if(a==NULL){
            copied = false;
        } 
        else{
            insertLast(&ans, INFO(a));
        }
        now = NEXT(now);
    }
    if(!copied){
        delAll(&ans);
    }
    return ans;
}

void cpAllocList(List lIn, List *lOut){
    *lOut = fCopyList(lIn);
}

void splitList(List *l1, List *l2, List l){
    CreateList(l1);
    CreateList(l2);
    int len = length(l)/2;
    int ctr = 0;
    Address now = FIRST(l);
    while(now != NULL){
        ctr++;
        Address ans = newNode(INFO(now));
        if(ans != NULL){
            if(ctr <= len){
                insertLast(l1, INFO(ans));
            } 
            else{
                insertLast(l2, INFO(ans));
            }
        }
        now = NEXT(now);
    }
}