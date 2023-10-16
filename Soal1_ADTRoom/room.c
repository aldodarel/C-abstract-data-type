#include <stdio.h>
#include "room.h"
#include <string.h>

ROOM MakeROOM (int id,char *a, float b, float c, int d) 
{
    ROOM room;
    room.kode = id;
    room.name = strdup(a);
    room.panjang = b;
    room.lebar = c;
    room.kapasitas = d;
    // room.hasil = h;

return room;
}

void BacaROOM (ROOM *R) 
{
    char buffer[256];

    printf("");
    scanf("%d", &R->kode);

    printf("");
    scanf(" %[^\n]", buffer);
    R->name = strdup(buffer);

    printf("");
    scanf("%f", &R->panjang);

    printf("");
    scanf("%f", &R->lebar);

    printf("");
    scanf("%d", &R->kapasitas);
}

void TulisROOM (ROOM *R)
{
    printf("\n\nKode : %d \n", R->kode);
    printf("Deskripsi : Ruangan %s dengan Luas %.2f satuan luas memiliki kapasitas %d orang\n\n", R->name, R->panjang * R->lebar, R->kapasitas);
}


