#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void print(ListDin l)
{
	printf("%d ", CAPACITY(l));
	displayList(l);
	printf("\n");
}

int main(){
    int C,tc;
    ListDin arr;
    scanf("%d", &C);
    CreateListDin(&arr,C);
    readList(&arr);
    scanf("%d", &tc);
    while (tc--){
        int op;
        scanf("%d", &op);
        if(op==1){
            int n;
            scanf("%d", &n);
            if(isFull(arr)){
                printf("list sudah penuh\n");
            }
            else{
                insertLast(&arr,n);
                print(arr);
            }
        }
        else if(op==2){
            int n;
            scanf("%d", &n);
            growList(&arr,n);
            print(arr);
        }
        else if(op==3){
            int n;
            scanf("%d", &n);
            if(CAPACITY(arr)<n){
                printf("list terlalu kecil\n");
            }
            else{
                shrinkList(&arr,n);
                print(arr);
            }
        }
        else if (op==4){
            compactList(&arr);
            print(arr);
        }
    }
}