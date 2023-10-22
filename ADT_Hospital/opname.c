#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "opname.h"

OPNAME MakeOPNAME(int no, char *a, char *b, char *c)
{
    OPNAME opname;
    opname.no_kamar = no;
    opname.nama = strdup(a);
    opname.penyakit = strdup(b);
    opname.namadokter = strdup(c);

    return opname;
}

void BacaOPNAME(OPNAME *O)
{
    char buffer[256];

    printf("Masukkan nomor kamar: ");
    scanf("%d", &O->no_kamar);

    printf("Masukkan Nama: ");
    scanf(" %[^\n]", buffer);
    O->nama = strdup(buffer);

    printf("Masukkan penyakit penderita: ");
    scanf(" %[^\n]", buffer);
    O->penyakit = strdup(buffer);

    printf("Masukkan nama dokter: ");
    scanf(" %[^\n]", buffer);
    O->namadokter = strdup(buffer);    
}

void TulisOPNAME(OPNAME *O)
{
    printf("\n\nNomor Kamar: %d\n", O->no_kamar);
    printf("Nama : %s\n", O->nama);
    printf("Penyakit penderita : %s \n", O->penyakit);
    printf("Nama Dokter : %s\n", O->namadokter);
}

// void FreeOPNAME(OPNAME *O)
// {
//     free(O->namadokter); // Free dynamically allocated memory
// }