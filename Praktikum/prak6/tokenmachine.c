/*NIM               : 13520101
Nama                : Aira Thalca Avila Putra
Kelas               : K02*/

#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank(){
    while(currentChar == BLANK && currentChar != MARK){
        adv();
    }
}

void startToken(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    } 
    else{
        endToken = false;
        salinToken();
    }
}

void advToken(){
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    } 
    else{
        salinToken();
        ignoreBlank();
    }
}

void salinToken(){
    int i;
    i = 0;
    currentToken.val = 0;
    while (currentChar != MARK && currentChar != BLANK){
        if (i < CAPACITY){
            if (currentChar >= 48 && currentChar <= 57) {
                currentToken.val *= 10;
                currentToken.val += (currentChar - 48);
                currentToken.tkn = 'b';
            } 
            else{
                currentToken.val = -1;
                currentToken.tkn = currentChar;
            }
        }
        adv();
        i++;
    }
}