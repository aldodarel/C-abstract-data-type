/* File: room.h */
/* Tanggal: 16 Oktober 2023 */
/* *** Definisi ABSTRACT DATA TYPE ROOM *** */
#ifndef ROOM_H
#define ROOM_H
typedef struct _room{
    int kode; /*variabel Kode Ruangan*/
    char *name; /*variabel Nama Ruangan*/
    float panjang; /*variabel Panjang Ruangan**/
    float lebar; /*variabel Lebar Ruangan*/
    int kapasitas; /*variabel kapasitas Ruangan*/
    float hasil;
} ROOM;
/* *** Konstruktor membentuk ROOM *** */
ROOM MakeROOM (int id,char *a, float b, float c, int d);
/* Membentuk sebuah ROOM dari komponen-komponennya */
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS *** */
void BacaROOM (ROOM *R);
/* Membaca nilai ROOM dari keyboard dan membentuk
   ROOM berdasarkan dari nilai yang dimasukkan */
/* Tiap komponen dibaca dalam 1 baris */
/* Contoh: 1 2
    516
    GD516
    5.00
    8.00
    60
*/
void TulisROOM (ROOM *R);
/* Nilai R ditulis ke layar dengan format sebagai berikut
Kode : 516
Deskripsi : Ruangan GD516 dengan Luas 40.00 satuan luas memiliki kapasitas 60 orang */
#endif