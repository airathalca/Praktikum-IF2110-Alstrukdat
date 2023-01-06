//NIM             : 13520101
//Nama            : Aira Thalca Avila Putra
//Program         : Implementasi list circular

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

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