#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int main() {
    int size;
    printf("Stack Size : ");
    scanf("%d", &size);

    Stack stack;
    InitializeStack(&stack, size);

    printf("Push Stack Value:\n");

    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        Push(&stack, value);
    }

    printf("\nStack Before Processing : ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }

    printf("\nTOP = %d", stack.data[stack.top]);

    if (IsFull(&stack)) {
        printf("\nStatus : Full");
    } else {
        printf("\nStatus : Not Full");
    }

    // Stack After Processing masih perlu perbaikan

    printf("\n---------------------------");

    int index = 0;

    while (index <= stack.top) {
        if (stack.data[index] % 2 == 1) {
            Pop(&stack);
        } else {
            index++;
        }
    }

    printf("\nStack After Processing : ");
   // Buat stack sementara untuk menyimpan elemen yang akan dipertahankan
    Stack tempStack;
    InitializeStack(&tempStack, size);

    for (int i = 0; i <= stack.top; i++) {
        if (stack.data[i] % 2 == 0) {
            // Jika elemen adalah bilangan genap, salin ke stack sementara
            Push(&tempStack, stack.data[i]);
        }
    }

    // Bersihkan stack asli
    while (!IsEmpty(&stack)) {
        Pop(&stack);
    }

    // Salin kembali elemen-elemen yang akan dipertahankan ke stack asli
    while (!IsEmpty(&tempStack)) {
        int value = tempStack.data[tempStack.top];
        Push(&stack, value);
        Pop(&tempStack);
    }

    // Hapus stack sementara
    CleanUp(&tempStack);

    // Sekarang Anda dapat mencetak stack setelah pemrosesan
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }

    printf("\nTOP = %d", stack.data[stack.top]);

    if (IsFull(&stack)) {
        printf("\nStatus : Full\n\n");
    } else {
        printf("\nStatus : Not Full & Not Empty\n\n");
    }

    return 0;
}