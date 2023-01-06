/*Nama : Aira Thalca Avila Putra*/
/*NIM  : 13520101*/

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int *) malloc(capacity*sizeof(int));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    NEFF(*l)=0;
    CAPACITY(*l)=0;
    free(BUFFER(*l));
}

int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return (NEFF(l));
}

IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return (NEFF(l)-1);
}

boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((0<=i) && (i<CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return ((0<=i) && (i<NEFF(l)));
}

boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
    return (NEFF(l)==0);
}

boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l)==CAPACITY(l));
}

void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
{
    int N;
    while (true){
        scanf("%d\n", &N);
        if (N >= 0 && N <= CAPACITY(*l)){
            break;
        }
    }
    IdxType i;
    NEFF(*l) = N;
    for(i=0; i <= getLastIdx(*l); i++){
        scanf("%d\n", &(ELMT(*l,i)));
    }
}

void displayList(ListDin l)
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
{
    printf("[");
    if(!isEmpty(l)){
        for (int i=0;i<=getLastIdx(l);i++){
            if(i==getLastIdx(l)){
                printf("%d", ELMT(l,i));
            }
            else{
                printf("%d,",ELMT(l,i));
            }
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    ListDin answer;
    CreateListDin(&answer,CAPACITY(l1));
    NEFF(answer) = NEFF(l1);
    for (int i=0;i<=getLastIdx(l1);i++){
        if(plus){
            ELMT(answer,i) = ELMT(l1,i) + ELMT(l2,i);
        }
        else{
            ELMT(answer,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    return answer;
}

boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if(NEFF(l1)!=NEFF(l2)){
        return false;
    }
    else{
    	boolean answer = true;
    	int i = 0;
		while ((answer) && (i<=getLastIdx(l1))){
			if(ELMT(l1,i) != ELMT(l2,i)){
                answer = false;
            }
            else{
                i++;
            }
		}
        return answer;
    }
}

IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
{
    if(isEmpty(l)){
        return IDX_UNDEF;
    }
    for (int i=0;i<=getLastIdx(l);i++){
        if(val==ELMT(l,i)){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for(int i=0;i<=getLastIdx(l);i++){
        if(ELMT(l,i)>(*max)){
            *max=ELMT(l,i);
        }
        if(ELMT(l,i)<(*min)){
            *min=ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
{
	ListDin temp;
    CreateListDin(&temp,CAPACITY(lIn));
    NEFF(temp) = NEFF(lIn);
    for (int i=0;i<=getLastIdx(temp);i++){
        ELMT(temp,i) = ELMT(lIn,i);
    }
    *lOut = temp;
}

ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    ElType ans=0;
    if(isEmpty(l)){
        return ans;
    }
    else{
        for (int i=0;i<=getLastIdx(l);i++){
            ans+=ELMT(l,i);
        }
    }
    return ans;
}

int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    ElType ans=0;
    if(isEmpty(l)){
        return ans;
    }
    else{
        for (int i=0;i<=getLastIdx(l);i++){
            if(val==ELMT(l,i)){
                ans+=1;
            }
        }
    }
    return ans;
}

boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
    for(int i=0;i<=getLastIdx(l);i++){
        if(ELMT(l,i)%2==1){
            return false;
        }
    }
    return true;
}

void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
{
    if(asc){
        for (int i = 0; i < length(*l)-1; i++){
            for (int j = 0; j < length(*l)-i-1; j++){
                if (ELMT(*l,j) > ELMT(*l,j+1)){
                    int temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }    
        }  
    }
    else{
        for (int i = 0; i < length(*l)-1; i++){
            for (int j = 0; j < length(*l)-i-1; j++){
                if (ELMT(*l,j) < ELMT(*l,j+1)){
                    int temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }    
        }  
    }      
}

void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l,getLastIdx(*l)+1) = val;
    NEFF(*l)+=1;
}

void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
{
    *val = ELMT(*l,getLastIdx(*l));
    NEFF(*l)-=1;
}

void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    int prevCapacity, prevNeff;
    IdxType i;
    ListDin temp;
    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevNeff = NEFF(*l);

    dealocate(l);

    CreateListDin(l, prevCapacity + num);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDin result;
    CreateListDin(&result, CAPACITY(*l)-num);
    if(NEFF(*l)<CAPACITY(*l)-num){
        NEFF(result) = NEFF(*l);
    }
    else{
        NEFF(result) = CAPACITY(*l)-num;
    }

    int i;
    for(i=0; i<=getLastIdx(result); i++){
        ELMT(result, i) = ELMT((*l), i);
    }
    dealocate(l);
    *l = result;
}

void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    int prevNeff;
    ListDin temp;

    copyList(*l, &temp);
    prevNeff = NEFF(*l);

    dealocate(l);

    CreateListDin(l, prevNeff);
    NEFF(*l) = prevNeff;

    for (int i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

