//Nama = Aira Thalca Avila Putra
//NIM = 13520101
//Problem = cache.c
//Implementasi linked list linier

#include <stdio.h>
#include "list_linked.h"

int main(){
    List l;
    CreateList(&l);
    int len;
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        insertLast(&l,i);
    }
    int tc,q,val;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&q);
        if(indexOf(l,q)==IDX_UNDEF){
            deleteLast(&l,&val);
            printf("miss ");
        }
        else{
            deleteAt(&l,indexOf(l,q),&val);
            printf("hit ");
        }
        insertFirst(&l,q);
        displayList(l);
        printf("\n");
    }
}