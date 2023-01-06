#include <stdio.h>
#include "boolean.h"
#include "listpos.h"

void CreateListPos(ListPos *l)
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
    for (int i=0;i<CAPACITY;i++){
        ELMT(*l,i) = VAL_UNDEF;
    }
}

/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
{
    int count = 0;
    for (int i=0;i<CAPACITY;i++){
        if (ELMT(l,i)!=VAL_UNDEF){
            count++;
        }
        else{
            break;
        }
    }
    return count; 
}

boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i>=0) && (i<CAPACITY));
}

boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return ((i>=0) && (i<length(l)));
}

boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return (length(l)==0);
}

boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return (length(l)==CAPACITY);
}


void readList(ListPos *l)
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
{
    CreateListPos(l);
    int n;
    while(true){
        scanf("%d", &n);
        if(n>=0 && n<=CAPACITY){
            break;
        }
    }
    if (n>0){
        int i;
        for(i=0; i<n; i++){
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
{
    printf("[");
    for (int i=0; i<length(l);i++){
        printf("%d", ELMT(l,i));
        if (i != length(l)-1){
            printf(",");
        }
    }
    printf("]");
}

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
{
    ListPos result;
    CreateListPos(&result);
    if(plus){
        for (int i=0;i<length(l1);i++){
            ELMT(result,i)=ELMT(l1,i)+ELMT(l2,i);
        }
    }
    else{
        for (int i=0;i<length(l1);i++){
            ELMT(result,i)=ELMT(l1,i)-ELMT(l2,i);
        }
    }
    return result;
}

boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
    if (length(l1)!=length(l2)){
        return false;
    }
    else{
        boolean equal=true;
        for (int i=0;i<length(l1);i++){
            if(ELMT(l1,i)!=ELMT(l2,i)){
                equal = false;
                break;
            }
        }
        return equal;
    }
}

int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
{
    if(isEmpty(l)){
        return IDX_UNDEF;
    }
    int ans = IDX_UNDEF;
    for (int i=0;i<length(l);i++){
        if(val==ELMT(l,i)){
            ans=i;
            break;
        }
    }
    return ans;
}

void extremes(ListPos l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
{
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for(int i=0;i<length(l);i++){
        if(ELMT(l,i)>(*max)){
            *max=ELMT(l,i);
        }
        if(ELMT(l,i)<(*min)){
            *min=ELMT(l,i);
        }
    }
}


boolean isAllEven(ListPos l)
/* Menghailkan true jika semua elemen l genap */
{
    if(isEmpty(l)){
        return true;
    }
    else{
        boolean even = true;
        for(int i=0;i<length(l);i++){
            if(ELMT(l,i)%2==1){
                even=false;
                break;
            }
        }
        return even;
    }
}

void sort(ListPos *l, boolean asc)
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
void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
{
    if(isFull(*l)){
        return;
    }
    else{
        ELMT(*l,length(*l)) = val;
    }
}

void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
{
    *val = ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1) = VAL_UNDEF;
}


#include <stdio.h>
#include "listpos.h"

int main(){
    ListPos l,l1,l2;
    readList(&l);
    l1 = l;
    l2 = l;
    sort(&l1,false);
    sort(&l2,true);
    boolean ascending = isListEqual(l2,l);
    boolean descending = isListEqual(l1,l);
    if(ascending){
        if(descending){
            printf("Static Monotonic List\n");
        }
        else{
            printf("Non-descending Monotonic List\n");
        }
    }
    else if(descending){
        printf("Non-ascending Monotonic List\n");
    }
    else{
        printf("Non-monotonic List\n");
    }
}
