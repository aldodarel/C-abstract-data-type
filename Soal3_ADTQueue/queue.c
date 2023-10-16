// BODY
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
/* ********* Prototype ********* */
/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Money, int Max){
/*Kamus Lokal*/
/*Algoritma*/
(*Q).T = (long*) malloc(Max * sizeof (long));
    if ((*Q).T != NULL) {
        (*Q).Money = Money;
        (*Q).HEAD = Nil;
        (*Q).TAIL = Nil;
        (*Q).MaxEl = Max;
    } else {
        (*Q).MaxEl = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
/* *** Destruktor *** */
void DeAlokasi (Queue * Q){
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
    (*Q).MaxEl = 0;
    free(Q->T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* *** Predikat Penting *** */
int IsEmpty (Queue Q){
    if (Q.HEAD == Nil && Q.TAIL == Nil) {
        return 1;
    } else {
        return 0;
    }
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
int IsFull (Queue Q){
    if (Q.TAIL == Q.MaxEl-1){
        return 1;
    }else {
        return 0;
    }
}
/* *** Banyaknya elemen queue *** */
int NbElmt (Queue Q){
    int count=0;
    if (!IsEmpty(Q)){
        while(Q.HEAD != Q.TAIL+1){
            count++;
            Q.HEAD++;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. 
   Mengirimkan 0 jika Q kosong */
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, long X){
    if(!IsFull(*Q)) {
        if(IsEmpty(*Q)) {
            (*Q).HEAD = 0;
            (*Q).TAIL = 0;
            (*Q).T[(*Q).HEAD] = X;
            (*Q).T[(*Q).TAIL] = X;
        } else if((*Q).HEAD < (*Q).TAIL) {
            (*Q).TAIL = (*Q).TAIL + 1;
            (*Q).T[(*Q).TAIL] = X; 
        }else{
            (*Q).TAIL = (*Q).TAIL + 1;
            (*Q).T[(*Q).TAIL] = X;
        } 
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q)=MaxEl maka Tail(Q) diset ke-0 */
void Del (Queue * Q, long * X){
    if (!IsEmpty(*Q)){
        if((*Q).HEAD < (*Q).TAIL) {
            *X = (*Q).T[(*Q).HEAD];
            (*Q).HEAD = (*Q).HEAD + 1;
        } 
        else {
            *X = (*Q).T[(*Q).HEAD];
            (*Q).HEAD = Nil;
            (*Q).TAIL = Nil;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju"
Q mungkin kosong */
/* *** Operasi Tambahan *** */
long Peek (Queue Q, int i){
    return (Q).T[i];
}
/* Prekondisi: Q tidak kosong */
/* Menghasilkan nilai Q pada indeks ke-i tanpa mengubah state dari Queue */
void Iterate (Queue Q){
    if (!IsEmpty(Q)){
        while(Q.HEAD != Q.TAIL){
            printf("%ld ", Peek(Q, Q.HEAD));
            Q.HEAD = Q.HEAD + 1;
        }
    printf("%ld\n",Peek(Q,Q.HEAD));
    }
}
/* Menuliskan isi Q dari Head ke Tail dengan menggunakan Peek */
/* Tidak menuliskan apa pun jika Q kosong */
/* I.S.: Q terdefinisi */
/* F.S. Isi Q tertulis ke layar dari Head ke Tail. Setiap elemen dituliskan 
sebagai satu baris,
diakhiri sebuah enter. */
int CekTotal(Queue Q){
    int total=0;
    if (!IsEmpty(Q)){
        while(Q.HEAD != Q.TAIL+1){
            total = total + Q.T[Q.HEAD];
            Q.HEAD++;
        }
    }
    return total;
}