// NAMA = AIRA THALCA AVILA PUTRA
// NIM = 13520101
// TOPIK = Binary Tree
#include "bintree.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

boolean poweroftwo(int n){
    if(n==0){
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}

BinTree merkle(int h){
	if(h==0){
		int c;
		scanf("%d", &c);
		return newTreeNode(c);
	}
	BinTree root = newTreeNode(0);
	LEFT(root) = merkle(h - 1);
	RIGHT(root) = merkle(h - 1);
	ROOT(root) = ROOT(LEFT(root)) + ROOT(RIGHT(root));
	return root;
}

int main(){
    int n;
    scanf("%d",&n);
    if(!poweroftwo(n)){
        printf("Jumlah masukan tidak sesuai\n");
    }
    else{
        int a = log2(n);
        BinTree ans = merkle(a);
        printTree(ans,2);
    }
}