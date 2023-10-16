#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack* stack, int size) {
    stack->data = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
}

int IsEmpty(Stack* stack) {
    return stack->top == -1;
}

int IsFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

void Push(Stack* stack, int value) {
    if (!IsFull(stack)) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

void Pop(Stack* stack) {
    if (!IsEmpty(stack)) {
        stack->top--;
    }
}

void CleanUp(Stack *stack) {
    free(stack->data);
    stack->top = -1;
    stack->size = 0;
}