#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l){
    return (FIRST(l)==NULL);
}

void CreateList(List *l){
    FIRST(*l)=NULL;
}

Address allocate(ElType val){
    Address ret;
    ret = (Address) malloc (sizeof(ElmtList));
    if(ret!=NULL){
        NEXT(ret)=NULL;
        INFO(ret)=val;
    }
    return ret;
}

void deallocate (Address P){
    free(P);
}

Address search(List l, ElType val){
    Address now = FIRST(l);
    if(now == NULL){
        return NULL;
    }
    while(NEXT(now) != FIRST(l) && INFO(now)!=val){
        now = NEXT(now);
    }
    if(INFO(now)==val){
        return now;
    }
    return NULL;
}

boolean addrSearch(List l, Address p){
    Address now = FIRST(l);
    if(now == NULL){
        return false;
    }
    while(NEXT(now) != FIRST(l) && now!=p){
        now = NEXT(now);
    }
    if(now==p){
        return true;
    }
    return false;
}

void insertFirst(List *l, ElType val){
    Address x = allocate(val);
    if(x!=NULL){
        if(FIRST(*l)==NULL){
            FIRST(*l)=x;
            NEXT(x)=x;
        }
        else{
            NEXT(x)=FIRST(*l);
            Address y = FIRST(*l);
            while (NEXT(y) != FIRST(*l)){
                y = NEXT(y);
            }
            NEXT(y) = x;
            FIRST(*l) = x;
        }
    }
}

void insertLast(List *l, ElType val){
    Address x = allocate(val);
    Address y = FIRST(*l);
    if(y==NULL){
        y=x;
        NEXT(y)=y;
    }
    else{
        while(NEXT(y)!=FIRST(*l)){
            y = NEXT(y);
        }
        NEXT(y)=x;
        NEXT(x)=FIRST(*l);
    }
}

void deleteFirst(List *l, ElType *val){
    FIRST(*l)=NEXT(FIRST(*l));
    deleteLast(l,val);
}

void deleteLast(List *l, ElType *val){
    Address x = FIRST(*l);
    Address y = x;

    while(NEXT(NEXT(x)) != y){
        x = NEXT(x);
    }
    *val = INFO(NEXT(x));
    if (NEXT(x) == y){
        CreateList(l);
    } else {
        NEXT(x) = y;
    }
}

void displayList(List l){
    printf("[");
    if (!(isEmpty(l))){
        Address now = FIRST(l);
        while (NEXT(now) != FIRST(l)){
            printf("%d,", INFO(now));
            now = NEXT(now);
        }
        printf("%d",INFO(now));
    }
    printf("]");
}

void deleteRR(List *l, ElType tQ){
    if(!isEmpty(*l)){
        Address now=FIRST(*l);
        while(NEXT(now)!=FIRST(*l)){
            now=NEXT(now);
        }
        if(INFO(now)>tQ){
            printf("%d\n",tQ);
            INFO(now)=INFO(now)-tQ;
            FIRST(*l)=now;
        }
        else{
            int val;
            deleteLast(l,&val);
            printf("%d\n",val);
        }
    }
    else{
        printf("List kosong\n");
    }
}

float average(List l){
    Address now=FIRST(l);
    float sum=0;
    int len=1;
    while(NEXT(now)!=FIRST(l)){
        sum+=INFO(now);
        now=NEXT(now);
        len++;
    }
    sum+=INFO(now);
    return sum/len;
}

int main(){
    int tQ;
    List l;
    CreateList(&l);
    tQ=0;
    while(tQ<=0){
        scanf("%d",&tQ);
    }
    if(tQ>0){
        while(true){
        	char op;
        	scanf(" %c",&op);
        	if(op=='A'){
            	int a;
            	scanf("%d",&a);
            	if(a>0){
                	insertFirst(&l,a);
            	}
        	}
        	else if(op=='D'){
            	deleteRR(&l,tQ);
        	}
        	else if(op=='F'){
            	break;
        	}
        	else{
            	printf("Kode salah\n");
       		}
    	}
    	if(isEmpty(l)){
        	printf("Proses selesai\n");
    	}
    	else{
        	printf("%.2f\n",average(l));
    	}	
	}
}