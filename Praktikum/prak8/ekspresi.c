//Nama = Aira Thalca Avila Putra
//NIM = 13520101
//Topik = Stack dan tokenmachine
//Program = Membuat program ekspresi postfix
#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "math.h"
#include "tokenmachine.h"

int main(){
    Stack s;
    int a,b;
    CreateStack(&s);
    startToken();
    if(endToken){
        printf("Ekspresi kosong\n");
    }
    else{
        while(!endToken){
            if(currentToken.tkn=='b'){
                push(&s,currentToken.val);
                printf("%d\n",currentToken.val);
            }
            else{
                pop(&s,&b);
                pop(&s,&a);
                if(currentToken.tkn == '*'){
                    printf("%d %c %d\n",a,currentToken.tkn,b);
                    push(&s,a*b);
                    printf("%d\n", TOP(s));
                }
                else if(currentToken.tkn == '/'){
                    printf("%d %c %d\n",a,currentToken.tkn,b);
                    push(&s,a/b);
                    printf("%d\n", TOP(s));
                }
                else if(currentToken.tkn == '+'){
                    printf("%d %c %d\n",a,currentToken.tkn,b);
                    push(&s,a+b);
                    printf("%d\n", TOP(s));
                }
                else if(currentToken.tkn == '-'){
                    printf("%d %c %d\n",a,currentToken.tkn,b);
                    push(&s,a-b);
                    printf("%d\n", TOP(s));
                }
                else if(currentToken.tkn == '^'){
                    printf("%d %c %d\n",a,currentToken.tkn,b);
                    push(&s,pow(a,b));
                    printf("%d\n", TOP(s));
                }
            }
            advToken();
        }
        pop(&s,&a);
        printf("Hasil=%d\n",a);
    }
}