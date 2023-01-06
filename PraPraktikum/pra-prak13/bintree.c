// NAMA = AIRA THALCA AVILA PUTRA
// NIM = 13520101
// TOPIK = Binary Tree
#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree new = newTreeNode(root);
    if (new!=NULL){
        LEFT(new) = left_tree;
        RIGHT(new) = right_tree;
    }
    return new;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root,left_tree,right_tree);
}

Address newTreeNode(ElType val){
    Address p;
    p = (Address) malloc (sizeof(TreeNode));
    if (p!=NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode (Address p){
    free(p);
}

boolean isTreeEmpty (BinTree p){
    return p == NULL;
}

boolean isOneElmt (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)==NULL && RIGHT(p)==NULL);
    }
    return false;
}

boolean isUnerLeft (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL && RIGHT(p)==NULL);
    }
    return false;
}

boolean isUnerRight (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)==NULL && RIGHT(p)!=NULL);
    }
    return false;
}

boolean isBinary (BinTree p){
        if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL && RIGHT(p)!=NULL);
    }
    return false;
}

void printPreorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTree(BinTree p, int h){
    void PrintTree2(BinTree p, int h, int cur){
        if (!isTreeEmpty(p)){
            printf("%*s%d\n", cur, "", ROOT(p));
            PrintTree2(LEFT(p), h, cur + h);
            PrintTree2(RIGHT(p), h, cur + h);
        }
    }
    PrintTree2(p,h,0);
}