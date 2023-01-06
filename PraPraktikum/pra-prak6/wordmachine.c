//Nama = Aira Thalca Avila Putra
//Kelas = K02
//NIM = 13520101

#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank()
{
    while(currentChar == BLANK && currentChar != MARK) {
        adv();
    }
}

void startWord()
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    start();
    ignoreBlank();
    if(currentChar == MARK){
        endWord = true;
    } 
    else{
        endWord = false;
        copyWord();
        }
}

void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
    ignoreBlank();
    if(currentChar == MARK) {
        endWord = true;
    } 
    else/* cc != MARK */
    {
        copyWord();
    }
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{
    int i;
    i = 0;
    while((currentChar != MARK) && (currentChar != BLANK)) {
        if (i < CAPACITY) {
            currentWord.contents[i] = currentChar;
        }
        adv();
        i++;
    }
    if (i < CAPACITY) {
        currentWord.length = i;
    } else {
        currentWord.length = CAPACITY;
    }
}