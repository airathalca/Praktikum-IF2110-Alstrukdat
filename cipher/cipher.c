/*NIM               : 13520101
Nama                : Aira Thalca Avila Putra
Kelas               : K02*/

#include "wordmachine.h"
#include <stdio.h>

int main(){
    int len_first;
    startWord();
    len_first = currentWord.length;
    while(endWord==false){
        for (int i=0;i<currentWord.length;i++){
            char x = (currentWord.contents[i]+len_first-'A')%26 + 65;
            printf("%c",x);
        }
        if(currentChar!=MARK){
            printf(" ");
        }
        else{
            printf(".");
        }
        advWord();
    }
    printf("\n");
}