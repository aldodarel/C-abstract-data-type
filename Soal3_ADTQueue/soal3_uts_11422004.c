// Driver
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main (){
    Queue Q;
    int size, money,x;
    printf("Money = ");
    scanf("%d", &money);
    printf("N = ");
    scanf("%d", &size);
    CreateEmpty(&Q, money, size);
    
    for (int i = 0; i < size; i++){
        scanf ("%d", &x);
        if (x==Nil)
        {
            break;
        }
        Add(&Q, x);
    }

    printf("\n\nQUEUE = ");
    Iterate(Q);
    if(IsFull(Q) == 1){
        printf("STATUS = ANTRIAN ATM PENUH");
    }
    else if(IsEmpty(Q) == 1){
        printf("STATUS = ANTRIAN KOSONG");
    }
    else{
        printf("STATUS = ANTRIAN ATM MASIH BISA DIISI");
    }
    printf("\n");
    printf("TRANSAKSI ATM = %d\n", CekTotal(Q));
    printf("SISA ATM = %d\n", Q.Money-CekTotal(Q));
    printf("SISA ANTRIAN = %d\n\n",Q.MaxEl-
    NbElmt(Q));
    return 0;
}