/* File queue.h (HEADER) */
/* ADT ATM */
#ifndef QUEUE_H
#define QUEUE_H 
/* Konstanta */
#define Nil -99
/* Nil adalah indeks tak terdefinisi */

typedef struct { 
    int Money; /* menyimpan UANG */
    long * T;  /* tabel penyimpan elemen */
    int HEAD;  /* alamat penghapusan */
    int TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} Queue;

#define Money(Q) (Q).Money 
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define MaxEl(Q) (Q).MaxEl  

/* ********* Prototype ********* */
/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Money, int Max);

/* *** Destruktor *** */
void DeAlokasi (Queue * Q);
/* Proses: Mengembalikan memori Q */

int IsEmpty (Queue Q);
int IsFull (Queue Q);

/* *** Banyaknya elemen queue *** */
int NbElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. 
   Mengirimkan 0 jika Q kosong */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, long X);

void Del (Queue * Q, long * X);

long Peek (Queue Q, int i); 

void Iterate (Queue Q);

int CekTotal(Queue Q);
#endif