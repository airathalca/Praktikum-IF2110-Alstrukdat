// NAMA = AIRA THALCA AVILA PUTRA
// NIM = 13520101
// TOPIK = Binary Tree
#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

void invertBtree(BinTree *p){
    if(!isTreeEmpty(*p)){
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
        *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
    }
}