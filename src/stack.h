#ifndef __STACK_H__
#define __STACK_H__

#include "graph.h"

typedef struct _Node
{
    Vertex *vertex;
    struct _Node *next;
} Node;

typedef struct _Stack
{
    int size;
    Node *first;
} Stack;

void stackInit(Stack *stack);
void spush(Stack *stack, Vertex *vertex);
Vertex *spop(Stack *stack);
Vertex *stop(Stack *stack);
void freeStack(Stack *stack);

#endif
