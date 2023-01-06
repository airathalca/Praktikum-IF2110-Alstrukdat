//Nama = Aira Thalca Avila Putra
//Nim = 13520101
//Topik = ADT Stack
//Program = Menghitung jumlah dua bilangan positif besar dengan stack
#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>

int main(){
    char s1[101];
    char s2[101];
    int val,temp=0;
    Stack S1,S2,sum,check;
    CreateStack(&S1);
    CreateStack(&S2);
    scanf("%s", s1);
    scanf("%s", s2);
    for(int i=0;i<strlen(s1)-1;i++){
        push(&S1,s1[i]-'0');
    }
    for(int i=0;i<strlen(s2)-1;i++){
        push(&S2,s2[i]-'0');
    }
    CreateStack(&sum);
    if(IDX_TOP(S2)>IDX_TOP(S1)){
        CreateStack(&check);
        check = S1;
        S1 = S2;
        S2 = check;
    }
    while(!isEmpty(S2)){
        push(&sum,(temp+TOP(S1)+TOP(S2))%10);
        if(temp){
            if(temp+TOP(S1)+TOP(S2)<10){
                temp = 0;
            }
        }
        else{
            if(TOP(S1)+TOP(S2)>=10){
                temp = 1;
            }
        }
        pop(&S1,&val);
        pop(&S2,&val);
    }
    while(!isEmpty(S1)){
        if(temp){
            push(&sum,(temp+TOP(S1))%10);
            if(temp+TOP(S1)<10){
                temp=0;
            }
        }
        else{
            push(&sum,TOP(S1));
        }
        pop(&S1,&val);
    }
    if(temp){
        push(&sum,temp);
    }
    while(!isEmpty(sum)){
        printf("%d",TOP(sum));
        pop(&sum,&val);
    }
    printf("\n");
}