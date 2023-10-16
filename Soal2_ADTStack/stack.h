#ifndef STACK_H
#define STACK_H

typedef struct {
    int* data;
    int top;
    int size;
} Stack;

void InitializeStack(Stack* stack, int size);
int IsEmpty(Stack* stack);
int IsFull(Stack* stack);
void Push(Stack* stack, int value);
void Pop(Stack* stack);
void CleanUp(Stack* stack);
void PrintStack(Stack* stack);

#endif
