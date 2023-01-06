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
