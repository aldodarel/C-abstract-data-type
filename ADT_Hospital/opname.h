/* File: room.h */
/* Tanggal: 16 Oktober 2023 */
/* *** Definisi ABSTRACT DATA TYPE ROOM *** */
#ifndef OPNAME_H
#define OPNAME_H
typedef struct _opname{
    int no_kamar; /*variabel Kode Ruangan*/
    char *nama; /*variabel Nama Ruangan*/
    char *penyakit; /*variabel Panjang Ruangan**/
    char *namadokter; /*variabel Lebar Ruangan*/

} OPNAME;
/* *** Konstruktor membentuk ROOM *** */
OPNAME MakeOPNAME (int no, char a[], char b[], char c[]);

void BacaOPNAME (OPNAME *O);

void TulisOPNAME (OPNAME *O);

void FreeOPNAME(OPNAME *O);

#endif